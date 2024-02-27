/**
 * @file comment.h
 * @author Hugo Martins & João Ribeiro
 * @date 10-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for comment input.
 */

#ifndef COMMENT_H
#define COMMENT_H
/**
 * @brief This function confirm if the company has any comments.
 * @param company Data from comments inserted in the Comment struct.
 * @return This function returns a True value if the company has comments.
 */
bool company_comments(Company *company);


/**
 * @brief This function list active comments about a determinated company.
 * @param companies Data from comments inserted in the Comment struct.
 * @param number Receive the company number.
 */
Company_count *list_company_comments_user(Company_count *companies, int number);

/**
 * @brief This function list all comments about a determinated company.
 * @param companies Data from comments inserted in the Comment struct.
 */
Company_count *list_company_comments(Company_count *companies);

/**
 * @brief This function allow comment anyone company.
 * @param companies Data from comments inserted in the Comment struct.
 */
Company_count *company_comment(Company_count *companies);

/**
 * @brief This function allow's delete comments.
 * @param companies Data from comments inserted in the Comment struct.
 */
void delete_comment (Company_count *companies);

/**
 * @brief This function allow hide comments.
 * @param companies Data from comments inserted in the Comment struct.
 */
void hide_comment(Company_count *companies);
#endif /* COMMENT_H */