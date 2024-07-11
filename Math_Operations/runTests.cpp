#include "mathLocal.h"
#include <iostream>

int main() {
    float boundary1[2];
    boundary1[0]=0.0;
    boundary1[1]=2;
    int resolution1[1];
    resolution1[0]=100;
    int resolutionLength=sizeof(resolution1)/sizeof(resolution1[0]);
    std::string functionLabel="f(x)=x^2";

    testFunc(boundary1, &xSquared, resolution1, resolutionLength, functionLabel);

    float boundary2[4]= {0.0,2.0,0.0,2.0};
    int resolution2[2]= {1000, 1000};
    int resolutionLength2=sizeof(resolution2)/sizeof(resolution2[0]);
    functionLabel="f(x,y)=x+y";

    testFunc(boundary2, &xPlusy, resolution2, resolutionLength2, functionLabel);
    return 0;
}

