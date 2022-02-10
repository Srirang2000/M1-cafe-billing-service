#ifndef __sll_billing_main_H__
#define __sll_billing_main_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<Windows.h>

struct bill
{
    int slno;
    int quantity;
    float price;
    char your_order[30];
    struct bill* link;
};


struct bill* root=NULL;

#endif