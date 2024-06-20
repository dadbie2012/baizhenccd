#include "CCaliperGUI.h"

#include "common.h"


void CLineCaliperGUI::RansacLineFiler(const vector<Point2d>& points,vector<Point2d>&errPoints, double sigma)
{
    unsigned int n = points.size();

    if (n < 2)
    {
        return;
    }

    RNG random;
    double bestScore = -1.;
    vector<Point2d>tempVec;
    int iterations = log(1 - 0.99) / (log(1 - (1.00 / n)))*10;

    for (int k = 0; k < iterations; k++)
    {
        int i1 = 0, i2 = 0;
        while (i1 == i2)
        {
            i1 = random(n);
            i2 = random(n);
        }
        const cv::Point2d& p1 = points[i1];
        const cv::Point2d& p2 = points[i2];
        Point2d vectorP21 = p2 - p1;
        vectorP21 *= 1. / norm(vectorP21);
        double score = 0;
        tempVec.clear();
        for (size_t i = 0; i < n; i++)
        {
            Point2d vectorPi1 = points[i] - p1;
            double d = vectorPi1.y * vectorP21.x - vectorPi1.x * vectorP21.y;
            if (fabs(d) < sigma)
            {
                score += 1;
            }
            else
            {
                tempVec.push_back(points[i]);
            }
        }
        if (score > bestScore)
        {
            bestScore = score;
            errPoints = tempVec;
        }
    }
}

CLineCaliperGUI::CLineCaliperGUI()
{
    m_pdStart					= Point2d(0, 0);
    m_pdEnd						= Point2d(0, 0);
    m_pdCenter					= Point2d(0, 0);
    m_dAngle					= 0;
    m_dLength					= 0;
    m_dMeasureLength			= 0;
    m_dSigma					= 1;
    m_nThreshold				= 30;
    m_nTranslation				= 1;
    m_nMeasureNums				= 1;
    m_LineSamplingPointSetsVec	= { Point2d(0,0),Point2d(0,0) };
    m_pdSampleLineStart			= { Point2d(-100,-100) };
    m_pdSampleLineEnd			= { Point2d(-100,-100) };
    m_nCircleSize				= 0;
    m_eAdjustWay = CAdjustWay::None;
}

bool CLineCaliperGUI::IsPointInCircle(Point2d pdCenter, Point2d pdPoint)
{
    return  getPoint2PointLength(pdCenter, pdPoint) <= m_nCircleSize;
}


void CLineCaliperGUI::drawMyCross(Mat& inputMat, Point2d p, double dAngle, double dSize, Scalar color,int nThickness)
{
    if (inputMat.empty())
    {
        return;
    }
    RotatedRect rotateRect(p, Size2d(dSize, dSize), dAngle);
    Point2f rectPoints[4];
    rotateRect.points(rectPoints);
    line(inputMat, rectPoints[0], rectPoints[2], color, nThickness, LINE_AA);
    line(inputMat, rectPoints[1], rectPoints[3], color, nThickness, LINE_AA);
}


void CLineCaliperGUI::drawMyArrow(Mat& inputMat, Point2d p1, Point2d p2, int dSize, Scalar color, int nThickness)
{
    if (inputMat.empty())
    {
        return;
    }
    double dK = ((double)p2.y - (double)p1.y) / ((double)p2.x - (double)p1.x);
    double dAngle = atan(dK) * 180 / PI;
    line(inputMat, p1, p2, color, nThickness, LINE_AA);
    RotatedRect rotateRect(p2, Size(dSize, dSize * 0.5), dAngle);
    Point2f rectPoints[4];
    rotateRect.points(rectPoints);
    if ((dAngle >= 0 && p1.x <= p2.x) || (dAngle < 0 && p1.x <= p2.x))
    {
        line(inputMat, p2, rectPoints[0], color, nThickness, LINE_AA);
        line(inputMat, p2, rectPoints[1], color, nThickness, LINE_AA);
    }
    else
    {
        line(inputMat, p2, rectPoints[2], color, nThickness, LINE_AA);
        line(inputMat, p2, rectPoints[3], color, nThickness, LINE_AA);
    }
}

