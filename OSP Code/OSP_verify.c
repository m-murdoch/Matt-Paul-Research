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




///Global Variables
static int* M;
static int** C;
static char** _flag_C;


//Local Function Declarations
int reduce_OSP_C_1_verify(long, int, int);
int eval_C_verify(long, int, int);

//Memory Macros
#define M(i) M[i]
#define C(i,j) C[i][j]
#define _flag_C(i,j) _flag_C[i][j]

void OSP_verify(long N, int* _local_M, int** _local_C){
	///Parameter checking
	if (!((N >= 2))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Copy to global
	M = _local_M;
	C = _local_C;
	
	//Memory Allocation
	int mz1, mz2;
	
	char* _lin__flag_C = (char*)malloc(sizeof(char)*((N+1) * (N+1)));
	mallocCheck(_lin__flag_C, ((N+1) * (N+1)), char);
	_flag_C = (char**)malloc(sizeof(char*)*(N+1));
	mallocCheck(_flag_C, (N+1), char*);
	for (mz1=0;mz1 < N+1; mz1++) {
		_flag_C[mz1] = &_lin__flag_C[(mz1*(N+1))];
	}
	memset(_lin__flag_C, 'N', ((N+1) * (N+1)));
	#define S0(i,j) eval_C_verify(N,i,j)
	{
		//Domain
		//{i,j|N>=j && j>=i && i>=1 && N>=2}
		int c1,c2;
		for(c1=1;c1 <= N;c1+=1)
		 {
		 	for(c2=c1;c2 <= N;c2+=1)
		 	 {
		 	 	S0((c1),(c2));
		 	 }
		 }
	}
	#undef S0
	
	//Memory Free
	free(_lin__flag_C);
	free(_flag_C);
}
int reduce_OSP_C_1_verify(long N, int ip, int jp){
	int reduceVar = INT_MAX;
	#define S0(i,j,k) {int __temp__ = ((eval_C_verify(N,i,k))+(eval_C_verify(N,k+1,j)))+(((M(i-1))*(M(k)))*(M(j))); reduceVar = __min_int(reduceVar,__temp__); }
	{
		//Domain
		//{i,j,k|ip>=1 && jp>=ip+1 && N>=jp && N>=2 && k>=i && j>=k+1 && j>=i+1 && N>=k && N>=i-1 && i>=1 && j>=0 && N>=j && k>=0 && ip==i && jp==j}
		int c3;
		for(c3=ip;c3 <= jp-1;c3+=1)
		 {
		 	S0((ip),(jp),(c3));
		 }
	}
	#undef S0
	return reduceVar;
}
int eval_C_verify(long N, int i, int j){
	if ( _flag_C(i,j) == 'N' ) {
		_flag_C(i,j) = 'I';
	//Body for C
		C(i,j) = (((j == i))?0:(reduce_OSP_C_1_verify(N,i,j)));
		_flag_C(i,j) = 'F';
	} else if ( _flag_C(i,j) == 'I' ) {
		printf("There is a self dependence on C at (%d,%d) \n",i,j);
		exit(-1);
	}
	return C(i,j);
}

//Memory Macros
#undef M
#undef C
#undef _flag_C


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
