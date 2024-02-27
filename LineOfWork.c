/**
 * @file LineOfWork.c
 * @author Hugo Martins & João Ribeiro
 * @date 10-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for line of work input.
 */

#include "util.h"
#include "functions.h"
#include "files.h"
#include "comment.h"
#include "LineOfWork.h"
#include "UserSearch.h"
#include "company.h"

void print_line_of_work(Line_of_work line_of_work) {
    puts(LINE);
    puts(LINE_OF_WORK_DISPLAY);
    puts(LINE);
    printf("Number:%d\nName:%s\nStatus:%s\n", line_of_work.number, line_of_work.name_of_activity, line_of_work.status);
}

int get_line_of_work_position(line_of_work_list field_of_activity_list, int number) {
    int i;
    for (i = 0; i < field_of_activity_list.counter; i++) {
        if (field_of_activity_list.field_of_activity_list[i].number == number) {
            return i;
        }
    }
    return -1;
}

line_of_work_list *insert_line_of_work(line_of_work_list *field_of_activity_list) {
    
    int number = getInt(MIN_NUMBER_LINE_OF_WORK, MAX_NUMBER_LINE_OF_WORK, MSG_GET_NUMBER_LINE_OF_WORK);
    
    if (get_line_of_work_position(*field_of_activity_list, number) != -1) {
        puts(ERROR_LINE_OF_WORK_EXIST);
        return field_of_activity_list;
    }
    field_of_activity_list->field_of_activity_list[field_of_activity_list->counter].number = number;

    readString(field_of_activity_list->field_of_activity_list[field_of_activity_list->counter].name_of_activity, MAX_NAME_ACTIVITY, MSG_GET_LINE_OF_WORK);
    strcpy(field_of_activity_list->field_of_activity_list[field_of_activity_list->counter].status, "Active");

    field_of_activity_list->counter++;

    puts(LINE_OF_WORK_ADDED);
    return field_of_activity_list;
}

void list_line_of_work(line_of_work_list field_of_activity_list) {
    int i;
    if (field_of_activity_list.counter > 0) {
        for (i = 0; i < field_of_activity_list.counter; i++) {
            print_line_of_work(field_of_activity_list.field_of_activity_list[i]);
        }
    } else {
        puts(ERROR_LIST_IS_EMPTY_LINE_OF_WORK);
    }

}

int choose_line_of_work(const line_of_work_list *field_of_activity_list) {
    list_line_of_work(*field_of_activity_list);
    int line_of_work_choice = getInt(MIN_NUMBER_LINE_OF_WORK, MAX_NUMBER_LINE_OF_WORK, MSG_GET_NUMBER_LINE_OF_WORK);
    if (line_of_work_choice < 1 || line_of_work_choice > field_of_activity_list-> counter) {
        puts(ERROR_MESSAGE);
    }

    return line_of_work_choice - 1;
}

void edit_line_of_work_status(line_of_work_list *field_of_activity_list){
    int position = get_line_of_work_position(*field_of_activity_list, getInt(MIN_NUMBER_LINE_OF_WORK, MAX_NUMBER_LINE_OF_WORK, MSG_GET_NUMBER_LINE_OF_WORK));
    char new_Status[MAX_STATS];
    if (position == -1) {
        puts(ERROR_COMPANY_DO_NOT_EXIST);
        return;
    }
    printf(MSG_CURRENT_STATS, field_of_activity_list->field_of_activity_list[position].status);
    readString(new_Status, MAX_STATS, NEW_STATS_MSG);
    strcpy(field_of_activity_list->field_of_activity_list[position].status, new_Status);

}

void edit_line_of_work(line_of_work_list *field_of_activity_list) {
    int edit_menu;
    list_line_of_work(*field_of_activity_list);

    int position = get_line_of_work_position(*field_of_activity_list, getInt(MIN_NUMBER_LINE_OF_WORK, MAX_NUMBER_LINE_OF_WORK, MSG_GET_NUMBER_LINE_OF_WORK));
    
    if (position == -1) {
        puts(ERROR_LINE_OF_WORK_DO_NOT_EXIST);
        return;
    }
    do{
        puts(EDIT_LINE_OF_WORKS_MENU);
        puts(EDIT_NAME_LINE_OF_WORK);
        puts(EDIT_STATUS_LINE_OF_WORK);
        scanf("%d", &edit_menu); 
        switch (edit_menu){
            case 1:
                 readString(field_of_activity_list->field_of_activity_list[position].name_of_activity, MAX_NAME_ACTIVITY, MSG_GET_LINE_OF_WORK);
                break;
            case 2:
                edit_line_of_work_status(field_of_activity_list);
                break;
        }
    }while (edit_menu!=0);
    puts(LINE_OF_WORK_EDITED);
}



void remove_line_of_work(Company_count *companies, line_of_work_list *field_of_activity_list) {
    int position = get_line_of_work_position(*field_of_activity_list, getInt(MIN_NUMBER_LINE_OF_WORK, MAX_NUMBER_LINE_OF_WORK, MSG_GET_NUMBER_LINE_OF_WORK));
    if (position == -1) {
        puts(ERROR_COMPANY_DO_NOT_EXIST);
        return;
    }

    if (companies[position].used_by_company == 0) {
        field_of_activity_list->field_of_activity_list[position].number = 0;
        strcpy(field_of_activity_list->field_of_activity_list[position].name_of_activity, "");
        strcpy(field_of_activity_list->field_of_activity_list[position].status, "");

        for (int i = position; i < field_of_activity_list->counter - 1; i++) {
            field_of_activity_list->field_of_activity_list[i] = field_of_activity_list->field_of_activity_list[i + 1];
        }
        field_of_activity_list->counter--;

        puts(LINE_OF_WORK_REMOVED);
    } else {
        puts(LINE_OF_WORK_CANT_BE_REMOVED);
    }
}