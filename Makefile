CFLAGS=`pkg-config --cflags --libs libnotify`
BIN=main
SRC=main.c
OBJS=main.o
INCLUDE=

.PHONY : all clean

all: $(BIN)

%.o: %.c $(INCLUDE)
	gcc -o $@ $^ $(CFLAGS)

run: $(BIN)
	./$(BIN)

clean: 
	rm -rf $(TARGET) $(OBJS)
