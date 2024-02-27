/**
 * @file files.h
 * @author Hugo Martins & João Ribeiro
 * @date 10-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for program files(save, load).
 */
#ifndef FILES_H
#define FILES_H

/**
 * @brief This function allow load you last input about the companies.
 * @param companies Data from Company_count struct.
 * @param filename Name of the file.
 */
Company_count *load_companies(Company_count *companies, char *filename);

/**
 * @brief This function allow save your input about the companies.
 * @param companies Data from Company_count struct.
 * @param filename Name of the file.
 */
Company_count *save_companies (Company_count *companies, char *filename);

/**
 * @brief This function allow load you last input about the line of work.
 * @param companies Data from Line_of_work_list struct.
 * @param filename Name of the file.
 */
line_of_work_list *load_line_of_work(line_of_work_list *field_of_activity_list, char *filename);

/**
 * @brief This function allow save your input about the companies.
 * @param companies Data from Line_of_work_list struct.
 * @param filename Name of the file.
 */
line_of_work_list *save_line_of_work(line_of_work_list *field_of_activity_list, char *filename);

/**
 * @brief This function allow free your memory abot the companies.
 * @param companies Data from Company_count struct.
 */
void free_company(Company_count *companies);

/**
 * @brief This function allow free your memory abot the line of works.
 * @param field_of_activity_list Data from Line_of_work_list struct.
 */
void free_line_of_work(line_of_work_list *field_of_activity_list);

/**
 * @brief This function allow alloc comment.
 * @param size Comment size
 */
Comment *alloc_comment_array(int size);


#endif/* FILES_H */