#include "src_calculation.h"


int total_c(int *item)
{
    int i,sum=0;
    for(i=0;i<10;i++)
    {
        sum=sum+item[i];
    }
    return sum;
}


