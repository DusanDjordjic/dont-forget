#include "todos.h"
#include <stdio.h>
#include <stdlib.h>
void* todos_create(int id, char* title, char* text, struct tm tm)
{
    return NULL;
}


void todo_print(const Todo* todo)
{
    // Convert date to string
    char date_string[80];
    pd_date_to_string(date_string, 80, todo->date);
    printf("%d: %s - %s\n\n%s\n", todo->id, todo->title, todo->desc, date_string);

}
Todo* todo_create(int id, char* title, char* desc, struct tm* date)
{
    // Allocate memory for new todo
    Todo* new_todo = malloc(sizeof(Todo));

    if (new_todo == NULL)
    {
        perror("Faield to create new todo");
        return NULL;
    }

    // Assign it's properties
    new_todo->id = id;
    new_todo->title = title;
    new_todo->desc = desc;
    new_todo->date = date;

    return new_todo;
}
Todo* todo_prompt(int id, char* title_prompt, char* desc_prompt, char* date_prompt)
{
    char* title = NULL;
    char* desc = NULL;
    char* date_string = NULL;
    struct tm* date = malloc(sizeof(struct tm));

    printf("Let's crate a new todo\n\n");
    // Propmt a user to enter a title using title_prompt
    printf("%s", title_prompt);

    // Propmt a user to enter a description using desc_prompt
    printf("%s", desc_prompt);

    // Propmt a user to enter a date using date_prompt
    printf("%s", date_prompt);
    if(pd_string_to_date(date_string, date) == NULL)
    {
        // Free memory
        perror("Invalid date format\n");
        return NULL;
    }
    // Handle Error

    // Send data to todo_create and return created pointer
    
    return todo_create(id, title, desc, date);
}
