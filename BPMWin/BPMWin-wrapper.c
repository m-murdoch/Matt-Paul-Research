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
#include <time.h>
#include <sys/time.h>
#include <sys/errno.h>
#include <omp.h>
#ifdef PAPI
#include <papi.h>
#endif


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
#define EPSILON 1.0E-9







//Memory Macros
#define Diag(i,j,k) Diag[i][j][k]
#define X(i1,j1,i2,j2) X[i1][j1][i2][j2]

#define X_verify(i1,j1,i2,j2) X_verify[i1][j1][i2][j2]
#define var_X(i1,j1,i2,j2) X(i1,j1,i2,j2)
#define var_X_verify(i1,j1,i2,j2) X_verify(i1,j1,i2,j2)

//function prototypes
void BPMWin(long, long, long, int***, int****);
void BPMWin_verify(long, long, long, int***, int****);

//main
int main(int argc, char** argv) {
	//Check number of args
	if (argc <= 3) {
		printf("Number of argument is smaller than expected.\n");
		printf("Expecting N,M,W\n");
		exit(0);
	}
	
	char *end = 0;
	char *val = 0;
	//Read Parameters
	//Initialisation of N
	errno = 0;
	end = 0;
	val = argv[1];
	long N = strtol(val,&end,10);
	if ((errno == ERANGE && (N == LONG_MAX || N == LONG_MIN)) || (errno != 0 && N == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for N\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter N: Converted part: %ld, non-convertible part: %s\n", N, end);
		exit(EXIT_FAILURE);
	}
	
	//Initialisation of M
	errno = 0;
	end = 0;
	val = argv[2];
	long M = strtol(val,&end,10);
	if ((errno == ERANGE && (M == LONG_MAX || M == LONG_MIN)) || (errno != 0 && M == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for M\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter M: Converted part: %ld, non-convertible part: %s\n", M, end);
		exit(EXIT_FAILURE);
	}
	
	//Initialisation of W
	errno = 0;
	end = 0;
	val = argv[3];
	long W = strtol(val,&end,10);
	if ((errno == ERANGE && (W == LONG_MAX || W == LONG_MIN)) || (errno != 0 && W == 0)) {
		perror("strtol");
		exit(EXIT_FAILURE);
	}
	if (end == val) {
		fprintf(stderr, "No digits were found for W\n");
		exit(EXIT_FAILURE);
	}
	if (*end != '\0'){
		printf("For parameter W: Converted part: %ld, non-convertible part: %s\n", W, end);
		exit(EXIT_FAILURE);
	}
	
	
	///Parameter checking
	if (!((N >= 3 && M >= 3 && N >= W+1 && W >= 3 && M >= W+1))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	
	
	//Memory Allocation
	int mz1, mz2, mz3, mz4;
	int* _lin_Diag = (int*)malloc(sizeof(int)*((N+1) * (M+1) * (M+1)));
	mallocCheck(_lin_Diag, ((N+1) * (M+1) * (M+1)), int);
	int*** Diag = (int***)malloc(sizeof(int**)*(N+1));
	mallocCheck(Diag, (N+1), int**);
	for (mz1=0;mz1 < N+1; mz1++) {
		Diag[mz1] = (int**)malloc(sizeof(int*)*(M+1));
		mallocCheck(Diag[mz1], (M+1), int*);
		for (mz2=0;mz2 < M+1; mz2++) {
			Diag[mz1][mz2] = &_lin_Diag[(mz1*((M+1) * (M+1))) + (mz2*(M+1))];
		}
	}
	int* _lin_X = (int*)malloc(sizeof(int)*((N+1) * (N+1) * (M+1) * (M+1)));
	mallocCheck(_lin_X, ((N+1) * (N+1) * (M+1) * (M+1)), int);
	int**** X = (int****)malloc(sizeof(int***)*(N+1));
	mallocCheck(X, (N+1), int***);
	for (mz1=0;mz1 < N+1; mz1++) {
		X[mz1] = (int***)malloc(sizeof(int**)*(N+1));
		mallocCheck(X[mz1], (N+1), int**);
		for (mz2=0;mz2 < N+1; mz2++) {
			X[mz1][mz2] = (int**)malloc(sizeof(int*)*(M+1));
			mallocCheck(X[mz1][mz2], (M+1), int*);
			for (mz3=0;mz3 < M+1; mz3++) {
				X[mz1][mz2][mz3] = &_lin_X[(mz1*((N+1) * (M+1) * (M+1))) + (mz2*((M+1) * (M+1))) + (mz3*(M+1))];
			}
		}
	}
	#ifdef VERIFY
		int* _lin_X_verify = (int*)malloc(sizeof(int)*((N+1) * (N+1) * (M+1) * (M+1)));
		mallocCheck(_lin_X_verify, ((N+1) * (N+1) * (M+1) * (M+1)), int);
		int**** X_verify = (int****)malloc(sizeof(int***)*(N+1));
		mallocCheck(X_verify, (N+1), int***);
		for (mz1=0;mz1 < N+1; mz1++) {
			X_verify[mz1] = (int***)malloc(sizeof(int**)*(N+1));
			mallocCheck(X_verify[mz1], (N+1), int**);
			for (mz2=0;mz2 < N+1; mz2++) {
				X_verify[mz1][mz2] = (int**)malloc(sizeof(int*)*(M+1));
				mallocCheck(X_verify[mz1][mz2], (M+1), int*);
				for (mz3=0;mz3 < M+1; mz3++) {
					X_verify[mz1][mz2][mz3] = &_lin_X_verify[(mz1*((N+1) * (M+1) * (M+1))) + (mz2*((M+1) * (M+1))) + (mz3*(M+1))];
				}
			}
		}
	#endif

	//Initialization of rand
	srand((unsigned)time(NULL));
	 
	//Input Initialization
	{
		#if defined (RANDOM)
			#define S0(i,j,k) (Diag(i,j,k) = rand()%8); //fprintf(stderr, "%f\n",Diag(i,j,k)); 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(i,j,k) scanf("%d", &Diag(i,j,k))
			#else
				#define S0(i,j,k) printf("Diag(%ld,%ld,%ld)=",(long) i,(long) j,(long) k); scanf("%d", &Diag(i,j,k))
			#endif
		#else
			#define S0(i,j,k) (Diag(i,j,k) = 1)   //Default value
		#endif
		
		
		int c1,c2,c3;
		for(c1=0;c1 <= N;c1+=1)
		 {
		 	for(c2=0;c2 <= M;c2+=1)
		 	 {
		 	 	for(c3=c2;c3 <= min(M,c2+W);c3+=1)
		 	 	 {
		 	 	 	S0((c1),(c2),(c3));
		 	 	 }
		 	 }
		 }
		#undef S0
	}
	
	//exit(0);
	
	//Timing
	struct timeval time;
	double elapsed_time;
	
#ifdef PAPI
    int retval, EventSet = PAPI_NULL, native;
    long_long PAPIvalues[5];
    retval = PAPI_library_init(PAPI_VER_CURRENT);

    if (retval != PAPI_VER_CURRENT) {
      fprintf(stderr, "PAPI library init error!\n");
      exit(1);
    }

	int EventCode;
	char EventCodeStr[PAPI_MAX_STR_LEN];

  	EventCode = 0 | PAPI_NATIVE_MASK;
	  
	if (PAPI_create_eventset(&EventSet) != PAPI_OK)
		printf ("%s:%d\t ERROR\n", __FILE__, __LINE__);
	if (PAPI_add_event(EventSet, PAPI_TOT_INS) != PAPI_OK)
	    printf ("%s:%d\t ERROR\n", __FILE__, __LINE__);
	if (PAPI_add_event(EventSet, PAPI_L3_TCM) != PAPI_OK)
	    printf ("%s:%d\t ERROR\n", __FILE__, __LINE__);
	sprintf( EventCodeStr, "OFFCORE_RESPONSE_0:ANY_DATA:LLC_MISS_LOCAL_DRAM" ); 
	//sprintf( EventCodeStr, "OFFCORE_RESPONSE_1:ANY_REQUEST:L3_MISS" );   
    //sprintf( EventCodeStr, "OFFCORE_RESPONSE_0:DMND_DATA_RD:L3_MISS" );
	//sprintf( EventCodeStr, "OFFCORE_RESPONSE_0:DMND_RFO:L3_MISS" );
	
	//sprintf( EventCodeStr, "OFFCORE_RESPONSE_0:PF_LLC_RFO:L3_MISS" );
	if ((retval=PAPI_event_name_to_code(EventCodeStr, &native)) != PAPI_OK) {
	  printf("Event name to code failed: %d\n", retval);
	}
	if ((retval=PAPI_add_event(EventSet, native)) != PAPI_OK) {
	  printf("Event add failed: %d\n", retval);
	}
	
	sprintf( EventCodeStr, "OFFCORE_RESPONSE_1:ANY_RFO:LLC_MISS_LOCAL_DRAM" );
	//sprintf( EventCodeStr, "OFFCORE_RESPONSE_1:OTHER:L3_MISS" );
	//sprintf( EventCodeStr, "OFFCORE_RESPONSE_1:PF_DATA_RD:L3_MISS" );
	//sprintf( EventCodeStr, "OFFCORE_RESPONSE_1:PF_RFO:L3_MISS" );
	if ((retval=PAPI_event_name_to_code(EventCodeStr, &native)) != PAPI_OK) {
	  printf("Event name to code failed: %d\n", retval);
	}
	if ((retval=PAPI_add_event(EventSet, native)) != PAPI_OK) {
	  printf("Event add failed: %d\n", retval);
	}
#endif

	//Call the main computation
	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
	
	
#ifdef PAPI
////PAPI///////////////////////////////////////////////
/* Start counting */
  if (PAPI_start(EventSet) != PAPI_OK)
      printf ("%s:%d\t ERROR\n", __FILE__, __LINE__);
////PAPI END///////////////////////////////////////////////
#endif	
	BPMWin(N, M, W, Diag, X);
#ifdef PAPI
////PAPI///////////////////////////////////////////////
  if (PAPI_read(EventSet, PAPIvalues) != PAPI_OK)
      printf ("%s:%d\t ERROR\n", __FILE__, __LINE__);
  if (PAPI_stop(EventSet, PAPIvalues) != PAPI_OK)
      printf ("%s:%d\t ERROR\n", __FILE__, __LINE__);
#endif        
	gettimeofday(&time, NULL);
	elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;

	// timing information
	//printf("Execution time : %lf sec.\n", elapsed_time);
	
#ifdef PAPI
	printf("%ld\t%ld\t%ld\t%lf \t%lld \t%lld \t%lld \t%lld\n",N,M,W,elapsed_time,PAPIvalues[0],PAPIvalues[1],PAPIvalues[2],PAPIvalues[3]);
#else	
	printf("Execution time : %lf sec.\n", elapsed_time);
#endif	
	#ifdef TIMING
		FILE * fp = fopen( "trace.dat","a+");
		if (fp == NULL) {
				printf("I couldn't open trace.dat for writing.\n");
				exit(EXIT_FAILURE);
		}
		fprintf(fp, "%ld\t%ld\t%ld\t%lf\n",N,M,W,elapsed_time);
		fclose(fp);
	#endif
	
	//Verification Run
	#ifdef VERIFY
		#ifdef TIMING
			gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
		#endif
    	BPMWin_verify(N, M, W, Diag, X_verify);
    	#ifdef TIMING
    		gettimeofday(&time, NULL);
			elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
			
			FILE * fp_verify = fopen( "trace_verify.dat","a+");
			if (fp == NULL) {
					printf("I couldn't open trace_verify.dat for writing.\n");
					exit(EXIT_FAILURE);
			}
			fprintf(fp, "%ld\t%ld\t%ld\t%lf\n",N,M,W,elapsed_time);
			fclose(fp_verify);
		#endif
	#endif
    	
	#ifdef CHECKING
    	//Print Outputs
    	
		
		{
			#ifdef NO_PROMPT
				#define S0(i1,j1,i2,j2) printf("%d\n",var_X(i1,j1,i2,j2))
			#else
				#define S0(i1,j1,i2,j2) printf("X(%ld,%ld,%ld,%ld)=",(long) i1,(long) j1,(long) i2,(long) j2);printf("%d\n",var_X(i1,j1,i2,j2))
			#endif
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
			#undef S0
		}
		
	#elif VERIFY
		//Compare outputs for verification
		{
			//Error Counter
			int _errors_ = 0;
			#define S0(i1,j1,i2,j2) if (var_X_verify(i1,j1,i2,j2)!=var_X(i1,j1,i2,j2)) _errors_++;
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
			#undef S0
			if(_errors_ == 0){
				printf("TEST for X PASSED\n");
			}else{
				printf("TEST for X FAILED. #Errors: %d\n", _errors_);
			}
		}
    #endif
    
	//Memory Free
	free(_lin_Diag);
	for (mz1=0;mz1 < N+1; mz1++) {
		free(Diag[mz1]);
	}
	free(Diag);
	free(_lin_X);
	for (mz1=0;mz1 < N+1; mz1++) {
		for (mz2=0;mz2 < N+1; mz2++) {
			free(X[mz1][mz2]);
		}
		free(X[mz1]);
	}
	free(X);
	#ifdef VERIFY
		free(_lin_X_verify);
		for (mz1=0;mz1 < N+1; mz1++) {
			for (mz2=0;mz2 < N+1; mz2++) {
				free(X_verify[mz1][mz2]);
			}
			free(X_verify[mz1]);
		}
		free(X_verify);
	#endif
	
	return EXIT_SUCCESS;
}

//Memory Macros
#undef Diag
#undef X


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
#undef EPSILON
