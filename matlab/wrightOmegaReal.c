/**
 * Santiago Akle 
 * ICME Stanford University 2014
 *
 * Computes the value \omega(z) defined as the solution y to
 * the equation y+log(y) = z ONLY FOR z real and z>=1.
 *
 * Loosely follows the recommendations by
 * PIERS W. LAWRENCE, ROBERT M. CORLESS, and DAVID J. JEFFREY. 
 * Published in:
 * Algorithm 917: Complex Double-Precision Evaluation of the Wright \omega Function
 * ACM Transactions on Mathematical Software (TOMS) TOMS Homepage table of contents archive
 * Volume 38 Issue 3, April 2012
 * Article No.	 20
 * Publication Date	2012-04-01 (yyyy-mm-dd)
 * Publisher	ACM New York, NY, USA
 * ISSN: 0098-3500 EISSN: 1557-7295 doi>10.1145/2168773.2168779
 */

#include "mex.h"
#include "wrightOmega.h"

/* THE mex-function */
void mexFunction( int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[] )  
{  
    pfloat *w;
    pfloat *z;
    idxint m,n,i,j;
    if(nlhs>1) mexErrMsgTxt("Too many output arguments!");
    if(nrhs!=1) mexErrMsgTxt("Wrong number of input arguments!");
    if((!mxIsDouble(prhs[0]))||(mxIsComplex(prhs[0]))) mexErrMsgTxt("Argument must be a real double matrix");
    m = mxGetM(prhs[0]);
    n = mxGetN(prhs[0]);
    
    plhs[0] = mxCreateDoubleMatrix(m,n,mxREAL);
    w = mxGetPr(plhs[0]);
    z = mxGetPr(prhs[0]);
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
                (*w) = wrightOmega(*z);    
                w++;
                z++;
        }
    }
}
