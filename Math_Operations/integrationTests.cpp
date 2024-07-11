#include "mathLocal.h"
#include <iostream>

using namespace std;

float xSquared(float* arguments) {
    return arguments[0]*arguments[0];
}

void testFunc(float* boundaries, float (*f)(float* arguments), int* resolutions,int resolutionLength, std::string funcLabel) {
    float integrationValue=integral(boundaries, f, resolutions, resolutionLength);
    cout <<"Resolution Length=" <<resolutionLength <<"\n";
    cout << "Integration of function:" << funcLabel << "\n";
    for(int i=0; i<resolutionLength; i++) {
        cout << "x" << i << "=(" << boundaries[2*i] << ", " << boundaries[2*i+1] <<")" << " Resolution=" << resolutions[i] <<"\n" ;
    }
    cout <<"Integration Result=" << integrationValue;
    return;
}