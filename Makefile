CC = gcc


CFLAGS = -Wall -Wextra -std=c11 -g


SRC = main.c converter.c currency.c


TARGET = unit-converter


HEADERS = converter.h currency.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
