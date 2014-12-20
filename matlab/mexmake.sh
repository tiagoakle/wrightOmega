
/Applications/MATLAB_R2011b.app/bin/mex -c ../src/wrightOmega.c -I../include
/Applications/MATLAB_R2011b.app/bin/mex -c ../matlab/wrightOmegaReal.c -I../include
/Applications/MATLAB_R2011b.app/bin/mex  -largeArrayDims -lm wrightOmega.o wrightOmegaReal.o -output "wrightOmegaReal"

