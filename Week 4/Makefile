CFLAGS= -O3  -std=c99  -I/usr/include/malloc/
LIBRARIES=-lm
CC?=gcc
OBJS = Shadows.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) Shadows-wrapper.c -o Shadows $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) Shadows-wrapper.c -o Shadows.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) Shadows_verify.o
	$(CC) Shadows-wrapper.c -o Shadows.verify $(OBJS) Shadows_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) Shadows_verify.o
	$(CC) Shadows-wrapper.c -o Shadows.verify-rand $(OBJS) Shadows_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

Shadows.o : Shadows.c
	$(CC) Shadows.c -o Shadows.o $(CFLAGS) $(LIBRARIES) -c

Shadows_verify.o : Shadows_verify.c
	$(CC) Shadows_verify.c -o Shadows_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o Shadows Shadows.check Shadows.verify Shadows.verify-rand
