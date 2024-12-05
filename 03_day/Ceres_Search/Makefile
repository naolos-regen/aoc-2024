# Compiler sett# Compiler settings
CC = gcc
CFLAGS = -Wall -g
LDFLAGS =

# Default source files and objects
SRC = main.c read_file.c
OBJ = $(SRC:.c=.o)

# Output binary name
TARGET = ceres_search

# Default target
all: $(TARGET)

# Rule for creating the binary
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# Rule for compiling .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Specific target for part_one
part_one: main.o read_file.o
	$(CC) main.o read_file.o -o ceres_part_one $(LDFLAGS)

# Specific target for part_two
part_two: part_two.o read_file.o
	$(CC) part_two.o read_file.o -o ceres_part_two $(LDFLAGS)

# Clean up build artifacts
clean:
	rm -f *.o ceres_search ceres_part_one ceres_part_two

# Phony targets
.PHONY: all clean part_one part_two
