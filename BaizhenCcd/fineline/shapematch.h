#ifndef SHAPEMATCH_H
#define SHAPEMATCH_H
#include<vector>
#include<opencv2/opencv.hpp>
#include<windows.h>


#include "high_shape_match.h"

#pragma comment(lib, "high_shape_match.lib")


using namespace cv;
using namespace std;

using namespace mypr;
using namespace chrono;


class shapematch
{
public:
    shapematch();
    int feature_show(cv::Mat& Insp, int model_id);
    int match_show(Mat& Insp, int model_id, int x0, int y0, Match* pMatches, int count, int subpixel = 0);
    int test();
   float dx;
    float dy;
    float angle;
};

#endif // SHAPEMATCH_H
