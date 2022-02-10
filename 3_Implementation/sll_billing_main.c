#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<Windows.h>
#include"sll_billing_main.h"
#include"sll_billing_func.h"

void order_func(int ,char *,int ,float );
void print();


void main()
{
    //.........................reading items from menu........................
    struct bill *temp;
    char menu_line[100];
    temp = (struct bill *)malloc(sizeof(struct bill *));
    FILE *the_menu=fopen("menu.txt", "r");
    if(the_menu==NULL)
    {
        perror("Couldn't open");
        exit(1);
    }
    while(fgets(menu_line,sizeof(menu_line),the_menu))
    {
        printf("%s",menu_line);
    }
    //.........................................................................
    int choice;
    int slno2=0,quantity2=0;
    while(1)
{
    printf("Choose your order : \n");
    scanf("%d",&choice);
    if(choice>0 && choice<9)
    {
        slno2 = slno2 + 1;                       // increment the serial number
        printf("\nhow many : ");
        scanf("%d",&quantity2);
    }
    else
    {
        printf("your order : \n");
    }
    switch(choice)
    {
        case 1: order_func(slno2,"CAPPUCCINO",quantity2,100.0);
                break;
        case 2: order_func(slno2,"LATTE",quantity2,150.0);
                break;
        case 3: order_func(slno2,"CORTADO",quantity2,70.0);
                break;
        case 4: order_func(slno2,"ESPRESSO",quantity2,80.0);
                break;
        case 5: order_func(slno2,"AMERICANO",quantity2,75.0);
                break;
        case 6: order_func(slno2,"BLACK",quantity2,50.0);
                break;
        case 7: order_func(slno2,"MOCHA",quantity2,130.0);
                break;
        case 8: order_func(slno2,"IRISH",quantity2,85.0);
                break;
        case 9: print();
                break;
        default: printf("invalid choice \n");
                exit(0);
    }
}
}