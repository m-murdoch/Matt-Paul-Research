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
static int*** Diag;
static int**** X;
static char**** _flag_X;


//Local Function Declarations
int reduce_BPMWin_X_1(long, long, long, int, int, int, int);
int eval_X(long, long, long, int, int, int, int);

//Memory Macros
#define Diag(i,j,k) Diag[i][j][k]
#define X(i1,j1,i2,j2) X[i1][j1][i2][j2]
#define _flag_X(i1,j1,i2,j2) _flag_X[i1][j1][i2][j2]

void BPMWin(long N, long M, long W, int*** _local_Diag, int**** _local_X){
	///Parameter checking
	if (!((N >= 3 && M >= 3 && N >= W+1 && W >= 3 && M >= W+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Copy to global
	Diag = _local_Diag;
	X = _local_X;
	
	//Memory Allocation
	int mz1, mz2, mz3, mz4;
	
	char* _lin__flag_X = (char*)malloc(sizeof(char)*((N+1) * (N+1) * (M+1) * (M+1)));
	mallocCheck(_lin__flag_X, ((N+1) * (N+1) * (M+1) * (M+1)), char);
	_flag_X = (char****)malloc(sizeof(char***)*(N+1));
	mallocCheck(_flag_X, (N+1), char***);
	for (mz1=0;mz1 < N+1; mz1++) {
		_flag_X[mz1] = (char***)malloc(sizeof(char**)*(N+1));
		mallocCheck(_flag_X[mz1], (N+1), char**);
		for (mz2=0;mz2 < N+1; mz2++) {
			_flag_X[mz1][mz2] = (char**)malloc(sizeof(char*)*(M+1));
			mallocCheck(_flag_X[mz1][mz2], (M+1), char*);
			for (mz3=0;mz3 < M+1; mz3++) {
				_flag_X[mz1][mz2][mz3] = &_lin__flag_X[(mz1*((N+1) * (M+1) * (M+1))) + (mz2*((M+1) * (M+1))) + (mz3*(M+1))];
			}
		}
	}
	memset(_lin__flag_X, 'N', ((N+1) * (N+1) * (M+1) * (M+1)));
	#define S0(i1,j1,i2,j2) eval_X(N,M,W,i1,j1,i2,j2)
	{
		//Domain
		//{i1,j1,i2,j2|W+i1>=j1 && j1>=i1 && N>=j1 && i1>=0 && W+i2>=j2 && j2>=i2 && M>=j2 && i2>=0 && N>=3 && M>=3 && N>=W+1 && W>=3 && M>=W+1}
		int c1,c2,c3,c4;
		for(c1=0;c1 <= N;c1+=1)
		 {
		 	for(c2=c1;c2 <= min(N,c1+W);c2+=1)
		 	 {
		 	 	for(c3=0;c3 <= M;c3+=1)
		 	 	 {
		 	 	 	for(c4=c3;c4 <= min(M,c3+W);c4+=1)
		 	 	 	 {
		 	 	 	 	S0((c1),(c2),(c3),(c4));
		 	 	 	 }
		 	 	 }
		 	 }
		 }
	}
	#undef S0
	
	//Memory Free
	free(_lin__flag_X);
	for (mz1=0;mz1 < N+1; mz1++) {
		for (mz2=0;mz2 < N+1; mz2++) {
			free(_flag_X[mz1][mz2]);
		}
		free(_flag_X[mz1]);
	}
	free(_flag_X);
}
int reduce_BPMWin_X_1(long N, long M, long W, int i1p, int j1p, int i2p, int j2p){
	int reduceVar = INT_MIN;
	#define S0(i1,j1,i2,j2,k1,k2) {int __temp__ = (eval_X(N,M,W,i1,k1,i2,k2))+(eval_X(N,M,W,k1+1,j1,k2+1,j2)); reduceVar = __max_int(reduceVar,__temp__); }
	{
		//Domain
		//{i1,j1,i2,j2,k1,k2|j1p>=i1p+1 && W>=3 && 2W+i1p>=j1p-1 && i1p>=0 && 2W+i2p>=j2p-1 && M>=W+1 && j2p>=i2p+1 && i2p>=0 && N>=j1p && M>=j2p && N>=W+1 && N>=3 && M>=3 && W+i1p>=j1p && W+i2p>=j2p && W+i1>=k1 && k1>=i1 && N>=k1 && i1>=0 && W+i2>=k2 && k2>=i2 && M>=k2 && i2>=0 && j2>=i2+1 && 2W+i2>=j2-1 && W+i1>=j1 && 2W+i1>=j1-1 && W+i2>=j2 && W+k1>=j1-1 && j1>=k1+1 && N>=j1 && k1>=-1 && W+k2>=j2-1 && j2>=k2+1 && M>=j2 && k2>=-1 && j1>=i1+1 && i1p==i1 && j1p==j1 && i2p==i2 && j2p==j2}
		int c5,c6;
		for(c5=i1p;c5 <= j1p-1;c5+=1)
		 {
		 	for(c6=i2p;c6 <= j2p-1;c6+=1)
		 	 {
		 	 	S0((i1p),(j1p),(i2p),(j2p),(c5),(c6));
		 	 }
		 }
	}
	#undef S0
	return reduceVar;
}
int eval_X(long N, long M, long W, int i1, int j1, int i2, int j2){
	if ( _flag_X(i1,j1,i2,j2) == 'N' ) {
		_flag_X(i1,j1,i2,j2) = 'I';
	//Body for X
		X(i1,j1,i2,j2) = (((j1 == i1))?Diag(i1,i2,j2):(((j2 == i2 && j1 >= i1+1))?0:(reduce_BPMWin_X_1(N,M,W,i1,j1,i2,j2))));
		_flag_X(i1,j1,i2,j2) = 'F';
	} else if ( _flag_X(i1,j1,i2,j2) == 'I' ) {
		printf("There is a self dependence on X at (%d,%d,%d,%d) \n",i1,j1,i2,j2);
		exit(-1);
	}
	return X(i1,j1,i2,j2);
}

//Memory Macros
#undef Diag
#undef X
#undef _flag_X


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
