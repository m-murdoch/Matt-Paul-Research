CFLAGS= -fopenmp  -O3  -std=gnu11  -I/usr/include/malloc/ 
LIBRARIES=-lm
CC=/s/parsons/l/sys/intel/bin/icc
LD=xild
AR=xiar
OBJS = OSP.o 
OBJS_seq = OSP_seq.o
all: plain check timing-rand verify-rand

debug: CFLAGS =-DDEBUG -g -fopenmp -xCORE-AVX2 -Wall -Wextra -std=gnu11 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP $(OBJS) $(CFLAGS)  $(LIBRARIES)

timing-rand: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP.timing-rand $(OBJS) $(CFLAGS)  $(LIBRARIES) -DTIMING -DRANDOM 

check: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP.check $(OBJS) $(CFLAGS) $(LIBRARIES) -DCHECKING

verify: $(OBJS) OSP_verify.o
	$(CC) OSP-wrapper.c -o OSP.verify $(OBJS) OSP_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) OSP_verify.o
	$(CC) OSP-wrapper.c -o OSP.verify-rand $(OBJS) OSP_verify.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM
	
OSP.o : OSP.c
	$(CC) OSP.c -o OSP.o $(CFLAGS) $(LIBRARIES) -c

OSP_verify.o : OSP_verify.c
	$(CC) OSP_verify.c -o OSP_verify.o $(CFLAGS) $(LIBRARIES) -c
clean:
	rm -f *.o OSP OSP.check OSP.verify OSP.verify-rand OSP.timing-rand 
