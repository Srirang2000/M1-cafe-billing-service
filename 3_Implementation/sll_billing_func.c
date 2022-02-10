#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <time.h>
#include"sll_billing_main.h"

total_amt;

void order_func(int slno1,char item[30],int quantity1,float price1)
{
    struct bill *temp,*temp1;
    temp=(struct bill *)malloc(sizeof(struct bill ));
    if(temp==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        temp->slno=slno1;
        strcpy(temp->your_order,item);
        temp->quantity=quantity1;
        temp->price=price1;
        temp->link=NULL;
        total_amt = total_amt + (price1*quantity1);
        if(root==NULL)
        {
            root=temp;
        }
        else
        {
            temp1=root;
            while(temp1->link!=NULL)
            {
                temp1=temp1->link;
            }
            temp1->link=temp;
        }
    }
}

void print()    //to print the values in the linked list
{
    struct bill *temp;
    temp=root;
    if(temp==NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        float tax=0.05*total_amt;
        time_t time1;
        time(&time1);
        printf("\n....................THE BREWERY.......................\n");
        printf("\n");
        printf("\t\t   \t %s",ctime(&time1));
        printf("......................................................\n");
        printf("order.No\titem\t\tquantity\tprice\n");
        printf("......................................................\n");
        while (temp!=NULL)
        {
            printf("%d\t\t%s\t      %d\t\t%.2f\n",temp->slno,temp->your_order,temp->quantity,temp->price);
            temp=temp->link;
        }
        printf(".......................................................\n");
        printf("\t\t\t subtotal amount = %.2f\n",total_amt);
        printf("\t\t\t\t    %5 TAX = %.2f \n",tax);
        printf("\t\t\t    Total amount = %.2f\n",(tax+total_amt));
    }
}
