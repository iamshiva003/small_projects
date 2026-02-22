#ifndef _MENU_H_
#define _MENU_H_
#include "account_manage.h"

typedef enum 
{
    CREATE = 0x00,
    DEPOSIT = 0x01,
    WITHDRAW = 0x02,
    ACCOUNT_DETAILS = 0x03,
    SAVE_AND_EXIT = 0x04,
    INVALID = 0xFF
} main_menu_opt_t;


main_menu_opt_t main_menu();

void deposit_menu(customer_t *customer_data);   // function definition for depositing

void create_menu(customer_t *customer_data); // function definition to create account

void withdraw_menu(customer_t *customer_data);  // function definition to withdraw

void account_deatils_menu(customer_t *customer_data);

void save_and_exit_menu();

#endif