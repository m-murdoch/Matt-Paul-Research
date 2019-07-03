CFLAGS=  -O3  -std=c99  -I/usr/include/malloc/ 
LIBRARIES=-lm
CC=gcc
LD=xild
AR=xiar
OBJS = mco.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all

# Creates just mco, takes no input and produces no output
plain: $(OBJS)
	$(CC) mco-wrapper.c -o mco $(OBJS) $(CFLAGS) $(LIBRARIES)
	
# Same as plain but writes time to a file
timing: $(OBJS)
	$(CC) mco-wrapper.c -o mco.timing $(OBJS) $(CFLAGS) $(LIBRARIES) -DTIMING

# Inputs random values doesn't show output
rand: $(OBJS)
	$(CC) mco-wrapper.c -o mco.rand $(OBJS) $(CFLAGS) $(LIBRARIES) -DRANDOM

# Takes random inputs, writes time to file
timing-rand: $(OBJS)
	$(CC) mco-wrapper.c -o mco.timing-rand $(OBJS) $(CFLAGS) $(LIBRARIES) -DTIMING -DRANDOM 

# Takes user input, shows output
check: $(OBJS)
	$(CC) mco-wrapper.c -o mco.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

# Takes random input, shows output
check-rand: $(OBJS)
	$(CC)  mco-wrapper.c -o mco.check-rand $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING -DRANDOM

# No prompt on inputs, shows output
no_prompt: $(OBJS)
	$(CC)  mco-wrapper.c -o mco.no_prompt $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING -DNO_PROMPT 

# Compares output to that of mco_verify.c, takes input/shows output
verify: $(OBJS) mco_verify.o
	$(CC) mco-wrapper.c -o mco.verify $(OBJS) mco_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

# Same as verify but takes random values
verify-rand: $(OBJS) mco_verify.o
	$(CC) mco-wrapper.c -o mco.verify-rand $(OBJS) mco_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

# Same as verify but writes both times to files
verify-timing: $(OBJS) mco_verify.o
	$(CC)  mco-wrapper.c -o mco.verify-timing $(OBJS) mco_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DTIMING

# Combination of verify-rand and verify-timing
verify-rand-timing: $(OBJS) mco_verify.o
	$(CC)  mco-wrapper.c -o mco.verify-rand-timing $(OBJS) mco_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DTIMING -DRANDOM
	
# Unimplemented
papi: $(OBJS)
	$(CC)  mco-wrapper.c -o mco $(OBJS) $(CFLAGS) $(LIBRARIES) -DPAPI

# Used in most options, requires mco.c
mco.o : mco.c
	$(CC) mco.c -o mco.o $(CFLAGS) $(LIBRARIES) -c

# Used in verify options, requires mco_verify.c
mco_verify.o : mco_verify.c
	$(CC) mco_verify.c -o mco_verify.o $(CFLAGS) $(LIBRARIES) -c

# Cleans files made by this makefile
clean:
	rm -f *.o mco mco.timing mco.rand mco.timing-rand mco.check mco.check-rand mco.no_prompt mco.verify mco.verify-rand mco.verify-timing mco.verify-rand-timing

