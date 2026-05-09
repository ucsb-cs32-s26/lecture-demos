CC      = gcc
TARGET  = hello

all: $(TARGET)

# Preprocessing: .c -> .i
hello.i: hello.c
	$(CC) -E -P hello.c -o hello.i

# Compilation: .i -> .s
hello.s: hello.i
	$(CC) $(CFLAGS) -S hello.i -o hello.s

# Assembly: .s -> .o
hello.o: hello.s
	$(CC) -c hello.s -o hello.o

# Linking: .o -> executable
$(TARGET): hello.o
	$(CC) hello.o -o $(TARGET)

clean:
	rm -f hello.i hello.s hello.o $(TARGET)