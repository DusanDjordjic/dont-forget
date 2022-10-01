#ifndef _IO_H_
#define _IO_H_

char*   io_getstr(); // Reads from stdin until there is nothig more to be read
char*   io_getnstr(unsigned int n); // Reads n bytes from stdin and calls io_clear_buffer
void    io_clear_buffer(); // Reads and discards everything from stdin

#endif
