CFLAGS=-Iparsing_dates -Iio `pkg-config --cflags --libs libnotify`
BIN=main
SRC=main.c pd_parser.c io.c
OBJS=main.o pd_parser.o io.o
VPATH=parsing_dates io
INCLUDE=parsing_dates/parsing_dates.h io/io.h

.PHONY : all clean

all: $(OBJS) $(INCLUDE)
	gcc -o $(BIN) $(OBJS) $(CFLAGS)

%.o: %.c 
	gcc -c $^ $(CFLAGS)

run: $(BIN)
	./$(BIN)

clean: 
	rm -rf $(TARGET) *.o **/*.o *.gch **/*.gch
