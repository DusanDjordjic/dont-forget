#include "todos.h"
#include "../io/io.h"

#include <stdio.h>
#include <stdlib.h>
unsigned int todo_title_length()
{
    unsigned int title_length = 0;
    unsigned int title_num_length = TODO_TITLE_LENGTH;
    do 
    { 
        title_num_length = title_num_length / 10;
        title_length++;
    }while (title_num_length != 0);

    return title_length;
}

void* todos_create(int id, char* title, char* text, struct tm tm)
{
    return NULL;
}


void todo_print(const Todo* todo)
{
    // Convert date to string
    char date_string[80];
    pd_date_to_string(date_string, 80, todo->date);
    printf("%d: %s - %s\n\n%s\n", todo->id, todo->title, date_string, todo->desc);

}

void todo_free(Todo* todo)
{
    free(todo->title);
    free(todo->desc);
    free(todo->date);
    free(todo);
}

void todo_free_inner(const Todo* todo)
{
    free(todo->title);
    free(todo->desc);
    free(todo->date);
}

void todo_populate(Todo* new_todo, int id, char* title, char* desc, struct tm* date)
{
    new_todo->id = id;
    new_todo->title = title;
    new_todo->desc = desc;
    new_todo->date = date;
}

int todo_prompt(Todo* new_todo, int id, char* title_prompt, char* desc_prompt, char* date_prompt)
{
    char* title = NULL;
    char* desc = NULL;
    char* date_string = NULL;
    struct tm* date = malloc(sizeof(struct tm));

    printf("Let's crate a new todo\n\n");
    
    // Propmt a user to enter a title using title_prompt
    printf("%s", title_prompt);
    title = io_getnstr(TODO_TITLE_LENGTH);
    if(title == NULL)
    {
        perror("Error while reading title\n");
        return 1;
    }
    
    // Propmt a user to enter a description using desc_prompt
    printf("%s", desc_prompt);
    desc = io_getstr();
    if(desc == NULL)
    {
        perror("Error while reading description\n");
        free(title);
        return 2;
    }

    // Propmt a user to enter a date using date_prompt
    printf("%s", date_prompt);
    date_string = io_getnstr(80);
    if(date_string == NULL)
    {
        perror("Error while reading date\n");
        free(title);
        free(desc);
        return 3;
    }

    if(pd_string_to_date(date_string, date) == NULL)
    {
        // Free memory
        perror("Invalid date format\n");
        free(title);
        free(desc);
        free(date_string);
        return 4;
    }

    free(date_string);
    // Handle Error

    // Send data to todo_create and return created pointer
    todo_populate(new_todo, id, title, desc, date);
    return 0;
}
