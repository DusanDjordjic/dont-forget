#include <time.h>
#define _XOPEN_SOURCE

#include <stdio.h>
#include <string.h>
#include <libnotify/notify.h> 
#include <libnotify/notification.h>
#include "parsing_dates/parsing_dates.h"

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

    /* Parsing time to date */
    

    struct tm tm;
    char* date = "2022-09-27";

    const char* cp = pd_string_to_date(date, &tm);
    pd_print(&tm);

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
