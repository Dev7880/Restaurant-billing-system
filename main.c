#include<stdio.h>
#include<stdlib.h>
int again;
int total=0;
float gst,cgst,sgst;
int bfrate[7][2]={  {0,35},
                    {1,99},
                    {2,30},
                    {3,20},
                    {4,45},
                    {5,45},
                    {6,40}
                };
int lunchrate[7][2]={{0,50},
                {1,55},
                {2,30},
                {3,6},
                {4,30},
                {5,45},
                {6,99}};
int dinner_rate[7][2]={{0,35},
                {1,50},
                {2,60},
                {3,10},
                {4,30},
                {5,55},
                {6,20}};
int purchased[][3]={{0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0}
                        };
int temp[][3]={{0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0},
                        {0,0}
                        };
void bfast(char bfmenu[][100]);
void lunch( char lunchmenu[][100]);
void dinner(char dinnermenu[][100]);
void main_menu();
void display();
void lunch_menucard();
void dinner_menu();
void display_bf_bill(char bfmenu[][100]);
void display_lunch_bill(char lunchmenu[][100]);
void display_dinner_bill(char dinnermenu[][100]);
void display_bfmenu();
void repeatbf(char bfmenu[][100]);
void repeatlunch(char lunchmenu[][100]);
void repeatdinner(char dinnermenu[][100]);
void display_total_words();
void main()
{
    char bfmenu[][100]={"French Fries","Pizza","Sandwitch","Tea","Cold Coffee","Hot Chocolate","Momo"};
    char lunchmenu[][100]={"Mix Veg","Kadai Paneer","Paratha","Roti","Rice","Chhola","Special Thali"};
    char dinnermenu[][100]={"Fried rice","Egg Curry","Chicken Noodles","Tandoori","Rice","Paneer Tokka","Gulab Jamun"};
    char choice;
    do
    {
        enter:
        display();
        printf("Enter your choice here : ");
        scanf("%c", &choice);
        getchar();
        switch(choice)
        {
            case 'A':
            case 'a':printf("\nBreakfast\n");
                    bfast(bfmenu);
                    break;
            case 'B':
             case 'b':printf("\nLunch\n");
                    lunch(lunchmenu);
                    break;
             case 'C':
            case 'c':printf("\nDinner\n");
                    dinner(dinnermenu);
                    break;
           default:printf("\nWrong choice  Please enter the valid choice!!\n");
                    goto enter;
        }
    }while(choice!='d');
}
void display()
{
    printf("                Welcome to BIG BUNS RESTAURANT          \n ");
    printf("             +============================+          \n\n");
    printf("  && Please select the meal && \n\n");
    printf("\t\t      [A] Breakfast\n");
    printf("\t\t      [B] Lunch\n");
    printf("\t\t      [C] Dinner\n");
}
void display_bfmenu()
{
    printf("                Welcome to BIG BUNS RESTAURANT          \n ");
    printf("             +============================+          \n\n");
    printf("                  $  Breakfast Menu  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] French Fries - Rs 35.00\n");
    printf("\t\t   [1] Pizza - Rs 99.00\n");
    printf("\t\t   [2] Sandwitch - Rs 30.00\n");
    printf("\t\t   [3] Tea - Rs 20.00\n");
    printf("\t\t   [4] Cold Coffee - Rs 45.00\n");
    printf("\t\t   [5] Hot Chocolate - Rs 45.00\n");
    printf("\t\t   [6] Momo - Rs 40.00\n");
}
void bfast(char bfmenu[][100]) //Breakfast Menu Screen
{
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    display_bfmenu();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    printf("Total is %d\n\n",total);
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
        purchased[code][1]= quantity*bfrate[code][1]; purchased[code][1]+ (quantity*bfrate[code][1]);
        total+=purchased[code][ 1];
        printf("Total is %d\n\n",total);
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        bfast(bfmenu);
    }
    repeatbf(bfmenu);
}
void repeatbf(char bfmenu[][100])
{
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    scanf("%d",&again);
    if (again == 1)
            bfast(bfmenu);
    else if (again == 2 )
    {
        display_bf_bill(bfmenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatbf(bfmenu);
    }
}
void display_bf_bill(char bfmenu[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      BIG BUNS RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t%s\t\t",bfmenu[i]);
            printf("%d\n",purchased[i][1]); purchased[i][1];
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n",total);
    display_total_words();
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~+          \n\n");

}
void display_lunch_bill(char lunchmenu[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      BIG BUNS RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",lunchmenu[i]);
            printf("%d\n",purchased[i][1]);
        }
    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n",total);
    display_total_words();
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~+          \n\n");
}
void display_dinner_bill(char dinnermenu[][100])
{
    int i;
    printf("  +~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      BIG BUNS RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t\t ITEMS\t\t\tPrice(in Rs.)\n");
    for(i=0;i<7;i++)
    {
        if(purchased[i][1]!=0)
        {
            printf("\t\t %s \t\t",dinnermenu[i]);
            printf("%d\n",purchased[i][1]);
        }

    }
    printf("\t\tGST=Rs.%0.2f\n",gst);
    printf("\t\tC-GST=Rs.%0.2f\n",cgst);
    printf("\t\tS-GST=Rs.%0.2f\n",sgst);
    printf("\t\tTotal=Rs.%d\n\n",total);
    display_total_words();
    printf("\n\n  +~~~~~~~~~~~~~~~~~~~~+          \n\n");
}
void lunch(char lunchmenu[][100]) // Lunch Screen Menu
{
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    lunch_menucard();
    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
       // purchased[code][1]= purchased[code][1]+(quantity*lunchrate[code][1]);
        purchased[code][1]= quantity*lunchrate[code][1];
         total+=purchased[code][ 1];
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
         lunch(lunchmenu);
    }
    repeatlunch(lunchmenu);
}
void dinner(char dinnermenu[][100]) // Dinner Menu Screen
{
    int choice = 0; //local variables
    int quantity = 0;
    int again = 0,amt=0;
    int code,i;
    dinner_menu();

    printf("\nEnter the code:: ");
    scanf("%d", &code);
    getchar();
    if(code>=0&&code<=6)
    {
        printf("\nEnter the quantity::");
        scanf("%d",&quantity);
       // purchased[code][1]= purchased[code][1]+(quantity*dinner_rate[code][1]);
        purchased[code][1]= quantity*dinner_rate[code][1];
        total+=purchased[code][1];
        gst=total*0.12;
        cgst=gst/2;
        sgst=cgst;
    }
    else
    {
        printf("\nInvalid code entered, Please enter the code again!!!!\n\n");
        dinner(dinnermenu);
    }
    repeatdinner(dinnermenu);
}
void lunch_menucard()
{
    printf("                Welcome to BIG BUNS Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("                   $  Lunch Menu  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] Mix Veg - Rs 50.00\n");
    printf("\t\t   [1] Kadai Paneer - Rs 55.00\n");
    printf("\t\t   [2] Paratha - Rs 30.00\n");
    printf("\t\t   [3] Roti - Rs 6.00\n");
    printf("\t\t   [4] Rice - Rs 30.00\n");
    printf("\t\t   [5] Chhola - Rs 45.00\n");
    printf("\t\t   [6] Special Thali - Rs 99.00\n");
    printf("Enter your choice here : ");
}
void dinner_menu()
{
    printf("                Welcome to BIG BUNS Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("                    $  Dinner Menu  $ \n\n");
    printf("  && Please select the food that you would like to purchase. && \n\n");
    printf("\t\t   [0] Fried Rice - Rs 35.00\n");
    printf("\t\t   [1] Egg Curry - Rs 50\n");
    printf("\t\t   [2] Chicken Noodles - Rs 60.00\n");
    printf("\t\t   [3] Tandoori - Rs 10.00\n");
    printf("\t\t   [4] Rice - Rs 30.00\n");
    printf("\t\t   [5] Paneer Tikka - Rs 55.00\n");
    printf("\t\t   [6] Gulab Jamun - Rs 20.00\n");
}
void repeatlunch(char lunchmenu[][100])
{
    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    scanf("%d",&again);
    if (again == 1)
            lunch(lunchmenu);
    else if (again == 2 )
    {
        display_lunch_bill(lunchmenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatlunch(lunchmenu);
    }
}
void repeatdinner(char dinnermenu[][100])
{

    printf("\nWould you like to buy anything else?\n[1] Yes , [2] No : "); // Allows user to choose whether to check-out or buy anything else.
    scanf("%d",&again);
    if (again == 1)
    {
        dinner(dinnermenu);
    }
    else if (again == 2 )
    {
        display_dinner_bill(dinnermenu);
        exit(0);
    }
    else
    {
        printf("\n\n\t\tSorry Invalid Decision Entered\n");
        repeatdinner(dinnermenu);
    }
}
void display_total_words()
{
    int num=0,digits=0,temp=0;
    while(total != 0)
    {
        num=(num * 10)+(total % 10);
        total/= 10;
        digits++;
    }
    printf("\nNo of digits::%d\n",digits);
    while(num!= 0)
    {
        temp++;
        switch(num%10)
        {
            case 0:
                printf("Zero ");
                break;
            case 1:
                printf("One ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
        }
        num = num / 10;
    }
    if(num==0&&digits!=temp)
        printf(" Zero ");
    return;
}