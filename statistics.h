struct Stats{
    int n; /*Sample size*/
    double average; /*mean*/
    double diff_squared; /*square of total differences*/
    double variance; /*variance*/
};

void initialize_stat(struct Stats *stat); 
void putElement(struct Stats *stat, int element); 


