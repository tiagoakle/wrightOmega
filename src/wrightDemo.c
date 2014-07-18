#include "math.h"
#include "wrightOmega.h"
#include <stdio.h>
/**
 * Santiago Akle 
 * ICME Stanford University 2014
 *
 * Exemplifies the use of wrightOmega 
 *
 * */
int main(void)
{   
    pfloat r = 0.0;
    pfloat z = 1.0;
    pfloat w = 0.0;
    pfloat maxerr = 0.0;
    pfloat maxeval = 0.0;

    int i    = 0;
    for(i=0;i<10000000;i++)
    {
        z = z+0.01;
        w = wrightOmega(z);
        r = w+log(w)-z;
        r = r<0.0? -r:r; //abs r
        if(r>maxerr)
        {
            maxerr = r;
            maxeval = w;
        }
    }
    printf("Largerst error %e achieved at %e\n",maxerr,maxeval);
}
