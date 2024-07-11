#ifndef MATHLOCAL
#define MATHLOCAL
#include <iostream>

float integral(float* boundaries, float (*f)(float* arguments), int* resolutions, int resolutionLength);

void testFunc(float* boundaries, float (*f)(float* arguments), int* resolutions, int resolutionLength, std::string funcLabel);

float xSquared(float* arguments);

float xPlusy(float* arguments);

#endif