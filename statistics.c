/* Author: Bao Thai 
 * Date: Sept 11 2017
 * Description: Methods to update the mean and standard deviation of a sample
 *              using "online variance" algorithm (see: Wikipedia) with 
 *              scaling to prevent sum of difference squared from getting
 *              too large (out-of-bound for IEEE-754 double). 
 */
#include "statistics.h" 

void initialize_stat(struct Stats *stat){
    stat->n = 0; 
    stat->average = 0.0; 
    stat->diff_squared = 0.0; /*need to scale this one down*/  
    stat->variance = 0; 
}

void putElement(struct Stats *stat, int element){
    double delta, delta2; /*used to calculate variance in one pass*/
    stat->n = stat->n + 1; /*update sample size*/
    delta = element - stat->average; 
    stat->average = stat->average + delta/(stat->n); /*update average*/ 
    delta2 = element - stat->average; 

    /*update sum of difference squared, with 1000 down-scale*/
    stat->diff_squared = stat->diff_squared + (delta*delta2/1000);

    /*compute variance from sum of squared difference with scaling*/ 
    if (stat->n < 2){
        stat->variance = 0; 
    } else {
        stat->variance = stat->diff_squared/((0.001)*(stat->n -1)); 
    }

}
