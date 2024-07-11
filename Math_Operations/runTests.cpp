#include "mathLocal.h"
#include <iostream>

int main() {
    float boundary1[2];
    boundary1[0]=0.0;
    boundary1[1]=2;
    int resolution1[1];
    resolution1[0]=1000;
    int resolutionLength=sizeof(resolution1)/sizeof(resolution1[0]);
    std::string functionLabel="f(x)=x^2";

    testFunc(boundary1, &xSquared, resolution1, resolutionLength, functionLabel);
    return 0;
}

