#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

void io_clear_buffer()
{
    while(fgetc(stdin) != '\n');
}

char* io_getnstr(unsigned int n)
{
    // Add + 1 because fgets reads one less char and adds '\0'
    char* buffer = malloc(sizeof(char) * (n + 1));
    if (buffer == NULL) return NULL;

    fgets(buffer, n + 1, stdin);

    unsigned long int len = strlen(buffer);
    if(buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
    
    // No need to clear a stdio buffer if there are no more chars 
    else if (len == n) io_clear_buffer();

    return buffer;

}

char* io_getstr()
{
    unsigned char step = 32;
    unsigned int size = 1; // Add 1 for '\0'
    char* str = malloc(sizeof(char));
    if(str == NULL) return NULL;
    char buffer[step]; 
    ssize_t i;
    do 
    {
        i = read(STDIN_FILENO, buffer, step);

        if(i < 0)
        {
            // Error
            if(str != NULL) free(str);
            return NULL;
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
        
        // size = 6, i = 3, size = 9,
        // input: fg\n
        // str: abcde\0...
        // memset: 5, 0, 4
        // str:abcdefg\n\0
        
        size += i;
        str = realloc(str, sizeof(*str) * size);
        if(str == NULL) return NULL;

        memset(str + size - i - 1, '\0', i + 1);
        strncat(str, buffer, i);
    }while (i == step);
    
    str[strlen(str) - 1] = '\0'; // strlen - 1 is always a new line 
    return str;
}

unsigned long int io_trim_str(char** str)
{
    unsigned long int n = 0;
    n += io_trim_str_right(str);
    n += io_trim_str_left(str);
    return n;
}

unsigned long int io_trim_str_left(char** str)
{
    char* out_str = NULL;
    unsigned long int len = strlen(*str);
    unsigned long int i = len - 1; // -1 to skip '\0'
    unsigned long int n = 0;

    while((*str)[i] == ' ' || (*str)[i] == '\n')
    {
        i--;
        n++;
    }

    printf("N IS : %lu\n", n);
    fflush(stdout);
    // str: "dusan  \0" -> len 7
    // i: 2
    // out: "dusan." len - i = 5
    // memcpy: to out, from str + i ('d'), size 5
    // out[len - i] = '\0': "dusan\0"
    if (n > 0)
    {
        out_str = malloc(sizeof(**str) * (len - n + 1));
        if(out_str == NULL) return -1;
        memcpy(out_str, *str, len - n);
        out_str[len - n] = '\0';
    }
    else
    {
        return 0;
    }

    free(*str);
    *str = out_str;
    return n;
}

unsigned long int io_trim_str_right(char** str)
{
    char* out_str = NULL;
    unsigned long int len = strlen(*str);
    unsigned long int i = 0;

    while((*str)[i] == ' ' || (*str)[i] == '\n') i++;

    printf("I IS : %lu\n", i);
    fflush(stdout);
    // str: "  dusan\0" -> len 7
    // i: 2
    // out: "dusan\0" len - i + 1 = 6
    // memcpy: to out, from str + i ('d'), size 6
    if (i > 0)
    {
        out_str = malloc(sizeof(**str) * (len - i + 1));
        if(out_str == NULL) return -1;
        memcpy(out_str, *str + i, len - i + 1);
    }
    else
    {
        return 0;
    }

    free(*str);
    *str = out_str;
    return i;
}
