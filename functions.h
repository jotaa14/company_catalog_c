/**
 * @file functions.h
 * @author Hugo Martins & João Ribeiro
 * @date 28-11-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for menu's, structs and Consts.
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


#define MAX_NIF_NUMBER 999999999
#define MAX_NAME_COMPANY 30
#define MAX_CATEGORY_COMPANY 15
#define MAX_STREET_COMPANY 50
#define MAX_MUNICIPALITY_COMPANY 30
#define MAX_ZIPCODE_NUMBER1 9999
#define MAX_ZIPCODE_NUMBER2 999
#define MAX_USER_NAME_SIZE 50
#define MAX_USER_EMAIL_SIZE 50
#define MAX_TITLE_SIZE 100
#define MAX_TEXT_SIZE 255
#define MAX_NAME_ACTIVITY 15
#define MAX_STATS 10
#define MAX_NUMBER_LINE_OF_WORK 10
#define MAX_COMPANYS 100
#define MAX_COMMENTS 50
#define MAX_NUMBER_COMPANY 100


#define MIN_NIF_NUMBER 100000000
#define MIN_ZIPCODE_NUMBER1 1000
#define MIN_ZIPCODE_NUMBER2 100
#define MIN_NUMBER_LINE_OF_WORK 1
#define MIN_NUMBER_COMPANY 1


#define ADMIN "(1) Admin "
#define USER  "(2) User " 
#define SAVE "(3) Save Program"
#define LOAD "(4) Load Program"
#define EXIT_MENU "(0) Exit"


#define CREATE_COMPANY "(1) Create Company"
#define EDIT_COMPANY "(2) Edit Company"
#define REMOVE_COMPANY "(3) Remove Company"
#define ADD_LINE_OF_WORK "(4) Add Line of Work"
#define EDIT_LINE_OF_WORK "(5) Edit Line of Work"
#define REMOVE_LINE_OF_WORK "(6) Remove Line of Work"
#define HIDE_COMMENTS "(7) Hide Comments"
#define DELETE_COMMENTS "(8) Delete Comments"
#define VIEW_REPORTS "(9) View Reports"

#define LIST_COMPANYS "(1) List Companys"
#define LIST_LINE_OF_WORK_ADMIN "(2) List Line Of Works"
#define LIST_COMMENT "(3) Comments about a selected company"

#define EDIT_NAME_LINE_OF_WORK "(1) Edit Line of Work name"
#define EDIT_STATUS_LINE_OF_WORK "(2) Edit Line of Work status"


#define EDIT_COMPANY_NIF "(1) Edit company NIF"
#define EDIT_COMPANY_NAME "(2) Edit company Name"
#define EDIT_COMPANY_STREET "(3) Edit company Street"
#define EDIT_COMPANY_LOCAL "(4) Edit company Local"
#define EDIT_COMPANY_CATEGORY "(5) Edit company Category"
#define EDIT_COMPANY_POSTALCODE "(6) Edit company Postal Code"
#define EDIT_COMPANY_STATUS "(7) Edit company Status"


#define SEARCH_COMPANY_USER "(1) Search company"
#define RATING_COMPANY_USER "(2) Rate company"
#define COMMENT_COMPANY_USER "(3) Comment company"
#define LIST_LINE_OF_WORK "(6) List line of work"
#define LIST_COMPANIES_CATALOG "(7) List Companies Catalog"


#define SEARCH_WITH_NIF "(1) Search with NIF"
#define SEARCH_WITH_NAME "(2) Search with Name"
#define SEARCH_WITH_LOCAL "(3) Search with Local"

#define MENU_SEE_COMMENTS "Choose the company that you want to see the comments"


#define NEW_STATS_MSG "Enter the status of the company (Active/Inactive): "

#define RETURN_TO_MAIN_MENU "(0) Return to main menu"

#define MSG_COMPANY_DELETE_COMMENTS "Choose the company you want to delete comments"
#define MSG_GET_NUMBER_LINE_OF_WORK "Enter the number of a line of work: "
#define MSG_GET_NUMBER_COMPANY "Enter the number of the company :"
#define MSG_GET_LINE_OF_WORK "Enter the name of the line of work: "
#define MSG_GET_COMPANY_NAME "Enter a company name: \n"
#define MSG_GET_NIF "Enter the company's nif: \n"
#define MSG_GET_COMPANY_CATEGORY "Enter the category in which the company is included (example: Micro, PME and Large Company):\n"
#define MSG_GET_STREET "Enter the company street: \n"
#define MSG_GET_MUNICIPALITY "Enter the company municipality: \n"
#define MSG_GET_ZIPCODE1 "Enter the first 4 digits for company's zipcode: \n"
#define MSG_GET_ZIPCODE2 "Enter the last 3 digits for company's zipcode: \n"
#define MSG_GET_RATING "Enter your rating [0-5]: "
#define MSG_CURRENT_STATS "Current Status: %s\n"

#define LINE "-----------------------------------"
#define MENU "---------------Menu----------------"
#define COMPANY_DISPLAY "----------Company display-----------"
#define LINE_OF_WORK_DISPLAY "-------Line of work display--------"
#define COMMENT_DISPLAY "-------------Comments--------------"
#define DISPLAY_EDIT_MENU "--------------Menu edit------------------"
#define MENU_USER "-------------Menu user-------------"
#define MENU_ADMIN "------------Menu admin-------------"
#define MANAGE_COMPANY_CATALOG "\n------Manage company catalog-------\n"
#define MANAGE_LINE_OF_WORK "\n--------Manage line of work--------\n"
#define MANAGE_COMMENTS "\n----------Manage Comments----------\n"
#define LIST "\n---------------List----------------\n"
#define VIEW_REPORTS_DISPLAY "\n-----------View reports------------\n"
#define REPORTS_MENU "-----------View reports------------"
#define MENU_SEARCH "-----------Menu search-------------"
#define EDIT_LINE_OF_WORKS_MENU "------EDIT LINE OF WORKS MENU------"

#define LINE_OF_WORK_ADDED "SUCCESS: Line of Work Added!"
#define COMPANY_FOUND "SUCCESS: Company Found!"
#define COMPANY_REMOVED "SUCCESS: Company Removed!"
#define COMPANY_ADDED "SUCCESS: Company Added!"
#define COMMENT_DELETED "SUCCESS: Comment Deleted!"
#define LINE_OF_WORK_EDITED "SUCCESS: Line Of Work Edited!"
#define LINE_OF_WORK_REMOVED "SUCCESS: Line Of Work Removed!"
#define COMPANY_EDITED "SUCCESS: Company Edited Successfully!"
#define LINE_OF_WORK_CANT_BE_REMOVED "You Cannot Remove This Line Of Work As It Is Being Used By A Company!" 

#define ERROR_INVALID_VALUE "ERROR: the value entered is invalid."
#define ERROR_LIST_IS_FULL "ERROR: the list of company's is full!\n"
#define ERROR_LIST_IS_EMPTY "ERROR: the company list is empty\n"
#define ERROR_LIST_OF_COMMENTS_EMPTY "ERROR: the comment list is empty\n"
#define ERROR_LIST_OF_COMPANY_COMMENT_EMPTY "ERROR: this company don't have comments"
#define ERROR_LIST_IS_EMPTY_LINE_OF_WORK "ERROR: the line of work list is empty\n"
#define ERROR_COMPANY_EXIST "ERROR: the company number is already assigned.\n"
#define ERROR_COMPANY_NIF_EXIST "ERROR: the company NIF is already assigned.\n"
#define ERROR_COMPANY_NAME_EXIST "ERROR: the company Name is already assigned.\n"
#define ERROR_COMPANY_DO_NOT_EXIST "ERROR: the company do not exist!\n"
#define ERROR_LINE_OF_WORK_EXIST "ERROR: business number already in use!"
#define ERROR_LINE_OF_WORK_DO_NOT_EXIST "ERROR: the Line of Work Do Not Exist!\n"
#define ERROR_MESSAGE "ERROR: choose the right option!\n"
#define ERROR_ALLOCATE_MEMORY "ERROR: failed to allocate memory.\n"
#define ERROR_CANT_REMOVE_COMMENTS "ERROR: you can't remove a company with comments"

#define COMPANIES_INITIAL_CAPACITY 100


typedef struct Comment {
    int comment_number;
    bool comment;
    char user_name[MAX_USER_NAME_SIZE];
    char user_email[MAX_USER_EMAIL_SIZE];
    char title[MAX_TITLE_SIZE];
    char text[MAX_TEXT_SIZE];
    struct Comment *following;
    char status[MAX_STATS];
} Comment;

typedef struct {
    int number;
    char name_of_activity[MAX_NAME_ACTIVITY];
    char status[MAX_STATS];
} Line_of_work;

typedef struct {
    int counter;
    Line_of_work *field_of_activity_list;
    
} line_of_work_list;


typedef struct {
    int zipcode1;
    int zipcode2;
} Zipcode;

typedef struct{
    int counter;
    char street[MAX_STREET_COMPANY];
    char municipality[MAX_MUNICIPALITY_COMPANY];
    Zipcode zipcode;
} Address;


typedef struct{
    int comment_counter;
    int number;
    int nif;
    char name[MAX_NAME_COMPANY]; 
    char category[MAX_CATEGORY_COMPANY];
    char status[MAX_STATS];
    Address address;
    Line_of_work line_of_works;
    float totalRating;
    int rating_count;
    float average_rating;
    Comment *comments;
} Company;

typedef struct {
    int counter;
    int used_by_company;
    Company *companies;
} Company_count;

/**
 * @brief This funciton allow acess to admin's menu
 * @param companies Data from Company_count struct.
 * @param field_of_activity_list Data from Line_of_work_list struct.
 */
Company_count *Menu_admin(Company_count *companies, line_of_work_list *field_of_activity_list);

/**
 *@brief  This function allow acess to user's menu
 */
Company_count *Menu_user();

/**
 *@brief This function allow acess to biwe reports menu
 */
void view_reports_menu();
#endif/* FUNCTIONS_H */