#include <stdio.h>
#include <stdint.h>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char** argv )
{
    Mat original = imread( "cheval.jpg", CV_LOAD_IMAGE_COLOR );
    Mat modified = imread( "cheval.jpg", CV_LOAD_IMAGE_COLOR );
    if ( !original.data || !modified.data)
    {
        printf("No image data \n");
        return -1;
    }

    for(int r=0; r<modified.rows; r++){
        for(int c=0; c<modified.cols; c++){
	    original.at<cv::Vec3b>(r,c)[0] = modified.at<cv::Vec3b>(r,c)[0]*0; //[0] = blue
        }
    }

    imshow("Original", original);
    imshow("Modified", modified);

    waitKey(0);

    return 0;
}
