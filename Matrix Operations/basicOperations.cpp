#include <iostream>
using namespace std;

void convolution(float** baseImage, float** kernel) {
    int baseRows, baseColumns, kernelRows, kernelColumns;
    if (sizeof(baseImage)==0 or sizeof(kernel)==0) {
        cout << "Image or Kernel is Empty \n";
        return;
    }
    baseRows=sizeof(baseImage)/sizeof(baseImage[0]);
    baseColumns=sizeof(baseImage[0])/sizeof(baseImage[0][0]);

    kernelRows=sizeof(kernel)/sizeof(kernel[0]);
    kernelColumns=sizeof(kernel[0])/sizeof(kernel[0][0]);

    if (kernelRows%2==0 or kernelColumns%2==0) {
        cout <<"Erorr: Kernel should have odd number of rows/columns";
        return;
    }

    float** expandedImage= new float*[baseRows+2*kernelRows];
    for (int i=0; i<baseRows+2*kernelRows; i++) {
        expandedImage[i]= new float[baseColumns+2*kernelColumns];
    }

    for(int i=0; i<baseRows+2*kernelRows; i++) {
        for(int j=0; j<baseRows+2*kernelRows; j++) {
            if (i>=kernelRows and i<baseRows+kernelRows and j>=kernelRows and j<baseRows+kernelRows) {
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
            baseImage[i-kernelRows][j=kernelColumns]=convolvedValue;
        }
    }
    
    return;
}