/**
 * @file main.c
 * @author Hugo Martins & João Ribeiro
 * @date 28-11-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief This C program allows you to access the program as admin or user.
 *
 * In admin you can create and manage a catalog of companies, 
 * create and manage a catalog of branches of activity, 
 * deactivate/activate comments made by the user, 
 * remove them and even consult reports.
 * 
 * In user you can search for the company, rate it, 
 * comment on it and consult the comments.
 */

#include "util.h"
#include "functions.h"
#include "files.h"
#include "comment.h"
#include "LineOfWork.h"
#include "UserSearch.h"
#include "company.h"
#define FILE_NAME_COMPANIES "savecompanies.bin"
#define FILE_NAME_LINE_OF_WORK "savelineofwork.bin"


int main() {
    int choice_menu;
    Company_count *companies;
    companies = NULL;
    
    if (companies == NULL){
        companies = malloc(1 * sizeof(Company_count));
    }
    
    if(companies != NULL){        
        companies->counter = 0;
        companies->companies = malloc(MAX_COMPANYS * sizeof(Company));
    }
    
    line_of_work_list *field_of_activity_list;
    field_of_activity_list = NULL;
    if (field_of_activity_list == NULL){
        field_of_activity_list = malloc(1 * sizeof(line_of_work_list));
    }
    if(field_of_activity_list->field_of_activity_list == NULL){
        field_of_activity_list->counter = 0;
        field_of_activity_list->field_of_activity_list = malloc(MAX_NUMBER_LINE_OF_WORK * sizeof(Line_of_work));
    }

    do{
        puts(LINE);
        puts(MENU);
        puts(LINE);
        puts(ADMIN);
        puts(USER);
        puts(SAVE);
        puts(LOAD);
        puts(EXIT_MENU);
        scanf("%d", &choice_menu);
        switch (choice_menu) {
            case 0:
                break;
            case 1: 
                companies=Menu_admin(companies, field_of_activity_list);
                break;
            case 2: 
                companies=Menu_user(companies, field_of_activity_list);
                break;
            case 3:
                companies = save_companies(companies,FILE_NAME_COMPANIES);
                field_of_activity_list = save_line_of_work(field_of_activity_list,FILE_NAME_LINE_OF_WORK);
                puts("Saved with success!");
                break;
            case 4:
                companies = load_companies(companies,FILE_NAME_COMPANIES);
                field_of_activity_list = load_line_of_work(field_of_activity_list,FILE_NAME_LINE_OF_WORK);
                puts("Loaded with success!");
                break;
            default: 
                puts(ERROR_MESSAGE);
                break;

        }
    }while(choice_menu != 0);
    
    
    
    free_company(companies);
    free_line_of_work(field_of_activity_list);
    return 0;
}