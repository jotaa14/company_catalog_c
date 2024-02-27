/**
 * @file company.c
 * @author Hugo Martins & João Ribeiro
 * @date 10-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for company input.
 */

#include "util.h"
#include "functions.h"
#include "files.h"
#include "comment.h"
#include "LineOfWork.h"
#include "UserSearch.h"
#include "company.h"

int get_company_position(Company_count companies, int number) {
    int i;
    for (i = 0; i < companies.counter; i++) {
        if (companies.companies[i].number == number) {
            return i;
        }
    }
    return -1;
}

Company_count *create_company(Company_count *companies, line_of_work_list *field_of_activity_list) {

    int number = getInt(MIN_NUMBER_COMPANY, MAX_NUMBER_COMPANY, MSG_GET_NUMBER_COMPANY);

    if (get_company_position(*companies, number) != -1) {
        puts(ERROR_COMPANY_EXIST);
        return companies;
    }
    int get_nif = getInt(MIN_NIF_NUMBER, MAX_NIF_NUMBER, MSG_GET_NIF);
    
    if (get_company_nif(companies, get_nif) != -1) {
        puts(ERROR_COMPANY_NIF_EXIST);
        return companies;
    }
    
    companies->companies[companies->counter].number = number;
    
    companies->companies[companies->counter].nif = get_nif;
    readString(companies->companies[companies->counter].name, MAX_NAME_COMPANY, MSG_GET_COMPANY_NAME);
    if (get_name_position(companies, companies->companies[companies->counter].name) != -1) {
        puts(ERROR_COMPANY_NAME_EXIST);
        return companies;
    }
    readString(companies->companies[companies->counter].category, MAX_CATEGORY_COMPANY, MSG_GET_COMPANY_CATEGORY);
    readString(companies->companies[companies->counter].address.street, MAX_STREET_COMPANY, MSG_GET_STREET);
    readString(companies->companies[companies->counter].address.municipality, MAX_MUNICIPALITY_COMPANY, MSG_GET_MUNICIPALITY);
    companies->companies[companies->counter].address.zipcode.zipcode2 = getInt(MIN_ZIPCODE_NUMBER2, MAX_ZIPCODE_NUMBER2, MSG_GET_ZIPCODE2);
    
    
    strcpy(companies->companies[companies->counter].status, "Active");
    if(field_of_activity_list->counter==0){
        field_of_activity_list=insert_line_of_work(field_of_activity_list);
                int line_of_work_index = choose_line_of_work(field_of_activity_list);
    
    if (line_of_work_index == -1) {
        return companies;
    }
    companies->companies[companies->counter].line_of_works = field_of_activity_list->field_of_activity_list[line_of_work_index];
    }else{
        int line_of_work_index = choose_line_of_work(field_of_activity_list);
    
    if (line_of_work_index == -1) {
        return companies;
    }
    companies->companies[companies->counter].line_of_works = field_of_activity_list->field_of_activity_list[line_of_work_index];
    }
    
    companies[companies->counter].used_by_company++;
    
    companies->companies[companies->counter].comment_counter=0;
    
    if(companies->companies[companies->counter].comment_counter==0){
        puts(COMPANY_ADDED);
    }

    companies->counter++;
    
    return companies;
}

void print_company(Company companies) {
    puts(LINE);
    puts(COMPANY_DISPLAY);
    puts(LINE);
    printf("Company number: %d\n", companies.number);
    printf("Name:%s\n Nif:%d\n Category:%s\n Street:%s \n Municipality: %s \n Zipcode: %d-%d\n Line of work name: %s\n Status: %s\n", companies.name, companies.nif, companies.category, companies.address.street, companies.address.municipality, companies.address.zipcode.zipcode1, companies.address.zipcode.zipcode2, companies.line_of_works.name_of_activity, companies.status);
}

void list_companys(Company_count companies) {
    int i;
    if (companies.counter > 0) {
        for (i = 0; i < companies.counter; i++) {
            print_company(companies.companies[i]);
        }
    } else {
        puts(ERROR_LIST_IS_EMPTY);
    }
}

