CFLAGS=  -O3  -std=c99  -I/usr/include/malloc/ 
LIBRARIES=-lm
CC=gcc
LD=xild
AR=xiar
OBJS = OSP.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all

# Creates just OSP, takes no input and produces no output
plain: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP $(OBJS) $(CFLAGS) $(LIBRARIES)
	
# Same as plain but writes time to a file
timing: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP.timing $(OBJS) $(CFLAGS) $(LIBRARIES) -DTIMING

# Inputs random values doesn't show output
rand: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP.rand $(OBJS) $(CFLAGS) $(LIBRARIES) -DRANDOM

# Takes random inputs, writes time to file
timing-rand: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP.timing-rand $(OBJS) $(CFLAGS) $(LIBRARIES) -DTIMING -DRANDOM 

# Takes user input, shows output
check: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

# Takes random input, shows output
check-rand: $(OBJS)
	$(CC)  OSP-wrapper.c -o OSP.check-rand $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING -DRANDOM

# No prompt on inputs, shows output
no_prompt: $(OBJS)
	$(CC)  OSP-wrapper.c -o OSP.no_prompt $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING -DNO_PROMPT 

# Compares output to that of OSP_verify.c, takes input/shows output
verify: $(OBJS) OSP_verify.o
	$(CC) OSP-wrapper.c -o OSP.verify $(OBJS) OSP_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

# Same as verify but takes random values
verify-rand: $(OBJS) OSP_verify.o
	$(CC) OSP-wrapper.c -o OSP.verify-rand $(OBJS) OSP_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

# Same as verify but writes both times to files
verify-timing: $(OBJS) OSP_verify.o
	$(CC)  OSP-wrapper.c -o OSP.verify-timing $(OBJS) OSP_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DTIMING

# Combination of verify-rand and verify-timing
verify-rand-timing: $(OBJS) OSP_verify.o
	$(CC)  OSP-wrapper.c -o OSP.verify-rand-timing $(OBJS) OSP_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DTIMING -DRANDOM
	
# Unimplemented
papi: $(OBJS)
	$(CC)  OSP-wrapper.c -o OSP $(OBJS) $(CFLAGS) $(LIBRARIES) -DPAPI

# Used in most options, requires OSP.c
OSP.o : OSP.c
	$(CC) OSP.c -o OSP.o $(CFLAGS) $(LIBRARIES) -c

# Used in verify options, requires OSP_verify.c
OSP_verify.o : OSP_verify.c
	$(CC) OSP_verify.c -o OSP_verify.o $(CFLAGS) $(LIBRARIES) -c

# Cleans files made by this makefile
clean:
	rm -f *.o OSP OSP.timing OSP.rand OSP.timing-rand OSP.check OSP.check-rand OSP.no_prompt OSP.verify OSP.verify-rand OSP.verify-timing OSP.verify-rand-timing
