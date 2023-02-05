#include <stdio.h>

void create();    // function to create account
void deposit();   // function to deposit
int data(long int, float); // function to search data and compare
void withdraw();  // function to withdraw
int wdata(long int, float); // function to search data and compare
void accountdetails();  //function to know the account details
int adata();   //function to compare aadhar details and display acc info

//customer details
struct customer{
    char name[20];
    char fname[15];   //father name
    int age;
    float cbalance;   // current balance
    long int aadhar;
    char DOB[12];     // date of birth
    char place[15];
    };

static struct customer cus[150];  // array of structure globally declared
static int count=0;
static int n=0;
static int *ptr[10];

    int main()
    {
        int choice;
        while (1)
         {
            printf("\n1.Create account\n2.Deposit amount\n3.Withdraw amount\n4.Account Details\n");
            printf ("Enter your choice : ");
            scanf ("%d",&choice);

            switch (choice)
            {
                case 1:create();
                       break;
                case 2:deposit();
                       break;
                case 3:withdraw();
                       break;
                case 4:accountdetails();
                       break;
                default : printf ("enter correct option\n");
            }
        }
    }


    void create() // function definition to create account
    {
        int x;
        static int i=0;   // terminator
        do{
            printf ("\nEnter your name : ");
            scanf ("%s",cus[i].name);
            printf ("Father name     : ");
            scanf ("%s",cus[i].fname);
            printf ("Age             : ");
            scanf ("%d",&cus[i].age);
            printf ("Aadhar          : ");
            scanf ("%ld",&cus[i].aadhar);
            printf ("Date of Birth   : ");
            scanf ("%s",cus[i].DOB);
            printf ("Place           : ");
            scanf ("%s",cus[i].place);
            printf ("--- Thank You ---\n");
            ptr[i]=&cus[i].aadhar;

            i++;
            count++;

            printf ("To continue press 1 or press 0 : ");
            scanf ("%d",&x);
          }while (x==1);
    }


    void deposit()   // function definition for depositing
    {
        long int ad;
        float amt;

        if (count == 0)
        {
            printf ("\nNo Account \n");
            printf ("Create an Account \n");
            printf ("--- Thank You ---\n\n");
        }
        else
        {
            printf ("Enter Aadhar number : ");
            scanf ("%ld",&ad);

            printf ("Enter the amount to deposit : ");
            scanf ("%f",&amt);

            data(ad,amt);
        }
     }


    int data(long int ad, float amt)   // function definition to compare details and deposit
     {
       int i;
       for(i=0; i<10; i++)
       {
           if (cus[i].aadhar == ad)
           {
               cus[i].cbalance = cus[i].cbalance + amt;
               printf ("Current Balance : %f\n",cus[i].cbalance);
               printf ("--- Thank You ---\n");
               break;
           }
       }
     }


     void withdraw()   // function definition to withdraw
    {
        long int ad;
        float amt;

        if (count == 0)
        {
            printf ("\nNo Account \n");
            printf ("Create an Account \n");
            printf ("--- Thank You ---\n\n");
        }
        else
        {

            printf ("Enter Aadhar number : ");
            scanf ("%ld",&ad);

            printf ("Enter the amount to withdraw : ");
            scanf ("%f",&amt);

            wdata(ad,amt);
        }
    }


    int wdata(long int ad, float amt)  // function definition to compare details and withdraw
     {
       int i;
       for(i=0; i<10; i++)
       {
           if (cus[i].aadhar == ad)
           {
               if (cus[i].cbalance < amt)
               {
                   printf ("Insufficient Amount\n");
                   printf ("Current Balance = %f\n",cus[i].cbalance);
                   printf ("--- Thank You ---\n\n");
                   break;
               }
               else
               {
                   cus[i].cbalance = cus[i].cbalance - amt;

                   printf ("Current Balance = %f\n", cus[i].cbalance);
                   printf ("--- Thank You ---\n");
                   break;
               }
            }
       }
    }


    void accountdetails()   // function for displaying account details
    {
        long int ad;

        for (int i=0; i<=n; i++)
        {
            if (count == 0)
                {
                    printf ("No Account \n");
                    printf ("Create an Account \n");
                    printf ("--- Thank You ---\n");
                }
            else
               {
                    printf ("Enter Aadhar Number : ");
                    scanf ("%ld",&ad);

                    adata(ad);
               }
        }
    }


    int adata(long int ad) // function to compare aadhar using pointers and display acc details
    {
        for (int i=0;i<10; i++)
        {
            if (*ptr[i] == ad)   // comparing aadhar number with pointer array
            {
                    printf ("\n---Account Details---\n");
                    printf ("Account Name    : %s \n",cus[i].name);
                    printf ("Father Name     : %s \n",cus[i].fname);
                    printf ("Age             : %d \n",cus[i].age);
                    printf ("Aadhar          : %ld \n",cus[i].aadhar);
                    printf ("Date Of Birth   : %s \n",cus[i].DOB);
                    printf ("Place           : %s \n",cus[i].place);
                    printf ("Current Balance : %f \n",cus[i].cbalance);
                    printf ("--- Thank You ---\n");
                    break;
            }
        }
    }


