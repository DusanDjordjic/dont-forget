#ifndef _TODOS_H_
#define _TODOS_H_
#include "../parsing_dates/parsing_dates.h"

typedef struct Todo {
    int id;
    char* title;
    char* desc;
    struct tm* date;
} Todo;

void    todo_print(const Todo* todo);
Todo*   todo_create(int id, char* title, char* desc, struct tm* date);
Todo*   todo_prompt(int id, char* title_prompt, char* desc_prompt, char* date_prompt);
#endif
