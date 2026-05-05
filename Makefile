# Compiler settings
CC = gcc
CFLAGS = -I./include
LDFLAGS = -L./lib -lraylib -lm -lpthread -ldl -lrt -lX11

# The output binary name
TARGET = build/main

# The source file
SRC = main.c

# The default rule
default: $(TARGET)
$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LDFLAGS) 

# run the program
run: $(TARGET)
	./$(TARGET)

# Cleanup
clean:
	rm -f $(TARGET)
