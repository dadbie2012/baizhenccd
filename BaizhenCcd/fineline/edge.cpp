#include "edge.h"
#include "common.h"

CLineEdgePoint::CLineEdgePoint()
{
    m_pdCenter      = Point2d(0, 0);
    m_dAngle        = 0;
    m_dK            = 0;
    m_dB            = 0;
    m_dLength       = 0;
    m_dHeight       = 0;
    m_dSigma        = 0;
    m_nThreshold    = 0;
}


void CLineEdgePoint::getLineRoiImage()
{
    if (m_mInputMat.empty())
    {
        return;
    }
    if (m_mInputMat.channels() > 1)
    {
        cvtColor(m_mInputMat, m_mInputMat, COLOR_BGR2GRAY);
    }

    Mat RotateMat = getRotationMatrix2D(m_pdCenter, -m_dAngle, 1);

    warpAffine(m_mInputMat, m_mInputMat, RotateMat, m_mInputMat.size(), WARP_INVERSE_MAP | INTER_CUBIC);
    Mat newCenter = RotateMat * (Mat_<double>(3, 1) << m_pdCenter.x, m_pdCenter.y, 1);
    double x = newCenter.at<double>(0, 0);
    double y = newCenter.at<double>(1, 0);

    Mat M = (Mat_<double>(2, 3) << 1, 0, x - m_dLength * 0.5, 0, 1, y - m_dHeight * 0.5);
    warpAffine(m_mInputMat, m_mInputMat, M, Size2d(m_dLength, m_dHeight), WARP_INVERSE_MAP | INTER_CUBIC);
}

void CLineEdgePoint::imageGaussBlur()
{
    if (m_mInputMat.empty())
    {
        return;
    }
    if (m_mInputMat.channels() > 1)
    {
        cvtColor(m_mInputMat, m_mInputMat, COLOR_BGR2GRAY);
    }
    GaussianBlur(m_mInputMat, m_mInputMat, Size(1, 3), m_dSigma);
}

void CLineEdgePoint::getLineImageGrad()
{
    if (m_mInputMat.empty())
    {
        return;
    }
    if (m_mInputMat.channels() > 1)
    {
        cvtColor(m_mInputMat, m_mInputMat, COLOR_BGR2GRAY);
    }
    reduce(m_mInputMat, m_mInputMat, 0, REDUCE_AVG, CV_64FC1);
    Sobel(m_mInputMat, m_mInputMat, CV_64FC1, 1, 0, 1);

    m_mInputMat = m_dSigma * sqrt(2 * PI) * m_mInputMat;
}

