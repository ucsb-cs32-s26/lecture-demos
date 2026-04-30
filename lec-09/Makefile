CC     = gcc
CFLAGS = -std=c99 -Wall -Wextra

# -Wall (Warn All): Despite the name, it doesn't actually enable every warning, but it covers the most common ones. It catches things like:
#     Using a variable before initializing it.
#     Functions that don't return a value when they should.
#     Missing braces in if statements.

# -Wextra: This enables even more warning flags that -Wall misses. It catches things like:
#     Comparing an unsigned integer to a signed integer.
#     Unused function parameters (like having argc in main but never using it).
#     "Empty" loop bodies that might be a typo.

# Most professional C developers aim for "Zero Warnings". 
# If your code compiles with -Wall -Wextra and stays silent, you’ve eliminated about 
# 80% of the mistakes that cause segmentation faults later.

BINS = 01_hello 02_io 03_strings 04_structs \
       05_malloc 06_memops 07_fileio 08_cmdargs

all: $(BINS)

01_hello: 01_hello.c
	$(CC) $(CFLAGS) -o $@ $<
# $@: Refers to the Target (the thing on the left of the colon).
# $<: Refers to the First Dependency (the thing on the right of the colon).

02_io: 02_io.c
	$(CC) $(CFLAGS) -o $@ $<

03_strings: 03_strings.c
	$(CC) $(CFLAGS) -o $@ $<

04_structs: 04_structs.c
	$(CC) $(CFLAGS) -o $@ $<

05_malloc: 05_malloc.c
	$(CC) $(CFLAGS) -o $@ $<

06_memops: 06_memops.c
	$(CC) $(CFLAGS) -o $@ $<

07_fileio: 07_fileio.c
	$(CC) $(CFLAGS) -o $@ $<

08_cmdargs: 08_cmdargs.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(BINS) data.txt nums.bin

.PHONY: all clean
# By adding .PHONY: clean, you are telling make: "Hey, even if a file named 'clean' 
# exists, ignore it. Always run the instructions under this target when I call it."