/**
 * @file company.h
 * @author Hugo Martins & João Ribeiro
 * @date 10-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for company input.
 */

#ifndef COMPANY_H
#define COMPANY_H
/**
 * This function allows you get the company position.
 * @param companies Data of the Company_count struct.
 * @param number1 Number of the company
 * @return Company position
 */
int get_company_position(Company_count companies, int number1);

/**
 * @brief This funtion allow you insert a new line of work.
 * @param companies Data of the Company_count struct.
 * @param field_of_activity_list Data of the Line_of_work_list struct.
 */
Company_count *create_company(Company_count *companies, line_of_work_list *field_of_activity_list);

/**
 * @brief This function allows print number and the company.
 * @param company Data of the Company struct.
 */
void print_company(Company company);

/**
 * @brief This function allows list all companies.
 * @param companies Data of the Company_count struct.
 */
void list_companys(Company_count companies);

/**
 * @brief This function allow you edit the company.
 * @param companies Data of the Company_count struct.
 */
void edit_company(Company_count *companies);

/**
 * @brief This function allow you edit the company status.
 * @param companies Data of the Company_count struct.
 */
void Edit_company_status(Company_count *companies);

/**
 * @brief This function allow clean data about the company.
 * @param company Data of the Company struct.
 */
void clean_Data_company(Company *company);

/**
 * @brief This fuction allow you remove a company if isn't commented.
 * @param companies Data of the Company_count struct.
 */
void remove_company(Company_count *companies);

/**
 * @brief This function allow you rate a company.
 * @param companies Data of the Company_count struct.
 */
void rating_company(Company_count *companies);

#endif/* COMPANY_H */