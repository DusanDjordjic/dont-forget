#include <stdio.h>
#include <stdlib.h>
#include <libnotify/notify.h> 
#include <string.h>
#include "parsing_dates/parsing_dates.h"
#include "todos/todos.h"
#include "io/io.h"

int main(int argc, char* argv[])
{

    /** 
     * TODO :
     *      DONE Make date parse and format api
     *      Make todo list api
     *      Make terminal ui to use todo list
     *      Make notification interface
     *      Connect todo list with notifications
     *      Run process in bg that will notify the user about todo item
     * 
     * Aditional:
     *      Make configuration file: 
     *           User can select a date format?
     *           User can turn of some/all notifications
     *
     *      Make installation script?
     *
     */

    unsigned long int size = 16, n1, n2, n;
    char* str = malloc(sizeof(char) * size);
    memset(str, 0, size);
    strncpy(str, " \n \n dus an  \n ", size - 1);
    printf("%lu,'%s'\n",strlen(str), str);

    n1 = io_trim_str_right(&str);
    printf("%lu,'%s'\n",strlen(str), str);

    n2 = io_trim_str_left(&str);
    printf("%lu,'%s'\n",strlen(str), str);
    memset(str, 0, size);
    strncpy(str, " \n \n dus an \n \n ", size - 1);
    n = io_trim_str(&str);
    printf("N1 + N2 == N;\n%lu + %lu == %lu\n", n1, n2, n);
    free(str);
    return 0;

 
    Todo t;
    // 22 + TODO_TITLE_LENGTH string length
    char title_prompt[22 + todo_title_length()];
    sprintf(title_prompt, "Enter a title (max %d):", TODO_TITLE_LENGTH);

    if(todo_prompt(&t, 1, title_prompt, "Enter a todo text:", "Enter a reminder date (YYYY-MM-DD):") != 0)
    {
        perror("Error while creating a todo\n");
        return 1;
    }
   
    todo_print(&t);

    todo_free_inner(&t);
    return 0;

    /* Sending notifications */

    char buffer[10];
    notify_init("Current Time");    
    NotifyNotification* current_time = notify_notification_new("Current Time", buffer, "dialog-information");

    notify_notification_show(current_time, NULL);
    g_object_unref(G_OBJECT(current_time));

    notify_uninit();

    return 0;
}

