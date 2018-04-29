CC = g++

DEVCFLAGS =  -ggdb -Wall -Wextra -Werror -Wpedantic

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

TARGET = caster

SOURCES = $(wildcard *.cpp)

OBJ = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJ)

	$(CC) $(DEVCFLAGS) -o $@.bin $(LDFLAGS)

clean:
	rm $(OBJ)
