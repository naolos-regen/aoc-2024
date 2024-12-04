# Compiler settings
CC = gcc               # You can use cc instead of gcc if you prefer
CFLAGS = -Wall -g      # Add debugging (-g) and warning options (-Wall)
LDFLAGS =              # Any flags for the linker, if needed

# Source files and headers
SRC = main.c read_file.c   # List of source files
OBJ = $(SRC:.c=.o)         # Corresponding object files (replace .c with .o)

# Output binary name
TARGET = ceres_search
