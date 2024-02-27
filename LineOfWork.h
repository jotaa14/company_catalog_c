/**
 * @file LineOfWork.h
 * @author Hugo Martins & João Ribeiro
 * @date 10-01-2024
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for line of work input.
 */

#ifndef LINEOFWORK_H
#define LINEOFWORK_H
/**
 * @brief This function allows print number and the line of work.
 * @param line_of_work Data of the Line_of_work struct.
 */
void print_line_of_work(Line_of_work line_of_work);

/**
 * @brief This function allows you get the line of work position.
 * @param field_of_activity_list Data of the Line_of_work_list struct.
 * @param number Number of the line of work
 * @return Line of work position
 */
int get_line_of_work_position(line_of_work_list field_of_activity_list, int number);

/**
 * @brief This funtion allow you insert a new line of work.
 * @param field_of_activity_list Data of the Line_of_work_list struct.
 */
line_of_work_list *insert_line_of_work(line_of_work_list *field_of_activity_list);

/**
 * @brief This function allows list all line of works.
 * @param field_of_activity_list Data of the Line_of_work_list struct.
 */
void list_line_of_work(line_of_work_list field_of_activity_list);

/**
 * @brief This function allow you choose what line of work you want.
 * @param field_of_activity_list Data of the Line_of_work_list struct.
 * @return Line of work choiced.
 */
int choose_line_of_work(const line_of_work_list *field_of_activity_list);

/**
 * @brief This function allow you edit the line of work.
 * @param field_of_activity_list Data of the Line_of_work_list struct.
 */
void edit_line_of_work (line_of_work_list *field_of_activity_list);

/**
 * @brief This function allow you edit the line of work status.
 * @param field_of_activity_list Data of the Line_of_work_list struct.
 */
void edit_line_of_work_status(line_of_work_list *field_of_activity_list);

/**
 * @brief This fuction allow you remove a line of work if isn't used by anyone company.
 * @param companies Data of the Company_count struct.
 * @param field_of_activity_list Data of the Line_of_work_list struct.
 */
void remove_line_of_work(Company_count *companies, line_of_work_list *field_of_activity_list);

#endif/* LINEOFWORK_H */