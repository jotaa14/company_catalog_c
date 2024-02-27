/**
 * @file files.c
 * @author Hugo Martins & João Ribeiro
 * @date 10-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for program files(save, load).
 */

#include "util.h"
#include "functions.h"
#include "files.h"
#include "comment.h"
#include "LineOfWork.h"
#include "UserSearch.h"
#include "company.h"

Company_count *load_companies(Company_count *companies, char *filename) {
    int i, success = 0;
    FILE *fp = fopen(filename, "rb");
    fread(&companies->counter, sizeof (int), 1, fp);



    if (companies->counter > 0) {
        companies->companies = (Company*) calloc(companies->counter, sizeof (Company));
        for (i = 0; i < companies->counter; i++) {
            fread(&companies->companies[i], sizeof (Company), 1, fp);
            fread(&companies->companies[i].comment_counter, sizeof(int), 1, fp);
            companies->companies[i].comments = (Comment*) malloc(companies->companies[i].comment_counter * sizeof(Comment));
            for (int j = 0; j < companies->companies[i].comment_counter; j++){
            fread(&(companies->companies[i].comments[j]), sizeof(Comment), 1,fp);

            }
           
        }
        success = 1;
    }
    fclose(fp);

    if (!success) {
        fp = fopen(filename, "wb");
        if (fp != NULL) {
            companies->companies = (Company*) calloc(companies->counter, sizeof (Company));
            companies->counter = 0;
            fclose(fp);
        }
    }

    return companies;
}

Company_count *save_companies(Company_count *companies, char *filename) {
    int i;
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        exit(EXIT_FAILURE);
    }

    fwrite(&companies->counter, sizeof (int), 1, fp);
    for (i = 0; i < companies->counter; i++) {
        fwrite(&companies->companies[i], sizeof (Company), 1, fp);
        fwrite(&(companies->companies[i].comment_counter), sizeof (int),1,fp);
        for (int j = 0; j < companies->companies[i].comment_counter; j++) {
            fwrite(&(companies->companies[i].comments[j]), sizeof (Comment), 1, fp);

        }
    }
    fclose(fp);
    return companies;
}


line_of_work_list *load_line_of_work(line_of_work_list *field_of_activity_list, char *filename){
    int i, success=0;
    FILE *fp = fopen(filename, "rb");
    fread(&field_of_activity_list->counter, sizeof(int),1,fp);
    
    if(field_of_activity_list->counter > 0){
        field_of_activity_list->field_of_activity_list = (Line_of_work*) calloc(field_of_activity_list->counter , sizeof(Line_of_work));
        for(i=0; i<field_of_activity_list->counter;i++){
            fread(&field_of_activity_list->field_of_activity_list[i],sizeof(Line_of_work),1,fp);
        }
        success=1;
    }
    fclose(fp);
    
    if(!success){
        fp = fopen(filename, "wb");
        if(fp!=NULL){
            field_of_activity_list->field_of_activity_list = (Line_of_work*) calloc(field_of_activity_list->counter , sizeof(Line_of_work));
            field_of_activity_list->counter = 0;
            fclose(fp);
        }
    }
    return field_of_activity_list;
}

line_of_work_list *save_line_of_work(line_of_work_list *field_of_activity_list, char *filename){
    int i;
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL){
        exit(EXIT_FAILURE);
    }
    fwrite(&field_of_activity_list->counter, sizeof(int),1,fp);
    for( i=0; i<field_of_activity_list->counter; i++){
        fwrite(&field_of_activity_list->field_of_activity_list[i],sizeof(Line_of_work), 1, fp);
    }
    fclose(fp);
    return field_of_activity_list;
}

void free_company(Company_count *companies) {
    if(companies->counter != 0){
        free(companies);
    }
    return;
}

void free_line_of_work(line_of_work_list *field_of_activity_list){
    if(field_of_activity_list->counter != 0){
        free(field_of_activity_list);
    }
    return;
}


Comment *alloc_comment_array(int size) {
    return (Comment*) calloc(size, sizeof (Comment));
}