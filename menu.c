#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "menu.h"



main_menu_opt_t main_menu()
{
    uint32_t choice;
    main_menu_opt_t ret_status = INVALID_MENU;
    
    system("clear");

    printf("+======================================+\n");
    printf("+               B - M - S              +\n");
    printf("+======================================+\n");
    printf("|       1 : Create account             |\n");
    printf("+--------------------------------------+\n");
    printf("|       2 : Deposit amount             |\n");
    printf("+--------------------------------------+\n");
    printf("|       3 : Withdraw amount            |\n");
    printf("+--------------------------------------+\n");
    printf("|       4 : Account Details            |\n");
    printf("+--------------------------------------+\n");
    printf("|      99 : Save and exit              |\n");
    printf("+======================================+\n\n");

    printf (">>> ");
        

    scanf ("%u",&choice);
        
    switch (choice)
    {
    case 1: 
        ret_status = CREATE_MENU;
        break;
    case 2: 
        ret_status = DEPOSIT_MENU;
        break;
    case 3: 
        ret_status = WITHDRAW_MENU;
        break;
    case 4: 
        ret_status = ACCOUNT_DETAILS_MENU;
        break;
    case 99:
        ret_status = SAVE_AD_EXIT_MENU;
        break;
    default : 
    }
    system("clear");
    return ret_status;
}

void deposit_menu(customer_t *customer_data)   // function definition for depositing
{
    printf("+---------------------------------------+\n");
    printf("|                DEPOSIT                |\n");
    printf("+---------------------------------------+\n");
    printf ("Enter Aadhar number : ");
    scanf ("%ld",&(customer_data->aadhar));

    printf ("Enter the amount to deposit : ");
    scanf ("%f",&(customer_data->cbalance));
}

void create_menu(customer_t *customer_data) // function definition to create account
{
    printf("+---------------------------------------+\n");
    printf("|            CREATE ACCOUNT             |\n");
    printf("+---------------------------------------+\n");

    printf ("\nEnter your first name : ");
    scanf ("%s",customer_data->first_name);

    printf ("\nEnter your last name : ");
    scanf ("%s",customer_data->last_name);

    printf ("Father name     : ");
    scanf ("%s",customer_data->father_name);

    printf ("Age             : ");
    scanf ("%d",&customer_data->age);

    printf ("Aadhar          : ");
    scanf ("%ld",&customer_data->aadhar);

    printf ("Date of Birth   : ");
    scanf ("%s",customer_data->DOB);

    printf ("Place           : ");
    scanf ("%s",customer_data->place);
}

void withdraw_menu(customer_t *customer_data)   // function definition to withdraw
{
    printf("+---------------------------------------+\n");
    printf("|                WITHDRAW               |\n");
    printf("+---------------------------------------+\n");

    printf ("Enter Aadhar number : ");
    scanf ("%ld",&(customer_data->aadhar));

    printf ("Enter the amount to withdraw : ");
    scanf ("%f",&(customer_data->cbalance));
}

void account_deatils_menu(customer_t *customer_data)
{
    printf("+---------------------------------------+\n");
    printf("|             ACCOUNT DETAILS           |\n");
    printf("+---------------------------------------+\n");
}

void save_and_exit_menu(customer_t *customer_data)
{
    printf("+---------------------------------------+\n");
    printf("|                SAVING...              |\n");
    printf("+---------------------------------------+\n");
}

