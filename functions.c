/**
 * @file functions.h
 * @author Hugo Martins & João Ribeiro
 * @date 28-11-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for menu's.
 */


#include "util.h"
#include "functions.h"
#include "files.h"
#include "comment.h"
#include "LineOfWork.h"
#include "UserSearch.h"
#include "company.h"

Company_count *Menu_admin(Company_count *companies, line_of_work_list *field_of_activity_list) {
    int menu_option_admin;
    do {
        puts(LINE);
        puts(MENU_ADMIN);
        puts(LINE);

        puts(MANAGE_COMPANY_CATALOG);
        puts(CREATE_COMPANY);
        puts(EDIT_COMPANY);
        puts(REMOVE_COMPANY);

        puts(MANAGE_LINE_OF_WORK);
        puts(ADD_LINE_OF_WORK);
        puts(EDIT_LINE_OF_WORK);
        puts(REMOVE_LINE_OF_WORK);

        puts(MANAGE_COMMENTS);
        puts(HIDE_COMMENTS);
        puts(DELETE_COMMENTS);

        puts(VIEW_REPORTS_DISPLAY);
        puts(VIEW_REPORTS);
        puts("\n");
        puts(RETURN_TO_MAIN_MENU);
        scanf("%d", &menu_option_admin);

        cleanInputBuffer();
       
        switch (menu_option_admin) {
            case 0:
                break;
            case 1:
                companies=create_company(companies, field_of_activity_list); 
                break;
            case 2:
                edit_company(companies); 
                break;
            case 3:
                remove_company(companies); 
                break;
            case 4:
                insert_line_of_work(field_of_activity_list); 
                break;
            case 5:
                edit_line_of_work(field_of_activity_list); 
                break;
            case 6:
                remove_line_of_work(companies, field_of_activity_list); 
                break;
            case 7:
                hide_comment(companies);
                break;
            case 8:
                delete_comment(companies);
                break;
            case 9:
                view_reports_menu(companies, field_of_activity_list); 
                break;
            default:
                puts(ERROR_MESSAGE);
                break;

        }
    } while (menu_option_admin != 0);
    return companies;
}

Company_count *Menu_user(Company_count *companies) {
    int menu_option_user;
    
    do {
        puts(LINE);
        puts(MENU_USER);
        puts(LINE);
        puts(SEARCH_COMPANY_USER);
        puts(RATING_COMPANY_USER);
        puts(COMMENT_COMPANY_USER);
        puts(RETURN_TO_MAIN_MENU);
        scanf("%d", &menu_option_user);

        cleanInputBuffer();

        switch (menu_option_user) {
            case 0:
                break;
            case 1:
                search_company(companies); 
                break;
            case 2:
                rating_company(companies); 
                break;
            case 3:
                companies=company_comment(companies); 
                break;
            default:
                puts(ERROR_MESSAGE);
                break;

        }
    } while (menu_option_user != 0);
    return companies;
}

void rating_company(Company_count *companies) {
    list_companys(*companies);
    
    int company_number = getInt(MIN_NUMBER_COMPANY, MAX_NUMBER_COMPANY, MSG_GET_NUMBER_COMPANY);
    int position = get_company_position(*companies, company_number);
    
    if (position == -1) {
        puts(ERROR_COMPANY_DO_NOT_EXIST);
        return;
    }
    
    float rating = getFloat(0.0, 5.0, MSG_GET_RATING);
    companies->companies[position].totalRating += rating;
    companies->companies[position].rating_count++;

    
    if (companies->companies[position].rating_count > 0) {
        companies->companies[position].average_rating = companies->companies[position].totalRating / companies->companies[position].rating_count;
    }

    printf("New average rating: %.2f\n", companies->companies[position].average_rating);

}

void view_reports_menu(Company_count *companies, line_of_work_list *field_of_activity_list) {
    int reports_menu;
    
    do {
        puts(LINE);
        puts(REPORTS_MENU);
        puts(LINE);
        puts(LIST);
        puts(LIST_COMPANYS);
        puts(LIST_LINE_OF_WORK_ADMIN);
        puts(LIST_COMMENT);
        puts(EXIT_MENU);

        scanf("%d", &reports_menu);

        switch (reports_menu) {
            case 0:
                break;
            case 1:
                list_companys(*companies);
                break;
            case 2:
                list_line_of_work(*field_of_activity_list); 
                break;
            case 3:
                companies=list_company_comments(companies);
                break;
            default:
                puts(ERROR_MESSAGE);
                break;
        }

    } while (reports_menu != 0);
}
