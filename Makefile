CFLAGS=-Iparsing_dates -Iio -Itodos `pkg-config --cflags --libs libnotify`
BIN=main
SRC=main.c pd_parser.c io_read.c io_clear.c io_trim.c todos.c
OBJS=main.o pd_parser.o io_read.o io_clear.o io_trim.o todos.o
VPATH=parsing_dates io todos
INCLUDE=parsing_dates/parsing_dates.h io/io.h todos/todos.h

.PHONY : all run clean

all: $(OBJS) $(INCLUDE)
	gcc -o $(BIN) $(OBJS) $(CFLAGS)

%.o: %.c 
	gcc -c $^ $(CFLAGS)

run: $(BIN)
	./$(BIN)

clean: 
	rm -rf $(BIN) *.o **/*.o *.gch **/*.gch *core*
