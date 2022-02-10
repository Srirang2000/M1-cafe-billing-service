#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void order_func(int ,char *,int ,float );
void print();

float total_amt = 0;

struct bill
{
    int slno;
    int quantity;
    float price;
    char your_order[30];
    struct bill* link;
};


struct bill* root=NULL;

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
