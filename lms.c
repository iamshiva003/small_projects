#include <stdio.h>
void adsignup();
void adsignin();
void display();
void create();
void bcreate();
void bgive();
void breturn();
void stock();
static int count=0;

struct admin
{
    char name[25];
    char dob[15];       //date of birth
    char bloodg[5];    // blood group
    char place[100];
    int id;
};

struct student
{
    char name[25];
    int roll;
    char sem[10];      //semester
    char bloodg[5];   // blood group
    char dob[15];

};

struct book
{
    char bname[25];
    int bcode;
    int qty;
};

struct admin ad[3];
struct student stu[50];
struct book bk[100];



void main()
{
    int ch;
    while(1)
    {
        printf ("Admin Login / signup \n");
        printf ("1.Signup \n2.Signin \n");
        printf ("Enter your choice \n");
        scanf ("%d", &ch);

        switch (ch)
        {
           case 1:adsignup();
               break;
           case 2:adsignin();
               break;
        }
    }

}

void adsignup()
{
    static int i=0;
    int x;
    do {
        printf ("Enter your name : ");
        scanf ("%s", ad[i].name);
        printf ("Enter Date of Birth : ");
        scanf ("%s", ad[i].dob);
        printf ("Enter Blood group : ");
        scanf ("%s", ad[i].bloodg);
        printf ("Enter Place : ");
        scanf ("%s", ad[i].place);
        printf ("Enter ID : ");
        scanf ("%d",&ad[i].id);

        i++;
        printf ("To continue press 1 or press 0 to exit : ");
        scanf ("%d",&x);

    }while (x==1);
}

void adsignin()
{
    int temp;
    printf ("Enter ID : ");
    scanf ("%d",&temp);

    for (int i=0; i<=2; i++)
    {
        if (temp == ad[i].id)
        {
            display ();

        }
    }
}

void display ()
{
    int ch;
    printf ("1.Create Student details \n");
    printf ("2.Book details \n");
    printf ("3.Give a book \n");     // withdraw
    printf ("4.Return a book \n");
    printf ("5.Stock Details \n");
    printf ("6.Logout\n");

    printf ("Enter your choice : ");
    scanf ("%d",&ch);

    switch (ch)
    {
        case 1:create();
                break;
        case 2:bcreate();
                break;
        case 3:bgive();
                break;
        case 4:breturn();
                break;
        case 5:stock();
                break;
        case 6:main();  //back to main function i.e logout of the control
        default: printf ("Enter the correct choice \n");
                break;
    }
}

void create()
{
    static int i=0;
    int x;
    do {
        printf ("Enter student name : ");
        scanf ("%s",stu[i].name);
        printf ("Enter Roll number  : ");
        scanf ("%d",&stu[i].roll);
        printf ("Enter Semester     : ");
        scanf ("%s",stu[i].sem);
        printf ("Enter Blood Group  : ");
        scanf ("%s",stu[i].bloodg);
        printf ("Enter Date of birth: ");
        scanf ("%s",stu[i].dob);

        i++;
        printf("%d",i);
        printf ("To continue press 1 or press 0 to exit : ");
        scanf ("%d",&x);
    }while (x==1);
    display();
}

void bcreate()
{
    static int i=0;
    int x;
    do
    {
        printf ("Enter book name : ");
        scanf ("%s",bk[i].bname);
        printf ("Enter book code : ");
        scanf ("%d",&bk[i].bcode);
        printf ("Enter quantity  :");
        scanf ("%d",&bk[i].qty);

        i++;
        count++;

        printf ("To continue press 1 or press 0 to exit : ");
        scanf ("%d",&x);
    }while(x==1);
    display();
}

void bgive()
{
    int rtemp,ctemp;
    int i,j;

    printf ("Enter roll.no  : ");
    scanf ("%d",&rtemp);

   for (i=0; i<50; i++)
   {
       if (rtemp == stu[i].roll)
       {
           printf ("Enter book code:");
           scanf ("%d",&ctemp);

           for (j=0;j<100;j++)
           {
               if (ctemp == bk[j].bcode)
               {
                   bk[j].qty=bk[j].qty-1;
               }
           }
       }
   }
   display();
}

void breturn()
{
    int rtemp,ctemp;
    int i,j;

    printf ("Enter roll.no : ");
    scanf ("%d",&rtemp);

   for (i=0; i<50; i++)
   {
       if (rtemp == stu[i].roll)
       {
           printf ("Enter book code:");
           scanf ("%d",&ctemp);

           for (j=0;j<100;j++)
           {
               if (ctemp == bk[j].bcode)
               {
                   bk[j].qty=bk[j].qty+1;
               }
           }
       }
    }
    display();
}

void stock()
{
    if (count == 0)
       printf ("No Stock\n");
    else
    {
        printf ("BOOK NAME \t\tBOOKCODE\tSTOCK \n");
        printf ("==================================================\n");

        for (int i=0; i<count; i++)
        {
            printf ("%s \t\t %d \t\t %d \n",bk[i].bname,bk[i].bcode,bk[i].qty);
        }
    }
    display();
}