void edit_company(Company_count *companies) {
    int edit_menu;
    int number = get_company_position(*companies, getInt(MIN_NUMBER_COMPANY, MAX_NUMBER_COMPANY, MSG_GET_NUMBER_COMPANY));
    if (number == -1) {
        puts(ERROR_COMPANY_DO_NOT_EXIST);
        return;
    }
    do {
        puts(LINE);
        puts(DISPLAY_EDIT_MENU);
        puts(LINE);
        puts(EDIT_COMPANY_NIF);
        puts(EDIT_COMPANY_NAME);
        puts(EDIT_COMPANY_STREET);
        puts(EDIT_COMPANY_LOCAL);
        puts(EDIT_COMPANY_CATEGORY);
        puts(EDIT_COMPANY_POSTALCODE);
        puts(EDIT_COMPANY_STATUS);
        puts(EXIT_MENU);
        scanf("%d", &edit_menu);

        cleanInputBuffer();

        switch (edit_menu) {
            case 1:
                companies->companies[number].nif = get_nif(MSG_GET_NIF);
                break;
            case 2:
                readString(companies->companies[number].name, MAX_NAME_COMPANY, MSG_GET_COMPANY_NAME);
                break;
            case 3:
                readString(companies->companies[number].address.street, MAX_STREET_COMPANY, MSG_GET_STREET);
                break;
            case 4:
                readString(companies->companies[number].address.municipality, MAX_MUNICIPALITY_COMPANY, MSG_GET_MUNICIPALITY);
                break;
            case 5:
                readString(companies->companies[number].category, MAX_CATEGORY_COMPANY, MSG_GET_COMPANY_CATEGORY);
                break;
            case 6:
                companies->companies[companies->counter].address.zipcode.zipcode1 = getInt(MIN_ZIPCODE_NUMBER1, MAX_ZIPCODE_NUMBER1, MSG_GET_ZIPCODE1);
                companies->companies[companies->counter].address.zipcode.zipcode2 = getInt(MIN_ZIPCODE_NUMBER2, MAX_ZIPCODE_NUMBER2, MSG_GET_ZIPCODE2);
                break;
            case 7:
                Edit_company_status(companies);
                break;
            default:
                puts(ERROR_MESSAGE);
            case 0:
                break;
        }
        puts(COMPANY_EDITED);

    } while (edit_menu != 0);


}

void Edit_company_status(Company_count *companies) {
    int position = get_company_position(*companies, getInt(MIN_NUMBER_COMPANY, MAX_NUMBER_COMPANY, MSG_GET_NUMBER_COMPANY));
    char new_Status[MAX_STATS];
    if (position == -1) {
        puts(ERROR_COMPANY_DO_NOT_EXIST);
        return;
    }
    printf(MSG_CURRENT_STATS, companies->companies[position].status);
    readString(new_Status, MAX_STATS, NEW_STATS_MSG);
    strcpy(companies->companies[position].status, new_Status);

}

void clean_Data_company(Company *company) {
    company->number = 0;
    company->nif = 0;
    company->address.zipcode.zipcode1 = 0;
    company->address.zipcode.zipcode2 = 0;
    strcpy(company->name, "");
    strcpy(company->category, "");
    strcpy(company->address.municipality, "");
    strcpy(company->address.street, "");

    strcpy(company->line_of_works.name_of_activity, "");
    strcpy(company->line_of_works.status, "");
    company->line_of_works.number = 0;
}

void remove_company(Company_count *companies) {
    int position = get_company_position(*companies, getInt(MIN_NUMBER_COMPANY, MAX_NUMBER_COMPANY, MSG_GET_NUMBER_COMPANY));
    if (position == -1) {
        puts(ERROR_COMPANY_DO_NOT_EXIST);
        return;
    }
    if (company_comments(&companies->companies[position])) {
        puts(ERROR_CANT_REMOVE_COMMENTS);

        return;
    }
    
    companies->companies[position] = companies->companies[companies->counter - 1];
    
    clean_Data_company(&companies->companies[companies->counter - 1]);
    
    companies->counter--;

    companies[position].used_by_company--;

    puts(COMPANY_REMOVED);
}