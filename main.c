#include <time.h>
#define _XOPEN_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <libnotify/notify.h> 
#include <libnotify/notification.h>
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

