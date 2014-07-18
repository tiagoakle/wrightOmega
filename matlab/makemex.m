%Compile the mex file and link
%TODO: add support for pc and linux:

mex -c ../src/wrightOmega.c -I../include
mex -c ../matlab/wrightOmegaReal.c -I../include
if(ismac)
    mex  -largeArrayDims -lm wrightOmega.o wrightOmegaReal.o -output "wrightOmegaReal"
elseif(isunix)
    mex -largeArrayDims -lm -lrt wrightOmega.o wrightOmegaReal.o -output "wrightOmegaReal"
else
    disp('Platform not supported\n');
end

