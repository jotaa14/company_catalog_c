/**
 * @file UserSearch.c
 * @author Hugo Martins & João Ribeiro
 * @date 10-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for search companies.
 */

#include "util.h"
#include "functions.h"
#include "files.h"
#include "comment.h"
#include "LineOfWork.h"
#include "UserSearch.h"
#include "company.h"

void search_company(Company_count *companies) {
    int search;

    do {
        puts(LINE);
        puts(MENU_SEARCH);
        puts(LINE);
        puts(SEARCH_WITH_NIF);
        puts(SEARCH_WITH_NAME);
        puts(SEARCH_WITH_LOCAL);
        puts(EXIT_MENU);
        scanf("%d", &search);

        switch (search) {
            case 0: 
                return;
            case 1:
                search_nif(companies);
                break;
            case 2:
                search_name(companies); 
                break;
            case 3:
                search_local(companies); 
                break;
            default:
                puts(ERROR_MESSAGE);
        }
    } while (search != 0);
}

int get_company_nif(Company_count *companies, int get_nif) {
    int i;
    for (i = 0; i < companies->counter; i++) {
        if (companies->companies[i].nif == get_nif) {
            return i;
        }
    }
    return -1;
}

int get_name_position(Company_count *companies, const char *get_name) {
    int i;
    for (i = 0; i < companies->counter; i++) {
        if (strcmp(companies->companies[i].name, get_name) == 0) {
            return i;
        }
    }
    return -1;
}

int get_local_position(Company_count *companies, const char *get_local) {
    int i;
    for (i = 0; i < companies->counter; i++) {
        if (strcmp(companies->companies[i].address.municipality, get_local) == 0) {
            return i;
        }
    }
    return -1;
}

void search_nif(Company_count *companies) {
    int nif;
    int position;
    puts(MSG_GET_NIF);
    scanf("%d", &nif);

    cleanInputBuffer();

    position = get_company_nif(companies, nif);
    if (position != -1) {
        if (strcmp(companies->companies[position].line_of_works.status, "Active") == 0){
            if (strcmp(companies->companies[position].status, "Active") == 0) {
                puts(COMPANY_FOUND);
                print_company(companies->companies[position]);
                if (list_company_comments_user > 0){
                puts(COMMENT_DISPLAY);
                companies=list_company_comments_user(companies, position);
                } else{
                    puts(ERROR_LIST_OF_COMMENTS_EMPTY);
                }
            } else {
                puts(ERROR_COMPANY_DO_NOT_EXIST);
            }
        } else {
            puts(ERROR_COMPANY_DO_NOT_EXIST);
        }
        
    } else {
        puts(ERROR_COMPANY_DO_NOT_EXIST);
    }
}

void search_name(Company_count *companies) {
    char name[MAX_NAME_COMPANY];
    int position;
    puts(MSG_GET_COMPANY_NAME);
    scanf("%s", name);

    cleanInputBuffer();

    position = get_name_position(companies, name);
    if (position != -1) {
        if (strcmp(companies->companies[position].line_of_works.status, "Active") == 0){
            if (strcmp(companies->companies[position].status, "Active") == 0) {
                puts(COMPANY_FOUND);
                print_company(companies->companies[position]);
                puts(COMMENT_DISPLAY);
                companies=list_company_comments_user(companies, position);
            } else {
                puts(ERROR_COMPANY_DO_NOT_EXIST);
            }
        } else {
            puts(ERROR_COMPANY_DO_NOT_EXIST);
        }
    } else {
        puts(ERROR_COMPANY_DO_NOT_EXIST);
    }
}

void search_local(Company_count *companies) {
    char local[MAX_MUNICIPALITY_COMPANY];
    int position;
    puts(MSG_GET_MUNICIPALITY);
    scanf("%s", local);

    cleanInputBuffer();

    position = get_local_position(companies, local);
    if (position != -1) {
        if (strcmp(companies->companies[position].line_of_works.status, "Active") == 0){
            if (strcmp(companies->companies[position].status, "Active") == 0) {
                puts(COMPANY_FOUND);
                print_company(companies->companies[position]);
                puts(COMMENT_DISPLAY);
                companies=list_company_comments_user(companies, position);
            } else {
                puts(ERROR_COMPANY_DO_NOT_EXIST);
            }
        } else {
            puts(ERROR_COMPANY_DO_NOT_EXIST);
        }
    } else {
        puts(ERROR_COMPANY_DO_NOT_EXIST);
    }
}

