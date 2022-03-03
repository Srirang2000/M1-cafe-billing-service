#include <stdio.h>

int main()
{
    int b[10]={20,65,45,85,95,44,23,55,66,78};
    int total_amt,tax_amount;
    total_amt=total_c(b);
    tax_amount=tax(total_amt);
    printf("Total amt: %d\n", total_amt);
    printf("tax amount: %d\n",tax_amount);
}

