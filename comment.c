/**
 * @file comment.c
 * @author Hugo Martins & João Ribeiro
 * @date 10-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for comment input.
 */

#include "util.h"
#include "functions.h"
#include "files.h"
#include "comment.h"
#include "LineOfWork.h"
#include "UserSearch.h"
#include "company.h"

bool company_comments(Company *company) {
    
    if(company->comment_counter == 0){
        return false;
    }else{
        return true;
    }
}

Company_count *list_company_comments_user(Company_count *companies, int number){
    if (companies->companies[number].comment_counter==0){
        puts(ERROR_LIST_OF_COMPANY_COMMENT_EMPTY);
    }else{
        if (strcmp(companies->companies[number].comments->status, "Active") == 0){
        int i;
    
        puts(LINE);
        puts(MENU_SEE_COMMENTS);
        puts(LINE);

        list_companys(*companies);

        if (companies->companies[number].comment_counter > 0) {
            for (i = 0; i < companies->companies[number].comment_counter; i++) {
                printf("\nUser: %s\nTitle: %s\nComment: %s\nStatus: %s\n",
                       companies->companies[number].comments[i].user_name,
                       companies->companies[number].comments[i].title,
                       companies->companies[number].comments[i].text,
                       companies->companies[number].comments[i].status);
            }

        } else {
            puts(ERROR_LIST_OF_COMPANY_COMMENT_EMPTY);
        }
        return companies;
        } else{
            puts(ERROR_LIST_OF_COMPANY_COMMENT_EMPTY);
        }
    }
}

Company_count *list_company_comments(Company_count *companies) {
    int i;
    
    puts(LINE);
    puts(MENU_SEE_COMMENTS);
    puts(LINE);

    list_companys(*companies);

    int company_number = getInt(MIN_NUMBER_COMPANY, MAX_NUMBER_COMPANY, MSG_GET_NUMBER_COMPANY);
    int location = get_company_position(*companies, company_number);
    if (location == -1) {
        puts(ERROR_COMPANY_DO_NOT_EXIST);
        return companies;
    }
    if (companies->companies[location].comment_counter > 0) {
        for (i = 0; i < companies->companies[location].comment_counter; i++) {
            printf("\nUser: %s\nTitle: %s\nComment: %s\nStatus: %s\n",
                   companies->companies[location].comments[i].user_name,
                   companies->companies[location].comments[i].title,
                   companies->companies[location].comments[i].text,
                   companies->companies[location].comments[i].status);
        }
        
    } else {
        puts(ERROR_LIST_OF_COMMENTS_EMPTY);
    }
    return companies;
}

Company_count *company_comment(Company_count *companies) {
    list_companys(*companies);

    int company_number = getInt(MIN_NUMBER_COMPANY, MAX_NUMBER_COMPANY, MSG_GET_NUMBER_COMPANY);
    int position = get_company_position(*companies, company_number);
    int comment_position = companies->companies[position].comment_counter;
    if (position == -1) {
        puts(ERROR_LIST_IS_EMPTY);
        return companies;
    }
    if(companies->companies[position].comments == NULL){
    companies->companies[position].comments=(Comment *) malloc(1 * sizeof (Comment));
    }
    else{
    companies->companies[position].comments=realloc(companies->companies[position].comments,5* sizeof(Comment));    
    }
    if (companies->companies[position].comments == NULL) {
        puts(ERROR_ALLOCATE_MEMORY);
        return companies;
    }
    readString(companies->companies[position].comments[comment_position].user_name, MAX_USER_NAME_SIZE, "Enter your name: ");
    readString(companies->companies[position].comments[comment_position].user_email, MAX_USER_EMAIL_SIZE, "Enter your email: ");
    readString(companies->companies[position].comments[comment_position].title, MAX_TITLE_SIZE, "Enter comment title: ");
    readString(companies->companies[position].comments[comment_position].text, MAX_TEXT_SIZE, "Enter your comment: ");
    strcpy(companies->companies[position].comments[comment_position].status, "Active");
    companies->companies[position].comments[comment_position].following = companies->companies[position].comments;
    
    companies->companies[position].comments[comment_position].comment = true;
    companies->companies[position].comments[comment_position].comment_number++;
    companies->companies[position].comment_counter++;
    
    
    return companies;
}

void clean_comments(Comment *comment){
    comment->comment_number = 0;
    strcpy(comment->text, "");
    strcpy(comment->title, "");
    strcpy(comment->user_email, "");
    strcpy(comment->user_name, "");
    strcpy(comment->status, "Inactive");
}

bool company_has_comments(Company *company) {
    return company->comments->comment;
}

void delete_comment (Company_count *companies){
    list_companys(*companies);
    
    int company_number = getInt(MIN_NUMBER_COMPANY, MAX_NUMBER_COMPANY, MSG_GET_NUMBER_COMPANY);
    int position = get_company_position(*companies, company_number);
    
    if (position == -1){
        puts(ERROR_COMPANY_DO_NOT_EXIST);
        return;
    }
    
    list_company_comments(companies); 
    
    int comment_id = getInt(MIN_NUMBER_COMPANY, MAX_NUMBER_COMPANY, MSG_GET_NUMBER_COMPANY);
    
    if(company_has_comments(&companies->companies[position])){
        
        companies->companies[position].comments[comment_id] = companies->companies[position].comments[companies->companies[position].comment_counter - 1];
        clean_comments(&(companies->companies[position].comments[companies->companies[position].comment_counter - 1]));
    }
    
    puts("Comment delete successfully!");
    
    companies->companies[position].comment_counter--;
}

int get_comment_number (Company_count companies,int number){
    int i;
    for (i=0; i<companies.companies->comment_counter; i++){
        if(companies.companies->comments[i].comment_number == number){
            return i;
        }
    }
    return -1;
}

void hide_comment(Company_count *companies){
    int position = get_company_position(*companies, getInt(MIN_NUMBER_COMPANY, MAX_NUMBER_COMPANY, MSG_GET_NUMBER_COMPANY));
    int number = get_comment_number(*companies, getInt(MIN_NUMBER_COMPANY, MAX_NUMBER_COMPANY, MSG_GET_NUMBER_COMPANY));
    char new_Status[MAX_STATS];
    if (position == -1) {
        puts(ERROR_COMPANY_DO_NOT_EXIST);
        return;
    }
    printf(MSG_CURRENT_STATS, companies->companies[position].comments[number].status);
    readString(new_Status, MAX_STATS, NEW_STATS_MSG);
    strcpy(companies->companies[position].comments[number].status, new_Status);

    puts(COMPANY_EDITED);
    return;
}