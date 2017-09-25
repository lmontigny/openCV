#include <stdio.h>
#include <stdint.h>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(int argc, char** argv )
{
    Mat original = imread( "cheval.jpg", CV_LOAD_IMAGE_COLOR );

    Mat splitChannels[3];

    split(original, splitChannels);
    imshow("B", splitChannels[0]);
    imshow("G", splitChannels[1]);
    imshow("G", splitChannels[2]);

    splitChannels[2] = Mat::zeros(splitChannels[2].size(), CV_8UC1);

    Mat output;

    merge(splitChannels, 3, output);
    imshow("Merged", output);
    waitKey();
    return 0;
}
