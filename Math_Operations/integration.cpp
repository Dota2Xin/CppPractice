#include "mathLocal.h"
/*
Inputs:
Integrates an arbitrary multidimensional function over predetermined numerical bounds in your variables
boundaries=Array of floats, every two entries corresponds the start and end for the variables that are being integrated over
i.e. [1.0,3.0,4.0,5.0] indicates x1 goes from 1.0 to 3.0 and x2 goes from 4.0 to 5.0
f=Function to be integrated, it has to take its input parameters as an array of floats
resolutions= Array of resolutions for a given parameter
i.e. [100,200,50] means x1 gets integrated in 100 steps, x2 gets integrated in 200 steps, x3 gets integrated in 50 steps
*/
float integral(float* boundaries, float (*f)(float* arguments), int* resolutions, int resolutionLength) {
    int totalSize=1;
    for(int i=0; i<resolutionLength; i++) {
        totalSize *=resolutions[i];
    }
    float totalSum=0;
    float* currentArguments=new float[resolutionLength];
    float dxN=1;
    float* dxi= new float[resolutionLength];
    for(int i=0; i<resolutionLength; i++) {
        dxi[i]=(boundaries[2*i+1]-boundaries[2*i])/resolutions[i];
        dxN *= (boundaries[2*i+1]-boundaries[2*i])/resolutions[i];
    }

    for(int i=0; i<totalSize; i++) {
        for(int j=0; j<resolutionLength; j++) {
            int currentIndex=i;
            for(int k=j+1; k<resolutionLength; k++) {
                currentIndex=currentIndex/resolutions[k];
            }
            currentIndex=currentIndex%resolutions[j];
            currentArguments[j]=currentIndex*dxi[j]+boundaries[2*j];
        }
        totalSum +=f(currentArguments)*dxN;
    }
    delete[] currentArguments;
    delete[] dxi;
    return totalSum;
}