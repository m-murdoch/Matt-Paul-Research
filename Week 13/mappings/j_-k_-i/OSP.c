// This file is generated from test alphabets program by code generator in alphaz
// To compile this code, use -lm option for math library.

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <omp.h>
#include <immintrin.h>
#include <malloc.h>


// Common Macros
#define max(x, y)   ((x)>(y) ? (x) : (y))
#define MAX(x, y)	((x)>(y) ? (x) : (y))
#define min(x, y)   ((x)>(y) ? (y) : (x))
#define MIN(x, y)	((x)>(y) ? (y) : (x))
#define CEILD(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define ceild(n,d)  (int)ceil(((double)(n))/((double)(d)))
#define FLOORD(n,d) (int)floor(((double)(n))/((double)(d)))
#define floord(n,d) (int)floor(((double)(n))/((double)(d)))
#define CDIV(x,y)    CEILD((x),(y))
#define div(x,y)    CDIV((x),(y))
#define FDIV(x,y)    FLOORD((x),(y))
#define LB_SHIFT(b,s)  ((int)ceild(b,s) * s)
#define MOD(i,j)   ((i)%(j))
#define mallocCheck(v,s,d) if ((v) == NULL) { printf("Failed to allocate memory for %s : size=%lu\n", "sizeof(d)*(s)", sizeof(d)*(s)); exit(-1); }
// Reduction Operators
#define RADD(x,y)    ((x)+=(y))
#define RMUL(x,y)    ((x)*=(y))
#define RMAX(x,y)    ((x)=MAX((x),(y)))
#define RMIN(x,y)    ((x)=MIN((x),(y)))

// Common functions for min and max
//functions for integer max
inline int __max_int(int x, int y){
	return ((x)>(y) ? (x) : (y));
}

inline short __max_short(short x, short y){
	return ((x)>(y) ? (x) : (y));
}

inline long __max_long(long x, long y){
	return ((x)>(y) ? (x) : (y));
}

inline unsigned int __max_unsigned_int(unsigned int x, unsigned int y){
	return ((x)>(y) ? (x) : (y));
}

inline unsigned short __max_unsigned_short(unsigned short x, unsigned short y){
	return ((x)>(y) ? (x) : (y));
}

//function for float max
inline float __max_float(float x, float y){
	return ((x)>(y) ? (x) : (y));
}

//function for double max
inline double __max_double(double x, double y){
	return ((x)>(y) ? (x) : (y));
}

//function for integer min
inline int __min_int(int x, int y){
	return ((x)>(y) ? (y) : (x));
}

inline short __min_short(short x, short y){
	return ((x)>(y) ? (y) : (x));
}

inline long __min_long(long x, long y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned int __min_unsigned_int(unsigned int x, unsigned int y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned short __min_unsigned_short(unsigned short x, unsigned short y){
	return ((x)>(y) ? (y) : (x));
}

inline unsigned long __min_unsigned_long(unsigned long x, unsigned long y){
	return ((x)>(y) ? (y) : (x));
}

inline float __min_float(float x, float y){
	return ((x)>(y) ? (y) : (x));
}

inline double __min_double(double x, double y){
	return ((x)>(y) ? (y) : (x));
}







//Memory Macros
#define M(i) M[i]
#define Main(i,j) Main[i][j]
#define C(i,j) C[i][j]

void OSP(long N, int* M, int** C){
	///Parameter checking
	if (!((N >= 2))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Memory Allocation
	int mz1, mz2;
	
	int* _lin_Main = (int*)malloc(sizeof(int)*((N) * (N+1)));
	mallocCheck(_lin_Main, ((N) * (N+1)), int);
	int** Main = (int**)malloc(sizeof(int*)*(N));
	mallocCheck(Main, (N), int*);
	for (mz1=0;mz1 < N; mz1++) {
		Main[mz1] = &_lin_Main[(mz1*(N+1))];
	}
	#define S0(i,j,i2) C(i-j+1,i) = 0
	#define S1(i,j,i2) C(i-j+1,i) = Main(i-j+1,i)
	#define S3(i,j,i2) Main(-i2+N,i) = 2147483647
	#define S2(i,j,k) {int __temp__ = ((C(-k+N,i-j))+(C(i-j+1,i)))+(((M(-k+N-1))*(M(i-j)))*(M(i))); Main(-k+N,i) = __min_int(Main(-k+N,i),__temp__); }
	{
		//Domain
		//{i,j,i2|i+i2==N && j==1 && N>=2 && N>=i && i>=1}
		//{i,j,i2|i+i2==N+j-1 && j>=2 && N>=2 && i>=j && N>=i}
		//{i,j,i2|j==0 && N>=i2+1 && i+i2>=N+1 && N>=i && N>=2}
		//{i,j,k|i+k>=N+j && j>=1 && N>=2 && N+j>=i && k>=-1 && N>=k+1 && i>=0 && N>=i && i>=j && i+k>=N+1}
		int c1,c2,c3;
		S0((1),(1),(N-1));
		S3((2),(0),(N-1));
		S0((2),(1),(N-2));
		S2((2),(1),(N-1));
		S1((2),(2),(N-1));
		for(c1=3;c1 <= N;c1+=1)
		 {
		 	for(c3=-c1+N+1;c3 <= N-1;c3+=1)
		 	 {
		 	 	S3((c1),(0),(c3));
		 	 }
		 	S0((c1),(1),(-c1+N));
		 	for(c3=-c1+N+1;c3 <= N-1;c3+=1)
		 	 {
		 	 	S2((c1),(1),(c3));
		 	 }
		 	for(c2=2;c2 <= c1-1;c2+=1)
		 	 {
		 	 	S1((c1),(c2),(-c1+c2+N-1));
		 	 	for(c3=N-c1+c2;c3 <= N-1;c3+=1)
		 	 	 {
		 	 	 	S2((c1),(c2),(c3));
		 	 	 }
		 	 }
		 	S1((c1),(c1),(N-1));
		 }
	}
	#undef S0
	#undef S1
	#undef S3
	#undef S2
	
	//Memory Free
	free(_lin_Main);
	free(Main);
}

//Memory Macros
#undef M
#undef Main
#undef C


//Common Macro undefs
#undef max
#undef MAX
#undef min
#undef MIN
#undef CEILD
#undef ceild
#undef FLOORD
#undef floord
#undef CDIV
#undef FDIV
#undef LB_SHIFT
#undef MOD
#undef RADD
#undef RMUL
#undef RMAX
#undef RMIN
