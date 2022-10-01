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
char* get_string();
char* get_n_string(unsigned int n);
void clear_buffer();
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
    char* buff = get_string();
    printf("%s\n", buff);
    printf("%lu\n", strlen(buff));
    free(buff);

    printf("Enter another string\n");
    buff = get_n_string(20);
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

void clear_buffer()
{
    while(getc(stdin) != '\n');
}
char* get_n_string(unsigned int n)
{
    char* buffer = malloc(sizeof(char) * n);
    fgets(buffer, n, stdin);
    clear_buffer();
    unsigned long int len = strlen(buffer);
    if(buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';

    return buffer;

}
char* get_string()
{
    unsigned char step = 32;
    unsigned int size = 1; // Add 1 for '\0'
    char* str = malloc(sizeof(char));
    char buffer[step]; 
    ssize_t i;
    do 
    {
        memset(buffer, '\0', step);
        i = read(STDIN_FILENO, buffer, step);
        if(i < 0)
        {
            printf("Error while reading from stdin");
            fflush(stdout);
            break;
        }
        else if(i == 0)
        {
            // Done 
            break;
        }
        // size = 1, i = 5, size = 6
        // input: abcde
        // str: ......
        // offset 6 - 5 - 1 = 0
        // memset: 0, 0, 6 (i + 1)
        // str: 000000
        // str: abcde\0
        
        // size = 6, i = 3,
        // size = 9,
        // fg\n
        // str:abcde\0...
        // memset: 5, 0, 4
        // 9 - 3 - 1 = 5
        // str:abcdefg\n\0
        
        size += i;
        str = realloc(str, sizeof(*str) * size);
        memset(str + size - i - 1, 0, i + 1);
        assert(str != NULL);
        strncat(str, buffer, i);
        
    }while (i == step);

    str[strlen(str) - 1] = '\0'; // strlen - 1 is always a new line 
    return str;
}
