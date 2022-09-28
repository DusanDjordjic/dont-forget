CFLAGS=-Iparsing_dates `pkg-config --cflags --libs libnotify`
BIN=main
SRC=main.c pd_parser.c
OBJS=main.o pd_parser.o
VPATH=parsing_dates
INCLUDE=parsing_dates/parsing_dates.h

.PHONY : all clean

all: $(OBJS) $(INCLUDE)
	gcc -o $(BIN) $(OBJS) $(CFLAGS)

%.o: %.c 
	gcc -c $^ $(CFLAGS)

run: $(BIN)
	./$(BIN)

clean: 
	rm -rf $(TARGET) **/*.o **/*.gch
