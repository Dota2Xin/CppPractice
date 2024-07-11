#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
    cv::Mat image= cv::imread("C:\\Users\\gabri\\OneDrive\\Pictures\\siteBannerBasic.png");

    if (image.empty()) {
        std::cerr << "Could not open or find the image" << std::endl;
        return -1;
    }

    cv::imshow("Display window", image);
    cv::waitKey(0);
    return 0;
}