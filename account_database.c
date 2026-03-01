#include "account_database.h"

account_databse_header db_header;
FILE *db_file_ptr;
account_entry_t account_entry;

db_operation_status load_databse()
{
    db_operation_status ret_status = DB_OPERATION_SUCCESS;
    size_t write_count = 0;
    db_customer_t temp_load[MAX_ALLOWED_ACCOUNT];

    if((db_file_ptr = fopen(DB_NAME, "rb")) == NULL)
    {
        if((db_file_ptr = fopen(DB_NAME, "wb")) == NULL)
        {
            ret_status = DB_OPERATION_FAILED;
        }
        else
        {
            db_header.account_count = 0;
            db_header.db_signature = DB_SIGNATURE;
            if(fwrite(&db_header, sizeof(db_header), 1, db_file_ptr) != 1)
            {
                ret_status = DB_OPERATION_FAILED;
            }
        }
    }
    else
    {
        if(fread(&db_header, sizeof(db_header), 1, db_file_ptr) != 1)
        {
            ret_status = DB_OPERATION_FAILED;
        }
        else if (db_header.db_signature != DB_SIGNATURE)
        {
            ret_status = DB_OPERATION_FAILED;
        }
    }

    // load db onto account entry
    if((ret_status & DB_FAIL_MASK) != DB_OPERATION_FAILED)
    {
        account_entry.count = db_header.account_count;

        if((account_entry.entry = (customer_t *)calloc(MAX_ALLOWED_ACCOUNT, sizeof(customer_t))) == NULL)
        {
            ret_status = DB_OPERATION_FAILED;
        }
        else
        {
            size_t temp = fread(temp_load, sizeof(db_customer_t), account_entry.count, db_file_ptr);
            if( temp != account_entry.count)
            {
                ret_status = DB_OPERATION_FAILED;
            }
            else
            {
                for(uint32_t i = 0; i < account_entry.count; i++)
                {
                    strncpy(account_entry.entry[i].first_name, temp_load[i].first_name, CHAR_FIELD_LENGTH);
                    strncpy(account_entry.entry[i].last_name, temp_load[i].last_name, CHAR_FIELD_LENGTH);
                    strncpy(account_entry.entry[i].father_name, temp_load[i].father_name, CHAR_FIELD_LENGTH);
                    account_entry.entry[i].age = temp_load[i].age;
                    account_entry.entry[i].cbalance = temp_load[i].cbalance;
                    account_entry.entry[i].aadhar = temp_load[i].aadhar;
                    strncpy(account_entry.entry[i].DOB, temp_load[i].DOB, 11);
                    strncpy(account_entry.entry[i].place, temp_load[i].place, CHAR_FIELD_LENGTH);
                }
            }
        }
    }

    fclose(db_file_ptr);

    return ret_status;
}

db_operation_status save_databse()
{
    db_operation_status ret_status = DB_OPERATION_SUCCESS;
    db_customer_t temp_load[MAX_ALLOWED_ACCOUNT];

    if((db_file_ptr = fopen(DB_NAME, "wb")) == NULL)
    {
        ret_status = DB_OPERATION_FAILED;
    }
    else
    {
        db_header.account_count = account_entry.count;

        if(fwrite(&db_header, sizeof(db_header), 1, db_file_ptr) == 1)
        {
            for(uint32_t i = 0; i < account_entry.count; i++)
            {
                strncpy(temp_load[i].first_name, account_entry.entry[i].first_name, CHAR_FIELD_LENGTH);
                strncpy(temp_load[i].last_name, account_entry.entry[i].last_name, CHAR_FIELD_LENGTH);
                strncpy(temp_load[i].father_name, account_entry.entry[i].father_name, CHAR_FIELD_LENGTH);
                temp_load[i].age = account_entry.entry[i].age;
                temp_load[i].cbalance = account_entry.entry[i].cbalance;
                temp_load[i].aadhar = account_entry.entry[i].aadhar;
                strncpy(temp_load[i].DOB, account_entry.entry[i].DOB, 11);
                strncpy(temp_load[i].place, account_entry.entry[i].place, CHAR_FIELD_LENGTH);
            }
            if(fwrite(temp_load, sizeof(db_customer_t), account_entry.count, db_file_ptr) != account_entry.count)
            {
                ret_status = DB_OPERATION_FAILED;
            }
        }
        else
        {
            ret_status = DB_OPERATION_FAILED;
        }
    }
    free(account_entry.entry);
    fclose(db_file_ptr);
}