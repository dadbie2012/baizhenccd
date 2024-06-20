
#define CCALIPERGUI_H


#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <list>
#include "fineline/edge.h"
#ifndef	 _CLineCaliperGUI_
#define  _CLineCaliperGUI_
#include<QtMath>


using namespace std;
using namespace cv;



class CLineCaliperGUI
{
protected:
    enum class CAdjustWay
    {
        None=0,
        AdjustCenter,
        AdjustStart,
        AdjustEnd,
        AdjustMeasureLength,
        AdjustMeasureHeight,
        AdjustMeasureNums,
    };
    Mat		m_mInputMat;
    Point2d m_pdStart;
    Point2d m_pdEnd;
    Point2d m_pdCenter;
    double	m_dAngle;
    double	m_dLength;

    Point2d m_pdSampleLineStart;
    Point2d m_pdSampleLineEnd;


    vector<Point2d>m_LineSamplingPointSetsVec;
    vector<Point2d>m_lineEdgeEquPointSetsVec;

    vector<Point2d>m_vpdEdgePoints;
    vector<Point2d>m_errortLineEdgePointSets;
    vector<double>m_vdEdgeGradient;

    double	m_dMeasureAngle;
    double	m_dMeasureLength;
    double	m_dMeasureHeight;
    double	m_dSigma;
    int		m_nThreshold;
    int		m_nTranslation;
    int		m_nMeasureNums;
private:
    int				m_nCircleSize;
    bool			IsPointInCircle(Point2d pdCenter, Point2d pdPoint);
    CAdjustWay		m_eAdjustWay;
    CLineEdgePoint	lineEdgePointCalc;
    void RansacLineFiler(
        const vector<Point2d>& points,
        vector<Point2d>& vpdExceptPoints,
        double sigma = 1);
public:
    CLineCaliperGUI();
    void createLineKaChi(Mat& InputMat,
        Point2d pdStart,
        Point2d pdEnd,
        double dMeasureLength,
        double dMeasureHeight,
        double dSigma,
        int nThreshold,
        int nTranslation,
        int nMesureNums);

    void adjustLineKaChi(Mat& InputMat,
        Point2d pdPoint,
        int nMeasureLength,
        int nMeasureHeight,
        double dSigma,
        int nThreshold,
        int nTranslation,
        int nMeasureNums,
        int nFlag = 0);

    void drawMyArrow(Mat& inputMat, Point2d p1, Point2d p2, int dSize, Scalar color, int nThickness = 1);

    void drawMyCross(Mat& inputMat, Point2d p, double dAngle, double dSize, Scalar color,int nThickness = 1);

    void drawMyRect(Mat& inputMat, RotatedRect rRect,Scalar color, int nThickness = 1);


    double getPoint2PointLength(Point2d p1, Point2d p2);

    Point2d GetPPCenter(Point2d p1, Point2d p2);

    double getLineK(Point2d p1, Point2d p2);
    void getLineEquPointSets(Point2d pdStart, Point2d pdEnd, int nEquinoxNums,vector<Point2d>& vpdEquinoxPoints);
    void getLineLastPoint(Point2d pdCenter, double dAngle, double dLength, Point2d& pdStart, Point2d& pdEnd);

    Point2d getLineIntersections(Point2d p1,Point2d p2, Point2d p11, Point2d p22);


    double getAnglePoint2Point(Point2d p1,Point2d p2);

    void lineEdgePointSetsFit(Point2d& pdStart, Point2d& pdEnd, double& dAngle);
    void lineEdgePointSetsShow(Mat& InputMat, double dSize, Scalar color);
    void getLineEdgePointSetsInfo(vector<Point2d>& vpdEdgePoints,
        vector<double>& vpdEdgePointsGradient);

    vector<Point2d> getEdgePoints();
        vector<Point2d> getExcepetEdgePoints();


};
#endif