void CLineCaliperGUI::createLineKaChi(Mat& InputMat,
    Point2d pdStart,
    Point2d pdEnd,
    double dMeasureLength,
    double dMeasureHeight,
    double dSigma,
    int nThreshold,
    int nTranslation,
    int nMesureNums)
{
    if (InputMat.empty())
    {
        return;
    }
    InputMat.copyTo(m_mInputMat);
    m_pdStart			= pdStart;
    m_pdEnd				= pdEnd;
    m_pdCenter			= GetPPCenter(pdStart, pdEnd);
    m_dAngle			= getAnglePoint2Point(pdStart, pdEnd);
    m_dLength			= getPoint2PointLength(pdStart, pdEnd);
    m_dMeasureLength	= dMeasureLength;
    m_dMeasureAngle		= m_dAngle - 90;
    m_dMeasureHeight	= dMeasureHeight;
    m_dSigma			= dSigma;
    m_nThreshold		= nThreshold;
    m_nTranslation		= nTranslation;
    m_nMeasureNums		= nMesureNums;
    m_nCircleSize = InputMat.cols / 150;

    drawMyArrow(InputMat, pdStart, pdEnd, (int)m_nCircleSize * 5, Cyan, 1);
    circle(InputMat, pdStart, m_nCircleSize, Yellow, 1, 16);
    circle(InputMat, pdEnd, m_nCircleSize, Yellow, 1, 16);
    circle(InputMat, m_pdCenter, m_nCircleSize, Yellow, 1, 16);


    getLineLastPoint(m_pdCenter, m_dAngle - 90, dMeasureLength+100, m_pdSampleLineStart, m_pdSampleLineEnd);
    drawMyArrow(InputMat, m_pdSampleLineStart, m_pdSampleLineEnd, (int)m_nCircleSize * 5, Cyan, 1);
    circle(InputMat, m_pdSampleLineEnd, m_nCircleSize, Yellow, 1, 16);


    getLineEquPointSets(m_pdStart, m_pdEnd, nMesureNums + 1, m_lineEdgeEquPointSetsVec);
    RotatedRect rRect;
    Point2d p1, p2;
    for (size_t i = 0; i < m_lineEdgeEquPointSetsVec.size(); i++)
    {
        getLineLastPoint(m_lineEdgeEquPointSetsVec[i], m_dAngle - 90, dMeasureLength, p1, p2);
        drawMyArrow(InputMat, p1, p2, (int)m_nCircleSize * 5, Cyan, 1);
        rRect = RotatedRect(m_lineEdgeEquPointSetsVec[i], Size2f(dMeasureLength, dMeasureHeight), m_dAngle - 90);
        drawMyRect(InputMat, rRect, Blue, 1);
    }
}

void CLineCaliperGUI::getLineEquPointSets(Point2d pdStart, Point2d pdEnd, int nEquinoxNums,vector<Point2d>& vpdEquinoxPoints)
{
    if (nEquinoxNums == 0)
    {
        return;
    }
    vpdEquinoxPoints.clear();
    double dXoffset = (pdEnd.x - pdStart.x) / nEquinoxNums;
    double dYoffset = (pdEnd.y - pdStart.y) / nEquinoxNums;
    for (int i = 0; i < nEquinoxNums - 1; i++)
    {
        double dx = dXoffset * ((double)i + 1);
        double dy = dYoffset * ((double)i + 1);
        vpdEquinoxPoints.push_back(Point2d(pdStart.x + dx, pdStart.y + dy));
    }
}


