#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void order_func(int ,char *,int ,int );

int main()
{
    //.........................reading items from menu........................
    char menu_line[100];
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

    char your_order[50];                    //coffee choice
    int slno=0,quantity=0,price;            //serial number,quantity,price
    int choice;                             // your choice
while(1)
{
    printf("Choose your order : \n");
    scanf("%d",&choice);
    if(choice>0 && choice<9)
    {
        slno = slno + 1;                       // increment the serial number
        printf("\nhow many : ");
        scanf("%d",&quantity);
    }
    else
    {
        printf("your order : \n");
    }
    switch(choice)
    {
        case 1: order_func(slno,"CAPPUCCINO",quantity,100);
                break;
        case 2: order_func(slno,"LATTE",quantity,150);
                break;
        case 3: order_func(slno,"CORTADO",quantity,70);
                break;
        case 4: order_func(slno,"ESPRESSO",quantity,80);
                break;
        case 5: order_func(slno,"AMERICANO",quantity,75);
                break;
        case 6: order_func(slno,"BLACK",quantity,50);
                break;
        case 7: order_func(slno,"MOCHA",quantity,130);
                break;
        case 8: order_func(slno,"IRISH",quantity,85);
                break;
        default: printf("invalid choice \n");
                exit(0);
    }
}
    return 0;
}

void order_func(int slno,char item[30],int quantity,int price)
{
    int tax = 0.05*price*quantity;
    int subtotal=price*quantity;
    time_t time1;
    time(&time1);
    printf("\n....................THE BREWERY.......................\n");
    printf("\n");
    printf("\t\t   \t %s",ctime(&time1));
    printf("......................................................\n");
    printf("order.No\titem\t\tquantity\tprice\n");
    printf("......................................................\n");
    printf("%d\t\t%s\t   %d\t\t%d\n",slno,item,quantity,price);
    printf(".......................................................\n");
    printf("\t\t\t subtotal amount = %d\n",(price*quantity));
    printf("\t\t\t\t    %5 TAX = %d \n",tax);
    printf("\t\t\t    Total amount = %d\n",(tax+subtotal));
}
