##
# Project Title
#
# @file
# @version 0.1

# Include the config.mk file
include config.mk

# Default target
all: $(TARGET)

# Rule for creating the binary
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Rule for compiling .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(TARGET)

# Phony targets (these aren't actual files, just commands)
.PHONY: all clean

# end
