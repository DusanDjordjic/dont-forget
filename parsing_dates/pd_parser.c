#include "parsing_dates.h"
#include <stdio.h>

const char* pd_string_to_date(const char* input, struct tm *tm)
{
    memset(tm, '\0', sizeof(*tm));
    return  strptime(input, DATE_FORMAT, tm);
}

unsigned char pd_date_to_string(char* input, const unsigned char size, const struct tm *tm)
{
    return strftime(input, size, DATE_FORMAT, tm);
}

void pd_print(struct tm *tm)
{
    char buffer[80];
    pd_date_to_string(buffer, 80, tm);
    printf("%s\n", buffer);
}
