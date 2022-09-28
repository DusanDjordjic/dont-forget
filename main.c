#define _XOPEN_SOURCE

#include <stdio.h>
#include <libnotify/notify.h>
#include <libnotify/notification.h>
#include <time.h>

int main(int argc, char* argv[])
{

    /** 
     * TODO :
     *      Make date parse and format api
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

    /* Parsing time to date */
    /* MM/DD/YY */

    time_t rawtime;
    struct tm *info;
    char buffer[80];

    time(&rawtime);
    info = localtime(&rawtime);

    int written = strftime(buffer, 80, "%x - %I:%M%p", info);
    buffer[written] = '\0';

    /* Sending notifications */

    notify_init("Current Time");    
    NotifyNotification* current_time = notify_notification_new("Current Time", buffer, "dialog-information");

    notify_notification_show(current_time, NULL);
    g_object_unref(G_OBJECT(current_time));

    notify_uninit();

    return 0;
}
