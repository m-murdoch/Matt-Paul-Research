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
#define M(i) M[i]
#define C(i,j) C[i][j]

#define C_verify(i,j) C_verify[i][j]
#define var_C(i,j) C(i,j)
#define var_C_verify(i,j) C_verify(i,j)

//function prototypes
void OSP(long, int*, int**);
void OSP_verify(long, int*, int**);

//main
int main(int argc, char** argv) {
	//Check number of args
	if (argc <= 1) {
		printf("Number of argument is smaller than expected.\n");
		printf("Expecting N\n");
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
	
	
	///Parameter checking
	if (!((N >= 2))) {
		printf("The value of parameters are not valid.\n");
		exit(-1);
	}
	
	
	//Memory Allocation
	int mz1, mz2;
	int* M = (int*)malloc(sizeof(int)*(N+1));
	mallocCheck(M, (N+1), int);
	int* _lin_C = (int*)malloc(sizeof(int)*((N+1) * (N+1)));
	mallocCheck(_lin_C, ((N+1) * (N+1)), int);
	int** C = (int**)malloc(sizeof(int*)*(N+1));
	mallocCheck(C, (N+1), int*);
	for (mz1=0;mz1 < N+1; mz1++) {
		C[mz1] = &_lin_C[(mz1*(N+1))];
	}
	#ifdef VERIFY
		int* _lin_C_verify = (int*)malloc(sizeof(int)*((N+1) * (N+1)));
		mallocCheck(_lin_C_verify, ((N+1) * (N+1)), int);
		int** C_verify = (int**)malloc(sizeof(int*)*(N+1));
		mallocCheck(C_verify, (N+1), int*);
		for (mz1=0;mz1 < N+1; mz1++) {
			C_verify[mz1] = &_lin_C_verify[(mz1*(N+1))];
		}
	#endif

	//Initialization of rand
	srand((unsigned)time(NULL));
	 
	//Input Initialization
	{
		#if defined (RANDOM)
			#define S0(i) (M(i) = rand()%8); //fprintf(stderr, "%f\n",M(i)); 
		#elif defined (CHECKING) || defined (VERIFY)
			#ifdef NO_PROMPT
				#define S0(i) scanf("%d", &M(i))
			#else
				#define S0(i) printf("M(%ld)=",(long) i); scanf("%d", &M(i))
			#endif
		#else
			#define S0(i) (M(i) = 1)   //Default value
		#endif
		
		
		int c1;
		for(c1=0;c1 <= N;c1+=1)
		 {
		 	S0((c1));
		 }
		#undef S0
	}
	
	//exit(0);
	
	//Timing
	clock_t start_time, end_time;
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
	start_time = clock();
	//gettimeofday(&time, NULL);
	//elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
	
	
#ifdef PAPI
////PAPI///////////////////////////////////////////////
/* Start counting */
  if (PAPI_start(EventSet) != PAPI_OK)
      printf ("%s:%d\t ERROR\n", __FILE__, __LINE__);
////PAPI END///////////////////////////////////////////////
#endif	
	OSP(N, M, C);
#ifdef PAPI
////PAPI///////////////////////////////////////////////
  if (PAPI_read(EventSet, PAPIvalues) != PAPI_OK)
      printf ("%s:%d\t ERROR\n", __FILE__, __LINE__);
  if (PAPI_stop(EventSet, PAPIvalues) != PAPI_OK)
      printf ("%s:%d\t ERROR\n", __FILE__, __LINE__);
#endif
	end_time = clock();
	elapsed_time = ((double) end_time-start_time) / CLOCKS_PER_SEC;
	
	//gettimeofday(&time, NULL);
	//elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;

	// timing information
	//printf("Execution time : %lf sec.\n", elapsed_time);
	
#ifdef PAPI
	printf("%ld\t%lf \t%lld \t%lld \t%lld \t%lld\n",N,elapsed_time,PAPIvalues[0],PAPIvalues[1],PAPIvalues[2],PAPIvalues[3]);
#else	
	printf("Execution time : %lf sec.\n", elapsed_time);
#endif	
	#ifdef TIMING
		FILE * fp = fopen( "timing.csv","a+");
		if (fp == NULL) {
				printf("I couldn't open timing.csv for writing.\n");
				exit(EXIT_FAILURE);
		}
		fprintf(fp, "%ld,%lf\n",N,elapsed_time);
		fclose(fp);
	#endif
	
	//Verification Run
	#ifdef VERIFY
		#ifdef TIMING
			start_time = clock();
			//gettimeofday(&time, NULL);
			//elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000);
		#endif
    	OSP_verify(N, M, C_verify);
    	#ifdef TIMING
    		end_time = clock();
			elapsed_time = ((double) end_time-start_time) / CLOCKS_PER_SEC;
			
			//gettimeofday(&time, NULL);
			//elapsed_time = (((double) time.tv_sec) + ((double) time.tv_usec)/1000000) - elapsed_time;
			
			FILE * fp_verify = fopen( "timing_verify.csv","a+");
			if (fp == NULL) {
					printf("I couldn't open timing_verify.csv for writing.\n");
					exit(EXIT_FAILURE);
			}
			fprintf(fp, "%ld,%lf\n",N,elapsed_time);
			fclose(fp_verify);
		#endif
	#endif
    	
	#ifdef CHECKING
    	//Print Outputs
    	
		
		{
			#ifdef NO_PROMPT
				#define S0(i,j) printf("%d\n",var_C(i,j))
			#else
				#define S0(i,j) printf("C(%ld,%ld)=",(long) i,(long) j);printf("%d\n",var_C(i,j))
			#endif
			int c1,c2;
			for(c1=1;c1 <= N;c1+=1)
			 {
			 	for(c2=c1;c2 <= N;c2+=1)
			 	 {
			 	 	S0((c1),(c2));
			 	 }
			 }
			#undef S0
		}
		
	#elif VERIFY
		//Compare outputs for verification
		{
			//Error Counter
			int _errors_ = 0;
			#define S0(i,j) if (var_C_verify(i,j)!=var_C(i,j)) _errors_++;
			int c1,c2;
			for(c1=1;c1 <= N;c1+=1)
			 {
			 	for(c2=c1;c2 <= N;c2+=1)
			 	 {
			 	 	S0((c1),(c2));
			 	 }
			 }
			#undef S0
			if(_errors_ == 0){
				printf("TEST for C PASSED\n");
			}else{
				printf("TEST for C FAILED. #Errors: %d\n", _errors_);
			}
		}
    #endif
    
	//Memory Free
	free(M);
	free(_lin_C);
	free(C);
	#ifdef VERIFY
		free(_lin_C_verify);
		free(C_verify);
	#endif
	
	return EXIT_SUCCESS;
}

//Memory Macros
#undef M
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
#undef EPSILON