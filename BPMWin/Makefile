CFLAGS=  -O3  -std=gnu11  -I/usr/include/malloc/ 
LIBRARIES=-lm
CC=/s/parsons/l/sys/intel/bin/icc
LD=xild
AR=xiar
OBJS = BPMWin.o 
all: plain check

debug: CFLAGS =-DDEBUG -g -xCORE-AVX2 -Wall -Wextra -std=c99 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) BPMWin-wrapper.c -o BPMWin $(OBJS) $(CFLAGS) $(LIBRARIES)

check: $(OBJS)
	$(CC) BPMWin-wrapper.c -o BPMWin.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) BPMWin_verify.o
	$(CC) BPMWin-wrapper.c -o BPMWin.verify $(OBJS) BPMWin_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) BPMWin_verify.o
	$(CC) BPMWin-wrapper.c -o BPMWin.verify-rand $(OBJS) BPMWin_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

BPMWin.o : BPMWin.c
	$(CC) BPMWin.c -o BPMWin.o $(CFLAGS) $(LIBRARIES) -c

BPMWin_verify.o : BPMWin_verify.c
	$(CC) BPMWin_verify.c -o BPMWin_verify.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o BPMWin BPMWin.check BPMWin.verify BPMWin.verify-rand
