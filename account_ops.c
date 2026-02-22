#include "account_ops.h"
#include <inttypes.h>
#include <stdio.h>

int32_t search_by_aadhar(customer_t *customer_data)
{
    for (uint32_t i = 0; i < account_entry.count; i++)
    {
        if(account_entry.entry[i].aadhar == customer_data->aadhar)
        {
            return i;
        }
    }

    return -1;
}

void create_account(customer_t *customer_data)
{
    if (search_by_aadhar(customer_data) == -1)
    {
        if(account_entry.count < MAX_ALLOWED_ACCOUNT)
        {
            strncpy(account_entry.entry[account_entry.count].first_name, customer_data->first_name, CHAR_FIELD_LENGTH);
            strncpy(account_entry.entry[account_entry.count].last_name, customer_data->last_name, CHAR_FIELD_LENGTH);
            strncpy(account_entry.entry[account_entry.count].father_name, customer_data->father_name, CHAR_FIELD_LENGTH);
            account_entry.entry[account_entry.count].age = customer_data->age;
            account_entry.entry[account_entry.count].cbalance = customer_data->cbalance;
            account_entry.entry[account_entry.count].aadhar = customer_data->aadhar;
            strncpy(account_entry.entry[account_entry.count].DOB, customer_data->DOB, 11);
            strncpy(account_entry.entry[account_entry.count].place, customer_data->place, CHAR_FIELD_LENGTH);
            account_entry.count++;
            printf("Created User %d\n", account_entry.count);
        }
        else
        {
            printf("MAX USER EXISTS\n");
        }
    }
    else
    {
        printf("Entry Alreday exists\n");
    }
}

void deposit_amount(customer_t *customer_data)
{

}

void withdraw_amount(customer_t *customer_data)
{

}

void account_details(customer_t *customer_data)
{
    int32_t account_index = -1;
    if ((account_index = search_by_aadhar(customer_data)) != -1)
    {
        printf("FIRST NAME  : %s\n",account_entry.entry[account_index].first_name);
        printf("LAST NAME   : %s\n",account_entry.entry[account_index].last_name);
        printf("FATHER NAME : %s\n",account_entry.entry[account_index].father_name);
        printf("AGE         : %d\n",account_entry.entry[account_index].age);
        printf("BALANCE     : %f\n",account_entry.entry[account_index].cbalance);
        printf("AADHAR CARD : %" PRIu64 "\n",account_entry.entry[account_index].aadhar);
        printf("DOB         : %s\n",account_entry.entry[account_index].DOB);
        printf("PPLACE      : %s\n",account_entry.entry[account_index].place);
    }
    else
    {
        printf("Entry does not exists\n");
    }
}


