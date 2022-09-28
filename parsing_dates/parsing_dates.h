#ifndef _PARSING_DATES_H_
#define _PARSING_DATES_H_

#define _XOPEN_SOURCE

#define DATE_FORMAT "%F" /* YYYY-MM-DD */

#include <time.h>
#include <string.h>

/* Interface for date parser */

const char*     pd_string_to_date(const char* input, struct tm* tm); // Returns NULL if failed, points to the next char in string that isn't parsed;
unsigned char   pd_date_to_string(char* input, unsigned char size, struct tm* tm); // Returns the number of charachters written in input string;
void            pd_print(struct tm *tm); // Uses pd_date_to_string to get the string and prints it to stdout;

#endif
