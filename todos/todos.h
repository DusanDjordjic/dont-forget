#ifndef _TODOS_H_
#define _TODOS_H_
#define TODO_TITLE_LENGTH 24
#include "../parsing_dates/parsing_dates.h"

typedef struct Todo {
    int id;
    char* title;
    char* desc;
    struct tm* date;
} Todo;

void            todo_print(const Todo* todo);
void            todo_free(Todo* todo);
void            todo_free_inner(const Todo* todo);
void            todo_populate(Todo* new_todo, int id, char* title, char* desc, struct tm* date);
int             todo_prompt(Todo* new_todo, int id, char* title_prompt, char* desc_prompt, char* date_prompt);
unsigned int    todo_title_length();
#endif
