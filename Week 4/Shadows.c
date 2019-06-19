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
static float* A;
static float T;
static bool* S;
static char* _flag_S;


//Local Function Declarations
bool reduce_Shadows_S_1(long, int);
bool eval_S(long, int);

//Memory Macros
#define A(i) A[i]
#define S(i) S[i]
#define _flag_S(i) _flag_S[i]

void Shadows(long N, float* _local_A, float* _local_T, bool* _local_S){
	///Parameter checking
	if (!((N >= 1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	//Copy to global
	A = _local_A;
	
	T = *_local_T;
	S = _local_S;
	
	//Memory Allocation
	int mz1;
	
	_flag_S = (char*)malloc(sizeof(char)*(N));
	mallocCheck(_flag_S, (N), char);
	memset(_flag_S, 'N', (N));
	#define S0(i) eval_S(N,i)
	{
		//Domain
		//{i|i>=0 && N>=i+1 && N>=1}
		int c1;
		for(c1=0;c1 <= N-1;c1+=1)
		 {
		 	S0((c1));
		 }
	}
	#undef S0
	
	//Memory Free
	free(_flag_S);
}
bool reduce_Shadows_S_1(long N, int ip){
	bool reduceVar = 1;
	#define S0(i,j) reduceVar = (reduceVar)&&((A(j))<=((A(i))+(((i)-(j))*(T))))
	{
		//Domain
		//{i,j|ip>=1 && N>=ip+1 && N>=1 && i>=j+1 && i>=1 && j>=0 && N>=j+1 && N>=i+1 && ip==i}
		int c2;
		for(c2=0;c2 <= ip-1;c2+=1)
		 {
		 	S0((ip),(c2));
		 }
	}
	#undef S0
	return reduceVar;
}
bool eval_S(long N, int i){
	if ( _flag_S(i) == 'N' ) {
		_flag_S(i) = 'I';
	//Body for S
		S(i) = (((i == 0))?1:(reduce_Shadows_S_1(N,i)));
		_flag_S(i) = 'F';
	} else if ( _flag_S(i) == 'I' ) {
		printf("There is a self dependence on S at (%d) \n",i);
		exit(-1);
	}
	return S(i);
}

//Memory Macros
#undef A
#undef S
#undef _flag_S


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
