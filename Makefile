CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

SRC = main.c unit_converter.c
TARGET = unit-converter
HEADERS = unit_converter.h

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.o

.PHONY: all clean



