/**
 * @file UserSearch.h
 * @author Hugo Martins & João Ribeiro
 * @date 10-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for search companies.
 */

#ifndef USERSEARCH_H
#define USERSEARCH_H

/**
 * @brief This function allow you what the method you want to choose
 * to search your company.
 * @param companies Data of the Company_count struct.
 */
void search_company(Company_count *companies);

/**
 * @brief This function allow you get company position by nif.
 * @param companies Data of the Company_count struct.
 * @param get_nif NIF.
 * @return Position of the company.
 */
int get_company_nif(Company_count *companies, int get_nif);

/**
 * @brief This function allow you get company position by nif.
 * @param companies Data of the Company_count struct.
 * @param get_name Name of the company.
 * @return Position of the company.
 */
int get_name_position(Company_count *companies, const char *get_name);

/**
 * @brief This function allow you get company position by local.
 * @param companies Data of the Company_count struct.
 * @param get_name Local of the company.
 * @return Position of the company.
 */
int get_local_position(Company_count *companies, const char *get_local);

/**
 * @brief This function allow search the company by NIF.
 * @param companies Data of the Company_count struct.
 */
void search_nif(Company_count *companies);

/**
 * @brief This function allow search the company by name.
 * @param companies Data of the Company_count struct.
 */
void search_name(Company_count *companies);

/**
 * @brief This function allow search the company by local.
 * @param companies Data of the Company_count struct.
 */
void search_local(Company_count *companies);

#endif /* USERSEARCH_H */