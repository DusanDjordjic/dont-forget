#include "io.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

void io_clear_buffer()
{
    while(getc(stdin) != '\n');
}

char* io_getnstr(unsigned int n)
{
    // Add + 1 because fgets reads one less char and adds '\0'
    char* buffer = malloc(sizeof(char) * (n + 1));
    fgets(buffer, n + 1, stdin);
    io_clear_buffer();
    unsigned long int len = strlen(buffer);
    if(buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';

    return buffer;

}

char* io_getstr()
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