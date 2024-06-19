#Type make in the command line to compile the program

CC = cc
CFLAGS = -Wall -g

# List of source files
SRCS = main.c linked_list.c

# List of object files
OBJS = $(SRCS:.c=.o)

# Name of the executable
TARGET = todo_list

# Default target
all: $(TARGET)

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile .c files into .o files
%.o: %.c linked_list.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

