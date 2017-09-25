#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char** argv )
{
    Mat imageColor = imread( "cheval.jpg", CV_LOAD_IMAGE_COLOR );
    if ( !imageColor.data )
    {
        printf("No image data \n");
        return -1;
    }

    Mat imageGray = imread( "cheval.jpg", CV_LOAD_IMAGE_GRAYSCALE );
    if ( !imageGray.data )
    {
        printf("No image data \n");
        return -1;
    }

    namedWindow("Color", CV_WINDOW_NORMAL);
    namedWindow("Gray", CV_WINDOW_FREERATIO);

    imshow("Color", imageColor);
    imshow("Gray", imageGray);

    resizeWindow("Gray", imageGray.cols/2, imageGray.rows/2);
    moveWindow("Gray", 200, 100);

    imwrite("cheval_color.jpg", imageColor);
    imwrite("cheval_gray.jpg", imageGray);

    waitKey(0);

    return 0;
}