void CLineCaliperGUI::getLineLastPoint(Point2d pdCenter, double dAngle, double dLength, Point2d& pdStart, Point2d& pdEnd)
{
    pdStart.x = pdCenter.x - cos(to_radian(dAngle)) * 0.5 * dLength;
    pdStart.y = pdCenter.y - sin(to_radian(dAngle)) * 0.5 * dLength;
    pdEnd = Point2d(pdCenter.x * 2 - pdStart.x, pdCenter.y * 2 - pdStart.y);
}

Point2d CLineCaliperGUI::getLineIntersections(Point2d p1,Point2d p2, Point2d p11, Point2d p22)
{
    double dK1 = (p1.y - p2.y) / (p1.x - p2.x);
    double dK2 = (p11.y - p22.y) / (p11.x - p22.x);

    if (dK1 == dK2)//parallel
    {
        return Point2d(-1, -1);
    }
    Point2d pdIntersection(0, 0);
    if (isinf(dK1) || isnan(dK1))//paralle to the y-axis
    {
        pdIntersection.x = p1.x;
        double dB2 = p11.y - dK2 * p11.x;
        pdIntersection.y = dK2 * pdIntersection.x + dB2;
    }
    else if (isinf(dK2) || isnan(dK2))
    {
        pdIntersection.x = p11.x;
        double dB1 = p1.y - dK1 * p1.x;
        pdIntersection.y = dK1 * pdIntersection.x + dB1;
    }
    else
    {
        double dB1 = p1.y - dK1 * p1.x;
        double dB2 = p11.y - dK2 * p11.x;
        pdIntersection.x = (dB2 - dB1) / (dK1 - dK2);
        pdIntersection.y = dK1 * pdIntersection.x + dB1;
    }
    return pdIntersection;
}

double CLineCaliperGUI::getAnglePoint2Point(Point2d p1,Point2d p2)
{
    if (p1 == p2)
    {
        return -1;
    }
    Point2d vector = p2 - p1;
    if (vector.x == 0)
    {
        if (vector.y > 0)
        {
            return 90;
        }
        else
        {
            return -90;
        }
    }
    double angle = to_degree(acos(pow(vector.x, 2) / (vector.x * sqrt(pow(vector.x, 2) + pow(vector.y, 2)))));
    if (p1.y > p2.y)
    {
        angle = -angle;
    }


    return  angle;
}


