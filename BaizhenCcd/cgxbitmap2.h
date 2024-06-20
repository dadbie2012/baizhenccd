#ifndef CGXBITMAP2_H
#define CGXBITMAP2_H

#include <QWidget>
#include <QLabel>
#include <iostream>
#include<visiondahengcamera.h>
#include<QMutex>
#include<QWriteLocker>
#include<QReadLocker>
#include<QPainter>
class CGXBitmap2:public QObject
{
    Q_OBJECT
public:
    CGXBitmap2();

    ~CGXBitmap2();

private:

    bool               m_bIsColor;                       //是否支持彩色相机
    int64_t            m_nImageHeight;                   //原始图像高
    int64_t            m_nImageWidth;                    //原始图像宽
    BITMAPINFO         *m_pBmpInfo;	                     //BITMAPINFO 结构指针，显示图像时使用
    char               m_chBmpBuf[2048];	             //BIMTAPINFO 存储缓冲区，m_pBmpInfo即指向此缓冲区
    uchar              *m_pImageBuffer;                  //保存翻转后的图像用于显示
    QReadWriteLock locker;
     //QWriteLocker writelocker;
private:
    CGXBitmap2& operator=(const CGXBitmap2&);
    CGXBitmap2(const CGXBitmap2&);

public:
    static int cameraopennum;
    QMutex *mutex;
        int count=0;
    bool ifexpand=false;

    QLabel			   *m_pLabel;
    QImage			   *m_pImage;
    int NUM;
    //显示图像
    void Show(CImageDataPointer& objCImageDataPointer);

    //图像处理后并显示图像
    void ShowImageProcess(CImageProcessConfigPointer& objCfg, CImageDataPointer& objCImageDataPointer);

    //存储Bmp图像
    //void SaveBmp(CImageDataPointer& objCImageDataPointer, const std::string& strFilePath);

    //存储Raw图像
    void SaveRaw(CImageDataPointer& objCImageDataPointer, const std::string& strFilePath);

    //通过GX_PIXEL_FORMAT_ENTRY获取最优Bit位
    GX_VALID_BIT_LIST GetBestValudBit(GX_PIXEL_FORMAT_ENTRY emPixelFormatEntry);

    LPCWSTR stringToLPCWSTR(std::string orig);

    void addDevicePtr(CGXDevicePointer& objCGXDevicePointer);

public slots:
       void SaveBmp(CImageDataPointer& objCImageDataPointer, const std::string& strFilePath);


    void getimage(CImageDataPointer & objImageDataPointer);

private:
    //判断PixelFormat是否为8位
    bool __IsPixelFormat8(GX_PIXEL_FORMAT_ENTRY emPixelFormatEntry);

    //为彩色相机图像显示准备资源
    void __ColorPrepareForShowImg();

    //为黑白相机图像显示准备资源
    void __MonoPrepareForShowImg();

    //判断是否兼容
    bool __IsCompatible(BITMAPINFO *pBmpInfo, uint64_t nWidth, uint64_t nHeight);

    //更新Bitmap的信息
    void __UpdateBitmap(CImageDataPointer& objCImageDataPointer);

    //将m_pBufferRGB中图像显示到界面
    void __DrawImg(uchar* pBuffer);
    //将m_pBufferRGB中图像显示到界面
    void __DrawImg2(uchar* pBuffer);

    //计算宽度所占的字节数
    int64_t __GetStride(int64_t nWidth, bool bIsColor);

    //是否支持彩色
    void __IsSupportColor(CGXDevicePointer& objCGXDevicePointer, bool &bIsColorFilter);

signals:
    void sendqimage(QImage image,QMutex *MUTEX);
    void sendexpandqimage(QImage image,QMutex *MUTEX);

};

#endif // CGXBITMAP2_H