void CLineEdgePoint::getLineEdgePoint(int threshold, CLineFineDir searchWay, CEdgeFindWay selection)
{
    if (m_mInputMat.empty())
    {
        return;
    }
    if (m_mInputMat.channels() > 1)
    {
        cvtColor(m_mInputMat, m_mInputMat, COLOR_BGR2GRAY);
    }

    double* ptr = m_mInputMat.ptr<double>(0);
    m_candiPointSetsVec.clear();
    m_lineEdgePointSetsVec.clear();

    for (int i = 0; i < m_mInputMat.cols; i++)
    {
        double dGradient = abs(ptr[i]);
        if (dGradient >= threshold)
        {
            m_candiPointSetsVec.push_back(Point2d(i, ptr[i]));
        }
    }
    if (m_candiPointSetsVec.size() == 0)
    {
        return;
    }
    if (searchWay == CLineFineDir::Poisitive)
    {
        for (vector<Point2d>::iterator iter = m_candiPointSetsVec.begin(); iter != m_candiPointSetsVec.end();)
        {
            if ((*iter).y <= 0)
            {
                iter = m_candiPointSetsVec.erase(iter);
            }
            else
            {
                iter++;
            }
        }
    }
    else if (searchWay == CLineFineDir::Negative)
    {
        for (vector<Point2d>::iterator iter = m_candiPointSetsVec.begin(); iter != m_candiPointSetsVec.end();)
        {
            if ((*iter).y > 0)
            {
                iter = m_candiPointSetsVec.erase(iter);
            }
            else
            {
                iter++;
            }
        }
    }
    if (m_candiPointSetsVec.size() == 0)
    {
        return;
    }
    if (selection == CEdgeFindWay::Fisrt)
    {
        m_candiPointSetsVec.erase(m_candiPointSetsVec.begin() + 1, m_candiPointSetsVec.end());
    }
    else if (selection == CEdgeFindWay::Last)
    {
        m_candiPointSetsVec.erase(m_candiPointSetsVec.begin(), m_candiPointSetsVec.end() - 1);
    }
    else if (selection == CEdgeFindWay::Strongest)
    {
        Point2d pdMax(0, 0);
        double dGradientMax = 0;
        for(Point2d item: m_candiPointSetsVec)
        {
            if (abs(item.y) >= dGradientMax)
            {
                pdMax = item;
                dGradientMax = abs(item.y);
            }
        }
        m_candiPointSetsVec.clear();
        m_candiPointSetsVec.push_back(pdMax);
    }
    else if (selection == CEdgeFindWay::weakest)
    {
        Point2d pdMin(0, 99999999);
        for (Point2d item : m_candiPointSetsVec)
        {
            if (abs(item.y) <= pdMin.y)
            {
                pdMin.y = abs(item.y);
                pdMin.x = item.x;
            }
        }
        m_candiPointSetsVec.clear();
        m_candiPointSetsVec.push_back(pdMin);
    }

    double dEdgex = 0, dEdgey = 0;
    for (Point2d item : m_candiPointSetsVec)
    {
        if (isinf(m_dK))
        {
            dEdgex = m_pdStart.x;
            dEdgey = m_pdStart.y + sin(to_radian(m_dAngle)) * item.x;
        }
        else
        {
            dEdgex = m_pdStart.x + item.x * cos(to_radian(m_dAngle));
            dEdgey = m_dK * dEdgex + m_dB;
        }
        m_lineEdgePointSetsVec.push_back(CEdgePointRes(Point2d(dEdgex, dEdgey), item.y));
    }
}


double CLineEdgePoint::getLineK(Point2d p1, Point2d p2)
{
    return (p1.y - p2.y) / (p1.x - p2.x);
}


void CLineEdgePoint::getLineLastPoint(Point2d pdCenter, double dAngle, double dLength, Point2d& pdStart, Point2d& pdEnd)
{
    pdStart.x = pdCenter.x - cos(to_radian(dAngle)) * 0.5 * dLength;
    pdStart.y = pdCenter.y - sin(to_radian(dAngle)) * 0.5 * dLength;
    pdEnd = Point2d(pdCenter.x * 2 - pdStart.x, pdCenter.y * 2 - pdStart.y);
}

vector<CEdgePointRes> CLineEdgePoint::getLineEdgePoints(
    Mat inputMat,
    Point2d pdCenter,
    double dMeasureLength,
    double dMeasureHeight,
    double dMeasureAngle,
    double sigma,
    int threshold,
    CLineFineDir traslation,
    CEdgeFindWay selection)
{
    if (inputMat.empty())
    {
        return vector<CEdgePointRes>();
    }
    if (inputMat.channels() > 1)
    {
        cvtColor(inputMat, inputMat, COLOR_BGR2GRAY);
    }
    m_lineEdgePointSetsVec.clear();
    inputMat.copyTo(m_mInputMat);
    m_pdCenter      = pdCenter;
    m_dLength       = dMeasureLength;
    m_dHeight       = dMeasureHeight;
    m_dAngle        = dMeasureAngle;
    m_dSigma        = sigma;
    m_nThreshold    = threshold * (m_dSigma * sqrt(2 * PI));
    getLineLastPoint(pdCenter, dMeasureAngle, dMeasureLength, m_pdStart, m_pdEnd);
    m_dK            = getLineK(m_pdStart, m_pdEnd);
    m_dB            = m_pdStart.y - m_dK * m_pdStart.x;

    getLineRoiImage();
    imageGaussBlur();
    getLineImageGrad();
    getLineEdgePoint(threshold, traslation, selection);
   // cout << "aabb" <<endl;

    return m_lineEdgePointSetsVec;
}





