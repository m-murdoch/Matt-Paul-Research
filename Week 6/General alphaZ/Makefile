CFLAGS=  -O3  -std=c99  -I/usr/include/malloc/ 
LIBRARIES=-lm
CC=gcc
LD=xild
AR=xiar
OBJS = Shadows.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all

# Creates just Shadows, takes no input and produces no output
plain: $(OBJS)
	$(CC) Shadows-wrapper.c -o Shadows $(OBJS) $(CFLAGS) $(LIBRARIES)
	
# Same as plain but writes time to a file
timing: $(OBJS)
	$(CC) Shadows-wrapper.c -o Shadows.timing $(OBJS) $(CFLAGS) $(LIBRARIES) -DTIMING

# Inputs random values doesn't show output
rand: $(OBJS)
	$(CC) Shadows-wrapper.c -o Shadows.rand $(OBJS) $(CFLAGS) $(LIBRARIES) -DRANDOM

# Takes random inputs, writes time to file
timing-rand: $(OBJS)
	$(CC) Shadows-wrapper.c -o Shadows.timing-rand $(OBJS) $(CFLAGS) $(LIBRARIES) -DTIMING -DRANDOM 

# Takes user input, shows output
check: $(OBJS)
	$(CC) Shadows-wrapper.c -o Shadows.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

# Takes random input, shows output
check-rand: $(OBJS)
	$(CC)  Shadows-wrapper.c -o Shadows.check-rand $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING -DRANDOM

# No prompt on inputs, shows output
no_prompt: $(OBJS)
	$(CC)  Shadows-wrapper.c -o Shadows.no_prompt $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING -DNO_PROMPT 

# Compares output to that of shadows_verify.c, takes input/shows output
verify: $(OBJS) Shadows_verify.o
	$(CC) Shadows-wrapper.c -o Shadows.verify $(OBJS) Shadows_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

# Same as verify but takes random values
verify-rand: $(OBJS) Shadows_verify.o
	$(CC) Shadows-wrapper.c -o Shadows.verify-rand $(OBJS) Shadows_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

# Same as verify but writes both times to files
verify-timing: $(OBJS) Shadows_verify.o
	$(CC)  Shadows-wrapper.c -o Shadows.verify-timing $(OBJS) Shadows_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DTIMING

# Combination of verify-rand and verify-timing
verify-rand-timing: $(OBJS) Shadows_verify.o
	$(CC)  Shadows-wrapper.c -o Shadows.verify-rand-timing $(OBJS) Shadows_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DTIMING -DRANDOM
	
# Unimplemented
papi: $(OBJS)
	$(CC)  Shadows-wrapper.c -o Shadows $(OBJS) $(CFLAGS) $(LIBRARIES) -DPAPI

# Used in most options, requires Shadows.c
Shadows.o : Shadows.c
	$(CC) Shadows.c -o Shadows.o $(CFLAGS) $(LIBRARIES) -c

# Used in verify options, requires Shadows_verify.c
Shadows_verify.o : Shadows_verify.c
	$(CC) Shadows_verify.c -o Shadows_verify.o $(CFLAGS) $(LIBRARIES) -c

# Cleans files made by this makefile
clean:
	rm -f *.o Shadows Shadows.timing Shadows.rand Shadows.timing-rand Shadows.check Shadows.check-rand Shadows.no_prompt Shadows.verify Shadows.verify-rand Shadows.verify-timing Shadows.verify-rand-timing
