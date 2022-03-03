#ifndef __src_calculation_H
#define __src_calculation_H

int tax(int x);
int total_c(int y);

int tax(int x)
{
    return (0.05*x);
}


int total_c(int *item)
{
    int i,sum=0;
    for(i=0;i<10;i++)
    {
        sum=sum+item[i];
    }
    return sum;
}

#endif