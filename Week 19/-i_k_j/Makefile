CFLAGS= -fopenmp  -O3  -std=gnu11  -I/usr/include/malloc/ 
LIBRARIES=-lm
CC=/s/parsons/l/sys/intel/bin/icc
LD=xild
AR=xiar
OBJS = OSP.o 
OBJS_seq = OSP_seq.o
all: plain check timing-rand timing-rand-seq verify-rand verify-rand-seq

debug: CFLAGS =-DDEBUG -g -xCORE-AVX2 -Wall -Wextra -std=gnu11 -I/usr/include/malloc/
debug: all
		
plain: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP $(OBJS) $(CFLAGS) -fopenmp $(LIBRARIES)

timing-rand: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP.timing-rand $(OBJS) $(CFLAGS) -fopenmp $(LIBRARIES) -DTIMING -DRANDOM 

timing-rand-seq: $(OBJS_seq)
	$(CC) OSP-wrapper.c -o OSP.timing-rand-seq $(OBJS_seq) $(CFLAGS) $(LIBRARIES) -DTIMING -DRANDOM 

check: $(OBJS)
	$(CC) OSP-wrapper.c -o OSP.check $(OBJS) $(CFLAGS) -fopenmp $(LIBRARIES) -DCHECKING

verify: $(OBJS) OSP_verify.o
	$(CC) OSP-wrapper.c -o OSP.verify $(OBJS) OSP_verify.o $(CFLAGS) -fopenmp $(LIBRARIES) -DVERIFY

verify-rand: $(OBJS) OSP_verify.o
	$(CC) OSP-wrapper.c -o OSP.verify-rand $(OBJS) OSP_verify.o $(CFLAGS) -fopenmp $(LIBRARIES) -DVERIFY -DRANDOM

verify-rand-seq: $(OBJS_seq) OSP_verify_seq.o
	$(CC) OSP-wrapper.c -o OSP.verify-rand-seq $(OBJS_seq) OSP_verify_seq.o $(CFLAGS) $(LIBRARIES) -DVERIFY -DRANDOM

OSP.o : OSP.c
	$(CC) OSP.c -o OSP.o $(CFLAGS) -fopenmp $(LIBRARIES) -c

OSP_seq.o : OSP_seq.c
	$(CC) OSP_seq.c -o OSP_seq.o $(CFLAGS) $(LIBRARIES) -c

OSP_verify.o : OSP_verify.c
	$(CC) OSP_verify.c -o OSP_verify.o $(CFLAGS) -fopenmp $(LIBRARIES) -c

OSP_verify_seq.o : OSP_verify.c
	$(CC) OSP_verify.c -o OSP_verify_seq.o $(CFLAGS) $(LIBRARIES) -c

clean:
	rm -f *.o OSP OSP.check OSP.verify OSP.verify-rand OSP.verify-rand-seq OSP.timing-rand OSP.timing-rand-seq
