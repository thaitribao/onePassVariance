/*Author: Bao Thai
 *Date: September 11 2017
 *Description: Main function that reads user integer input and adds 
 *             the input to a sample. The average, sum of squared difference
 *             and the variance are then computed. 
 */
#include "statistics.h"
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define BREAK_VAL -666

int main(int argc, char *argv[]){
    int i; 
    struct Stats *stat;

    stat = (struct Stats *) malloc(sizeof(struct Stats)); 
    if (stat == NULL){
        fprintf(stderr, "Malloc error"); 
        return 911; 
    }

    initialize_stat(stat); 

    while(1){
        printf("Enter next number: "); 
        scanf("%d", &i); 
        if(i == BREAK_VAL){
            break; 
        } 
        putElement(stat, i);
        printf("Sample size: %d\n", stat->n); 
        printf("Average: %.2f\n", stat->average);
        printf("Diff_Sq: %.2f\n", stat->diff_squared); 
        printf("StdDev: %.2f\n", sqrt(stat->variance)); 
    }
    return 0;
}
