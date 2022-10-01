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


    printf("Enter a string\n");
    char* buff = io_getstr();
    printf("%s\n", buff);
    printf("%lu\n", strlen(buff));
    free(buff);

    printf("Enter another string\n");
    buff = io_getnstr(20);
    printf("%s\n", buff);
    printf("%lu\n", strlen(buff));
    free(buff);
    

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

