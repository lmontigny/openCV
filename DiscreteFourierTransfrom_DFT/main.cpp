#include <stdio.h>
#include <stdint.h>
#include <opencv2/opencv.hpp>
using namespace cv;

void takeDFT(Mat &source, Mat& destination){
    Mat originalComplex[2] = {source, Mat::zeros(source.size(), CV_32F)};

    Mat dftReady;

    merge(originalComplex, 2, dftReady);

    Mat dftOfOriginal;

    dft(dftReady, dftOfOriginal, DFT_COMPLEX_OUTPUT);

    destination = dftOfOriginal;

}

void recenterDFT(Mat& source){
    int centerX = source.cols/2;
    int centerY = source.rows/2;

    Mat q1(source, Rect(0,0, centerX, centerY));
    Mat q2(source, Rect(centerX,0, centerX, centerY));
    Mat q3(source, Rect(0,centerY, centerX, centerY));
    Mat q4(source, Rect(centerX, centerY, centerX, centerY));

    Mat swapMap;

    q1.copyTo(swapMap);
    q4.copyTo(q1);
    swapMap.copyTo(q4);

    q2.copyTo(swapMap);
    q3.copyTo(q2);
    swapMap.copyTo(q3);

    
}

void showDFT(Mat& source){
    Mat splitArray[2] = {Mat::zeros(source.size(), CV_32F), Mat::zeros(source.size(), CV_32F)};

    split(source, splitArray);

    Mat dftMagnitude;

    magnitude(splitArray[0], splitArray[1], dftMagnitude);

    dftMagnitude += Scalar::all(1);

    log(dftMagnitude, dftMagnitude);

    normalize(dftMagnitude, dftMagnitude, 0, 1, CV_MINMAX);
    recenterDFT(dftMagnitude);
    imshow("DFT", dftMagnitude);
    waitKey();
}

void invertDFT(Mat& source, Mat& destination){
	Mat inverse;
	dft(source, inverse, DFT_INVERSE | DFT_REAL_OUTPUT | DFT_SCALE);
	destination = inverse;
}

int main(int argc, char** argv )
{
    Mat original = imread( "cheval.jpg", CV_LOAD_IMAGE_GRAYSCALE );
    
    Mat originalFloat;

    original.convertTo(originalFloat, CV_32FC1, 1.0/255.0);

    Mat dftOfOriginal;

    takeDFT(originalFloat, dftOfOriginal);
    showDFT(dftOfOriginal);

    Mat invertedDFT;
    
    invertDFT(dftOfOriginal, invertedDFT);
    imshow("invertedDFT Result", invertedDFT);
    waitKey();
    return 0;
}
