#include <iostream>
#include <cmath>
using namespace std;

void convolution(int** baseImage, float** kernel) {
    int baseRows, baseColumns, kernelRows, kernelColumns;
    if (sizeof(baseImage)==0 || sizeof(kernel)==0) {
        cout << "Image or Kernel is Empty \n";
        return;
    }
    baseRows=sizeof(baseImage)/sizeof(baseImage[0]);
    baseColumns=sizeof(baseImage[0])/sizeof(baseImage[0][0]);

    kernelRows=sizeof(kernel)/sizeof(kernel[0]);
    kernelColumns=sizeof(kernel[0])/sizeof(kernel[0][0]);

    if (kernelRows%2==0 || kernelColumns%2==0) {
        cout <<"Erorr: Kernel should have odd number of rows/columns";
        return;
    }

    int** expandedImage= new int*[baseRows+2*kernelRows];
    for (int i=0; i<baseRows+2*kernelRows; i++) {
        expandedImage[i]= new int[baseColumns+2*kernelColumns];
    }

    for(int i=0; i<baseRows+2*kernelRows; i++) {
        for(int j=0; j<baseRows+2*kernelRows; j++) {
            if (i>=kernelRows && i<baseRows+kernelRows && j>=kernelRows && j<baseRows+kernelRows) {
                expandedImage[i][j]=baseImage[i][j];
            }
            else {
                expandedImage[i][j]=0;
            }
        }
    }
    int kernelCenterRow=kernelRows/2;
    int kernelCenterColumn=kernelColumns/2;
    for (int i=kernelRows; i<baseRows+kernelRows; i++) {
        for (int j=kernelColumns; j<baseColumns+kernelColumns; j++) {
            float convolvedValue=0;
            for (int k=0; k<kernelRows; k++) {
                for(int l=0; l<kernelColumns; l++) {
                    convolvedValue+= kernel[k][l]*expandedImage[i+(kernelCenterRow-k)][j+(kernelCenterColumn-l)];
                }
            }
            if(convolvedValue>255) {
                convolvedValue=255;
            }
            if(convolvedValue<0) {
                convolvedValue=0;
            }
            baseImage[i-kernelRows][j-kernelColumns]=static_cast<int>(round(convolvedValue));
        }
    }
    
    for (int i=0; i<sizeof(expandedImage)/sizeof(expandedImage[0]); i++) {
        delete[] expandedImage[i];
    }
    delete[] expandedImage;
    return;
}