double CLineCaliperGUI::getPoint2PointLength(Point2d p1, Point2d p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

Point2d CLineCaliperGUI::GetPPCenter(Point2d p1, Point2d p2)
{
    return Point2d((p1.x + p2.x) * 0.5, (p1.y + p2.y) * 0.5);
}

double CLineCaliperGUI::getLineK(Point2d p1, Point2d p2)
{
    return (p1.y - p2.y) / (p1.x - p2.x);
}

void CLineCaliperGUI::drawMyRect(Mat& inputMat, RotatedRect rRect,Scalar color, int nThickness)
{
    Point2f pfRectPoints[4];
    rRect.points(pfRectPoints);
    for (int i = 0; i < 4; i++)
    {
        line(inputMat, pfRectPoints[i], pfRectPoints[(i + 1) % 4], color, nThickness, LINE_AA);
    }
}

void CLineCaliperGUI::adjustLineKaChi(Mat& InputMat, Point2d pdPoint, int nMeasureLength, int nMeasureHeight, double dSigma, int nThreshold, int nTranslation, int nMeasureNums, int nFlag)
{
    if (nFlag == 1)
    {
        m_eAdjustWay = CAdjustWay::None;
        createLineKaChi(InputMat, m_pdStart, m_pdEnd, m_dMeasureLength, m_dMeasureHeight, dSigma, nThreshold, nTranslation, m_nMeasureNums);
        return;
    }
    if (IsPointInCircle(m_pdStart, pdPoint))
    {
        m_eAdjustWay = CAdjustWay::AdjustStart;
    }
    else if (IsPointInCircle(m_pdEnd, pdPoint))
    {
        m_eAdjustWay = CAdjustWay::AdjustEnd;
    }
    else if (IsPointInCircle(m_pdCenter, pdPoint))
    {
        m_eAdjustWay = CAdjustWay::AdjustCenter;
    }
    else if (IsPointInCircle(m_pdSampleLineEnd, pdPoint))
    {
        m_eAdjustWay = CAdjustWay::AdjustMeasureLength;
    }
    else if (pdPoint.x == -1 && pdPoint.y == -1)
    {
        createLineKaChi(InputMat, m_pdStart, m_pdEnd, m_dMeasureLength, m_dMeasureHeight, dSigma, nThreshold, nTranslation, nMeasureNums);
    }
    else if (pdPoint.x == -2 && pdPoint.y == -2)
    {
        createLineKaChi(InputMat, m_pdStart, m_pdEnd, nMeasureLength, m_dMeasureHeight, dSigma, nThreshold, nTranslation, m_nMeasureNums);
    }
    else if (pdPoint.x == -3 && pdPoint.y == -3)
    {
        createLineKaChi(InputMat, m_pdStart, m_pdEnd, m_dMeasureLength, nMeasureHeight, dSigma, nThreshold, nTranslation, m_nMeasureNums);
    }
    else
    {
        createLineKaChi(InputMat, m_pdStart, m_pdEnd, m_dMeasureLength, m_dMeasureHeight, dSigma, nThreshold, nTranslation, m_nMeasureNums);
    }

    if (m_eAdjustWay == CAdjustWay::AdjustStart)
    {
        createLineKaChi(InputMat, pdPoint, m_pdEnd, m_dMeasureLength, m_dMeasureHeight, dSigma, nThreshold, nTranslation, m_nMeasureNums);
    }
    else if (m_eAdjustWay == CAdjustWay::AdjustEnd)
    {
        createLineKaChi(InputMat, m_pdStart, pdPoint,m_dMeasureLength, m_dMeasureHeight, dSigma, nThreshold, nTranslation, m_nMeasureNums);
    }
    else if (m_eAdjustWay == CAdjustWay::AdjustCenter)
    {
        getLineLastPoint(pdPoint, m_dAngle, m_dLength, m_pdStart, m_pdEnd);
        createLineKaChi(InputMat, m_pdStart, m_pdEnd, m_dMeasureLength, m_dMeasureHeight, dSigma, nThreshold, nTranslation, m_nMeasureNums);
    }
    else if (m_eAdjustWay == CAdjustWay::AdjustMeasureLength)
    {
        double dMeasureLength = getPoint2PointLength(m_pdCenter, pdPoint) * 2 - 100;

        if (dMeasureLength < 1)
        {
            dMeasureLength = m_dMeasureLength;
        }
        createLineKaChi(InputMat, m_pdStart, m_pdEnd, dMeasureLength, m_dMeasureHeight, dSigma, nThreshold, nTranslation, m_nMeasureNums);
    }
}

void CLineCaliperGUI::lineEdgePointSetsFit(Point2d& pdStart, Point2d& pdEnd, double& dAngle)
{
    RotatedRect rMaskRegion(m_pdCenter, Size2f(getPoint2PointLength(m_pdStart, m_pdEnd) + 10, m_dMeasureLength + 10), m_dAngle);

    Point2f rRegionPoints[4];
    rMaskRegion.points(rRegionPoints);
    Mat mask = Mat::zeros(m_mInputMat.size(), CV_8UC1);
    Point ppt[] = { rRegionPoints[0], rRegionPoints[1], rRegionPoints[2], rRegionPoints[3] };
    const Point* pts[] = { ppt };
    int npt[] = { 4 };
    fillPoly(mask, pts, npt, 1, Scalar::all(255), 8);
    Mat RoiMat;
    bitwise_and(m_mInputMat, m_mInputMat, RoiMat, mask);

    m_vpdEdgePoints.clear();
    m_vdEdgeGradient.clear();
    m_errortLineEdgePointSets.clear();
    for (size_t i = 0; i < m_lineEdgeEquPointSetsVec.size(); i++)
    {
        vector<CEdgePointRes>edges = lineEdgePointCalc.getLineEdgePoints(RoiMat, m_lineEdgeEquPointSetsVec[i], m_dMeasureLength, m_dMeasureHeight, m_dAngle - 90
            , m_dSigma, m_nThreshold, m_nTranslation == 1 ? CLineFineDir::Poisitive : CLineFineDir::Negative, CEdgeFindWay::Strongest);
        for (size_t i = 0; i < edges.size(); i++)
        {
            m_vpdEdgePoints.push_back(edges[i].m_pdEdgePoint);
            m_vdEdgeGradient.push_back(edges[i].m_dGradient);
        }
    }
    Vec4f lines;
    int nSize = m_vpdEdgePoints.size() - 1;
    pdStart = Point2d(-1, -1);
    pdEnd = Point2d(-1, -1);
    if (nSize >= 0)
    {
        RansacLineFiler(m_vpdEdgePoints, m_errortLineEdgePointSets);
        for (Point2d point : m_errortLineEdgePointSets)
        {
            for (int i = 0; i < nSize + 1; i++)
            {
                if (point == m_vpdEdgePoints[i])
                {
                    m_vpdEdgePoints.erase(m_vpdEdgePoints.begin() + i);
                    break;
                }
            }
        }
        nSize = m_vpdEdgePoints.size() - 1;

        fitLine(m_vpdEdgePoints, lines, DIST_HUBER, 0, 0.01, 0.01);
        double dK	= lines[1] / lines[0];


        Point2d pdfitLineP1 = Point2d(m_vpdEdgePoints[0].x, dK * (m_vpdEdgePoints[0].x - lines[2]) + lines[3]);
        Point2d pdfitLineP2 = Point2d(m_vpdEdgePoints[nSize].x, dK * (m_vpdEdgePoints[nSize].x - lines[2]) + lines[3]);
        Point2d pdP11(0, 0), pdP22(0, 0);

        getLineLastPoint(m_vpdEdgePoints[0], m_dAngle - 90, m_dMeasureLength, pdP11, pdP22);
        pdStart = getLineIntersections(pdfitLineP1, pdfitLineP2, pdP11, pdP22);
        //cout<<"pdStart.x"<<pdStart.x<<endl;
       // cout<<pdStart.y<<endl;


        getLineLastPoint(m_vpdEdgePoints[nSize], m_dAngle - 90, m_dMeasureLength, pdP11, pdP22);
        pdEnd = getLineIntersections(pdfitLineP1, pdfitLineP2, pdP11, pdP22);

        dAngle = getAnglePoint2Point(pdStart, pdEnd);
    }


}

void CLineCaliperGUI::lineEdgePointSetsShow(Mat& InputMat, double dSize, Scalar color)
{
    if (InputMat.empty())
    {
        return;
    }
    for (auto edge : m_vpdEdgePoints)
    {
        drawMyCross(InputMat, edge, 90, dSize, color, 1);
    }
    for (auto edge : m_errortLineEdgePointSets)
    {
        drawMyCross(InputMat, edge, 90, dSize, Red, 1);
    }
}

void CLineCaliperGUI::getLineEdgePointSetsInfo(vector<Point2d>& edgePointSets, vector<double>& edgePointSetGrad)
{
    edgePointSets = m_vpdEdgePoints;
    edgePointSetGrad = m_vdEdgeGradient;
}




vector<Point2d> CLineCaliperGUI::getEdgePoints()
{
    return m_vpdEdgePoints;
}

vector<Point2d> CLineCaliperGUI::getExcepetEdgePoints()
{
    return m_errortLineEdgePointSets;
}
