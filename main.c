#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_rng.h>

/*
 * Calculate Pi based on a MC Approach
 */
double calcPI(long int numTrials,unsigned long int myseed)
{
    long int i, numAccepted=0;
    double x,y;

    gsl_rng *r;
    const gsl_rng_type * T;

    gsl_rng_env_setup();
    T = gsl_rng_default;

    gsl_rng_default = gsl_rng_mt19937;
    gsl_rng_default_seed = myseed;

    r = gsl_rng_alloc (T);

    /* gsl_rng_set(r); */

    printf("\n    Generator type:'%s'\n",gsl_rng_name(r));
    printf("    Seed:'%lu'\n", gsl_rng_default_seed);
    printf("    First Value:'%lu'\n", gsl_rng_get(r));
  
    for(i=1; i<=numTrials; i++)
    { 
        x = gsl_rng_uniform(r);
        y = gsl_rng_uniform(r);
 
        if(x*x + y*y <=1.0)
           numAccepted += 1;    
    }
    printf("\n    #Accepted:%ld\n", numAccepted);
    printf("    # Trials :%ld\n", numTrials);
    return (4.0*numAccepted)/numTrials;
}


/* 
    GSL_RNG_TYPE
    GSL_RNG_SEED
*/

int main(int argc, char **argv)
{
    long int numTrials; 
    long int seed=0;
    char fileName[256];
    FILE *fp; 
    double pi;
  
    if((argc<3) || (argc>4))
    {
       printf("  SYNTAX: EXE #Trials Filename <Seed=0>\n");
       return (EXIT_FAILURE);
    }

    numTrials = atol(argv[1]);
    if(numTrials<=1)
    {
       printf(" Invalid #trials:%ld\n", numTrials);
       return (EXIT_FAILURE);
    } 
    strcpy(fileName,argv[2]);

    if(argc==4)
       seed = atol(argv[3]); 



    /* Calc. PI */
    pi = calcPI(numTrials,(unsigned long int)seed);
    printf("\n    =>Pi (Estimate):%16.14lf\n",pi);
    printf("    Pi (EXACT):     %16.14lf\n", 4.0*atan(1.0));


    /* Write result in file */
    fp = fopen(fileName,"w");
    if(fp==NULL)
    {
       printf("    File '%s' can not be opened\n",fileName);
       return (EXIT_FAILURE);
    }
    else 
    {
       printf("    Results to be stored in:'%s'\n",fileName);
       fprintf(fp,"%20.16lf",pi); 
       fclose(fp);
    }

    return 0;
}   
