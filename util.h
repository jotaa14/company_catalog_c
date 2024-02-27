/**
 * @file util.h
 * @author Hugo Martins & João Ribeiro
 * @date 29-11-2023
 * @version 1
 *
 * @copyright Copyright (C) ESTG 2023. All Rights MIT Licensed.
 *
 * @brief Contains functions for get input, clean buffer and validate nif.
 */

#ifndef UTIL_H
#define UTIL_H

/**
 * @brief This function prompts the user to input an integer within a specified range and displays a custom message.
 * @param minValue The minimum valid integer value.
 * @param maxValue The maximum valid integer value.
 * @param msg A custom message to prompt the user for input.
 * @return The user-provided integer value within the specified range.
 */
int getInt(int minValue, int maxValue, char *msg);

/**
 * @brief This function prompts the user to input a single character and displays a custom message.
 * @param msg A custom message to prompt the user for input.
 * @return The user-provided character.
 */
char getChar(char *msg);

/**
 * @brief This function prompts the user to input a floating-point number within a specified range and displays a custom message.
 * @param minValor The minimum valid floating-point value.
 * @param maxValor The maximum valid floating-point value.
 * @param msg A custom message to prompt the user for input.
 * @return The user-provided floating-point value within the specified range.
 */
float getFloat(float minValue, float maxValue, char *msg);

/**
 * @brief This function reads a string of characters from the user with a specified maximum length and displays a custom message.
 * @param string A character array to store the user-provided string.
 * @param size The maximum number of characters that can be read (including null terminator).
 * @param msg A custom message to prompt the user for input.
 * @return This function does not return a value. It populates the string parameter with the user's input.
 */
void readString(char *string, unsigned int size, char *msg);

/**
 * @brief This function cleans buffer.
 * @return This function does not return a value.
 */
void cleanInputBuffer();

/**
 * @brief This function get nif of company.
 * @param msg A message that tells the user to indicate the NIF.
 * @return This function return a NIF value.
 */
int get_nif(char *msg);

/**
 * @brief This function validate NIF of companies.
 * @param nif The number provided.
 * @return This function return a NIF Value if it's correct.
 */
int valid_nif(int nif);



#endif/* UTIL_H */