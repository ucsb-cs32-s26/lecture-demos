CC      = gcc
TARGET  = main

all: $(TARGET)

# ---------- Preprocessing ----------
main.i: main.c func.h
	$(CC) -E -P main.c -o main.i

func.i: func.c func.h
	$(CC) -E -P func.c -o func.i

# ---------- Compilation ----------
main.s: main.i
	$(CC) $(CFLAGS) -S main.i -o main.s

func.s: func.i
	$(CC) $(CFLAGS) -S func.i -o func.s

# ---------- Assembly ----------
main.o: main.s
	$(CC) -c main.s -o main.o

func.o: func.s
	$(CC) -c func.s -o func.o

# ---------- Linking ----------
$(TARGET): main.o func.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o func.o

# ---------- Cleanup ----------
clean:
	rm -f *.i *.s *.o $(TARGET)