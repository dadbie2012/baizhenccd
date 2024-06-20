#include "cgxbitmap2.h"


CGXBitmap2::CGXBitmap2()

{

    m_bIsColor=false;
    m_nImageHeight=0;
    m_nImageWidth=0;
    m_pImage=NULL;
    m_pBmpInfo=NULL;
    m_pImageBuffer=NULL;
    mutex=new QMutex;
}
int CGXBitmap2::cameraopennum=0;
void CGXBitmap2::addDevicePtr(CGXDevicePointer& objCGXDevicePointer)
{
    if (objCGXDevicePointer.IsNull())
    {
        throw std::runtime_error("Argument is error");
    }

    memset(m_chBmpBuf, 0, sizeof(m_chBmpBuf));
    gxstring strValue = "";

    //获得图像宽度、高度等

    m_nImageWidth = (int64_t)objCGXDevicePointer->GetRemoteFeatureControl()->GetIntFeature("Width")->GetValue();
    m_nImageHeight = (int64_t)objCGXDevicePointer->GetRemoteFeatureControl()->GetIntFeature("Height")->GetValue();

    //获取是否为彩色相机
    __IsSupportColor(objCGXDevicePointer, m_bIsColor);

    if (m_bIsColor)
    {

        __ColorPrepareForShowImg();
    }
    else
    {

        __MonoPrepareForShowImg();
    }
}
//---------------------------------------------------------------------------------
/**
\brief   析构函数
\return  无
*/
//----------------------------------------------------------------------------------
CGXBitmap2::~CGXBitmap2()
{

}

//----------------------------------------------------------------------------------
/**
\brief     判断PixelFormat是否为8位
\param     emPixelFormatEntry 图像数据格式
\return    true为8为数据，false为非8位数据
*/
//----------------------------------------------------------------------------------
bool CGXBitmap2::__IsPixelFormat8(GX_PIXEL_FORMAT_ENTRY emPixelFormatEntry)
{
    bool bIsPixelFormat8 = false;
    const unsigned  PIXEL_FORMATE_BIT = 0x00FF0000;  ///<用于与当前的数据格式进行与运算得到当前的数据位数
    unsigned uiPixelFormatEntry = (unsigned)emPixelFormatEntry;
    if ((uiPixelFormatEntry & PIXEL_FORMATE_BIT) == GX_PIXEL_8BIT)
    {
        bIsPixelFormat8 = true;
    }
    return bIsPixelFormat8;
}

//----------------------------------------------------------------------------------
/**
\brief     通过GX_PIXEL_FORMAT_ENTRY获取最优Bit位
\param     emPixelFormatEntry 图像数据格式
\return    最优Bit位
*/
//----------------------------------------------------------------------------------
GX_VALID_BIT_LIST CGXBitmap2::GetBestValudBit(GX_PIXEL_FORMAT_ENTRY emPixelFormatEntry)
{
    GX_VALID_BIT_LIST emValidBits = GX_BIT_0_7;
    switch (emPixelFormatEntry)
    {
    case GX_PIXEL_FORMAT_MONO8:
    case GX_PIXEL_FORMAT_BAYER_GR8:
    case GX_PIXEL_FORMAT_BAYER_RG8:
    case GX_PIXEL_FORMAT_BAYER_GB8:
    case GX_PIXEL_FORMAT_BAYER_BG8:
    {
        emValidBits = GX_BIT_0_7;
        break;
    }
    case GX_PIXEL_FORMAT_MONO10:
    case GX_PIXEL_FORMAT_BAYER_GR10:
    case GX_PIXEL_FORMAT_BAYER_RG10:
    case GX_PIXEL_FORMAT_BAYER_GB10:
    case GX_PIXEL_FORMAT_BAYER_BG10:
    {
        emValidBits = GX_BIT_2_9;
        break;
    }
    case GX_PIXEL_FORMAT_MONO12:
    case GX_PIXEL_FORMAT_BAYER_GR12:
    case GX_PIXEL_FORMAT_BAYER_RG12:
    case GX_PIXEL_FORMAT_BAYER_GB12:
    case GX_PIXEL_FORMAT_BAYER_BG12:
    {
        emValidBits = GX_BIT_4_11;
        break;
    }
    case GX_PIXEL_FORMAT_MONO14:
    {
        //暂时没有这样的数据格式待升级
        break;
    }
    case GX_PIXEL_FORMAT_MONO16:
    case GX_PIXEL_FORMAT_BAYER_GR16:
    case GX_PIXEL_FORMAT_BAYER_RG16:
    case GX_PIXEL_FORMAT_BAYER_GB16:
    case GX_PIXEL_FORMAT_BAYER_BG16:
    {
        //暂时没有这样的数据格式待升级
        break;
    }
    default:
        break;
    }
    return emValidBits;
}

//---------------------------------------------------------------------------------
/**
\brief   为彩色相机图像显示准备资源
\return  无
*/
//----------------------------------------------------------------------------------
void CGXBitmap2::__ColorPrepareForShowImg()
{
    //--------------------------------------------------------------------
    //---------------------------初始化bitmap头---------------------------

    m_pBmpInfo = (BITMAPINFO *)m_chBmpBuf;
    m_pBmpInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    m_pBmpInfo->bmiHeader.biWidth = (LONG)m_nImageWidth;
    m_pBmpInfo->bmiHeader.biHeight = (LONG)m_nImageHeight;

    m_pBmpInfo->bmiHeader.biPlanes = 1;
    m_pBmpInfo->bmiHeader.biBitCount = 24;
    m_pBmpInfo->bmiHeader.biCompression = BI_RGB;
    m_pBmpInfo->bmiHeader.biSizeImage = 0;
    m_pBmpInfo->bmiHeader.biXPelsPerMeter = 0;
    m_pBmpInfo->bmiHeader.biYPelsPerMeter = 0;
    m_pBmpInfo->bmiHeader.biClrUsed = 0;
    m_pBmpInfo->bmiHeader.biClrImportant = 0;
}

//---------------------------------------------------------------------------------
/**
\brief   为黑白相机图像显示准备资源
\return  无
*/
//----------------------------------------------------------------------------------
void CGXBitmap2::__MonoPrepareForShowImg()
{
    //---------------------------------------------------------------------
    //----------------------初始化bitmap头---------------------------------
    m_pBmpInfo = (BITMAPINFO *)m_chBmpBuf;
    m_pBmpInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    m_pBmpInfo->bmiHeader.biWidth = (LONG)m_nImageWidth;
    m_pBmpInfo->bmiHeader.biHeight = (LONG)m_nImageHeight;

    m_pBmpInfo->bmiHeader.biPlanes = 1;
    m_pBmpInfo->bmiHeader.biBitCount = 8; // 黑白图像为8
    m_pBmpInfo->bmiHeader.biCompression = BI_RGB;
    m_pBmpInfo->bmiHeader.biSizeImage = 0;
    m_pBmpInfo->bmiHeader.biXPelsPerMeter = 0;
    m_pBmpInfo->bmiHeader.biYPelsPerMeter = 0;
    m_pBmpInfo->bmiHeader.biClrUsed = 0;
    m_pBmpInfo->bmiHeader.biClrImportant = 0;

    // 黑白图像需要初始化调色板
    for (int i = 0; i < 256; i++)
    {
        m_pBmpInfo->bmiColors[i].rgbBlue = i;
        m_pBmpInfo->bmiColors[i].rgbGreen = i;
        m_pBmpInfo->bmiColors[i].rgbRed = i;
        m_pBmpInfo->bmiColors[i].rgbReserved = 0;
    }

    //为经过翻转后的图像数据分配空间
    if (m_pImageBuffer != NULL)
    {
        delete m_pImageBuffer;
        m_pImageBuffer = NULL;
    }

    m_pImageBuffer = new BYTE[(size_t)(m_nImageWidth * m_nImageHeight)];
    if (m_pImageBuffer == NULL)
    {
        throw std::runtime_error("Fail to allocate memory");
    }
}

//----------------------------------------------------------------------------------
/**
\brief     判断是否兼容
\param     pBmpInfo BITMAPINFO指针
\param     nWidth 图像宽
\param     nHeight 图像高
\return    true为一样，false不一样
*/
//----------------------------------------------------------------------------------
bool CGXBitmap2::__IsCompatible(BITMAPINFO *pBmpInfo, uint64_t nWidth, uint64_t nHeight)
{
    if (pBmpInfo == NULL
            || pBmpInfo->bmiHeader.biHeight != nHeight
            || pBmpInfo->bmiHeader.biWidth != nWidth
            )
    {
        return false;
    }
    return true;
}

//----------------------------------------------------------------------------------
/**
\brief     检查图像是否改变并更新Buffer并为图像显示准备资源
\param     objCImageDataPointer  图像数据对象
\return    无
*/
//----------------------------------------------------------------------------------
void CGXBitmap2::__UpdateBitmap(CImageDataPointer& objCImageDataPointer)
{
    locker.lockForWrite();
    if (!__IsCompatible(m_pBmpInfo, objCImageDataPointer->GetWidth(), objCImageDataPointer->GetHeight()))
    {
        m_nImageWidth = objCImageDataPointer->GetWidth();
        m_nImageHeight = objCImageDataPointer->GetHeight();
        if (m_bIsColor)
        {

            __ColorPrepareForShowImg();
        }
        else
        {
            __MonoPrepareForShowImg();
        }
    }
    locker.unlock();
}

//---------------------------------------------------------------------------------
/**
\brief   将m_pBufferRGB中图像显示到界面
\param   pBuffer  图像数据Buffer指针
\return  无
*/
//----------------------------------------------------------------------------------
void CGXBitmap2::__DrawImg(uchar* pBuffer)
{
    QImage image;
    locker.lockForRead();
    //    if (m_pImage != NULL)
    //    {
    //        delete m_pImage;
    //        m_pImage = NULL;
    //    }
    //    //数据转换
    //    m_pImage = new QImage(pBuffer, m_nImageWidth, m_nImageHeight, QImage::Format_RGB888);
    image=QImage(pBuffer, m_nImageWidth, m_nImageHeight, QImage::Format_RGB888);
    image.scaled(m_nImageWidth, m_nImageHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    // 不失真缩放
    //   m_pImage->scaled(m_nImageWidth, m_nImageHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    // m_pLabel->setScaledContents(true);
    // m_pLabel->setPixmap(QPixmap::fromImage(*m_pImage));

    locker.unlock();


    mutex->lock();
    //cout<<"cameraopennum:"<<cameraopennum<<endl;

    count++;
    if(cameraopennum>3){
        if(count==2){
            if(ifexpand){
                emit sendexpandqimage(image.copy(),mutex);
                count=0;
            }else{
                emit sendqimage(image.copy(),mutex);
                count=0;
            }
        }
    }else if(cameraopennum>6){
        if(count==3){
            if(ifexpand){
                emit sendexpandqimage(image.copy(),mutex);
                count=0;
            }else{
                emit sendqimage(image.copy(),mutex);
                count=0;
            }
        }
    }else{
        if(ifexpand){
            emit sendexpandqimage(image.copy(),mutex);
            count=0;
        }else{
            emit sendqimage(image.copy(),mutex);
            count=0;
        }
    }
    mutex->unlock();


}
void CGXBitmap2::__DrawImg2(uchar* pBuffer)
{
    locker.lockForRead();
    //    if (m_pImage != NULL)
    //    {
    //        delete m_pImage;
    //        m_pImage = NULL;
    //    }
    //    //数据转换
    //    m_pImage = new QImage(pBuffer, m_nImageWidth, m_nImageHeight, QImage::Format_Indexed8);

    //    // 不失真缩放
    //    m_pImage->scaled(m_nImageWidth, m_nImageHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QImage image=QImage((const uchar*)(pBuffer), m_nImageWidth, m_nImageHeight, QImage::Format_Indexed8);
    image.scaled(m_nImageWidth, m_nImageHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    // m_pLabel->setScaledContents(true);
    // m_pLabel->setPixmap(QPixmap::fromImage(*m_pImage));
    if(NUM==1){

        QPainter painter(&image);
        QPen pen;
        pen.setColor(QColor(58, 58, 255));
        pen.setWidth(2);
        painter.setPen(pen);
        painter.drawRect(0,0,100,100);
    }
    locker.unlock();


    mutex->lock();

    count++;
    if(cameraopennum>3){
        if(count==3){
            if(ifexpand){
                emit sendexpandqimage(image.copy(),mutex);
                count=0;
            }else{
                emit sendqimage(image.copy(),mutex);
                count=0;
            }
        }
    }else if(cameraopennum>6){
        if(count==3){
            if(ifexpand){
                emit sendexpandqimage(image.copy(),mutex);
                count=0;
            }else{
                emit sendqimage(image.copy(),mutex);
                count=0;
            }
        }
    }else{
        if(count==3){
            if(ifexpand){

                emit sendexpandqimage(image.copy(),mutex);
                count=0;
            }else{
                emit sendqimage(image.copy(),mutex);
                count=0;
            }
        }
    }

    mutex->unlock();

}
//----------------------------------------------------------------------------------
/**
\brief     计算宽度所占的字节数
\param     nWidth  图像宽度
\param     bIsColor  是否是彩色相机
\return    图像一行所占的字节数
*/
//----------------------------------------------------------------------------------
int64_t CGXBitmap2::__GetStride(int64_t nWidth, bool bIsColor)
{
    return bIsColor ? nWidth * 3 : nWidth;
}

//----------------------------------------------------------------------------------
/**
\brief     用于显示图像
\param     objCImageDataPointer  图像数据对象
\return    无
*/
//----------------------------------------------------------------------------------
void CGXBitmap2::Show(CImageDataPointer& objCImageDataPointer)
{
    // SaveBmp(objCImageDataPointer,"C:/Users/ZF/Desktop/zefeng/1.bmp");
    GX_VALID_BIT_LIST emValidBits = GX_BIT_0_7;
    uchar* pBuffer = NULL;

    if (objCImageDataPointer.IsNull())
    {
        throw std::runtime_error("NULL pointer dereferenced");
    }

    //    double time_1 = 0;
    //    LARGE_INTEGER nFreq;
    //    LARGE_INTEGER nBeginTime;
    //    LARGE_INTEGER nEndTime;
    //    QueryPerformanceFrequency(&nFreq);
    //    QueryPerformanceCounter(&nBeginTime);

    //    SaveBmp(objCImageDataPointer,"C:/Users/Administrator/Desktop/image/1.bmp");
    //    QueryPerformanceCounter(&nEndTime);//停止计时
    //    time_1 = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;//计算程序执行时间单位为s*/
    //     << "The run time is:" << time_1 * 1000 << "ms" << endl;

    //检查图像是否改变并更新Buffer
    __UpdateBitmap(objCImageDataPointer);

    emValidBits = GetBestValudBit(objCImageDataPointer->GetPixelFormat());
    if (m_bIsColor)
    {

        pBuffer = (uchar*)objCImageDataPointer->ConvertToRGB24(emValidBits, GX_RAW2RGB_NEIGHBOUR, true);
        __DrawImg(pBuffer);
    }
    else
    {

        if (__IsPixelFormat8(objCImageDataPointer->GetPixelFormat()))
        {

            pBuffer = (uchar*)objCImageDataPointer->GetBuffer();
        }
        else
        {

            pBuffer = (uchar*)objCImageDataPointer->ConvertToRaw8(emValidBits);
        }

        __DrawImg2(pBuffer);
    }

}

//----------------------------------------------------------------------------------
/**
\brief     用于图像处理后并显示图像
\param     objCfg  图像处理调节参数对象
\param     objCImageDataPointer  图像数据对象
\return    无
*/
//----------------------------------------------------------------------------------
void CGXBitmap2::ShowImageProcess(CImageProcessConfigPointer& objCfg, CImageDataPointer& objCImageDataPointer)
{
    if ((objCfg.IsNull()) || (objCImageDataPointer.IsNull()))
    {
        throw std::runtime_error("NULL pointer dereferenced");
    }

    //检查图像是否改变并更新Buffer
    __UpdateBitmap(objCImageDataPointer);

    BYTE* pBuffer = (BYTE*)objCImageDataPointer->ImageProcess(objCfg);

    if (m_bIsColor)
    {
        __DrawImg(pBuffer);
    }
    else
    {
        // 黑白相机需要翻转数据后显示
        for (int i = 0; i < m_nImageHeight; i++)
        {
            memcpy(m_pImageBuffer + i * m_nImageWidth, pBuffer + (m_nImageHeight - i - 1) * m_nImageWidth, (size_t)m_nImageWidth);
        }

        __DrawImg(m_pImageBuffer);
    }
}
//----------------------------------------------------------------------------------
/**
\brief     存储Bmp图像
\param     objCImageDataPointer  图像数据对象
\param     strFilePath  显示图像文件名
\return    无
*/
//----------------------------------------------------------------------------------
void CGXBitmap2::SaveBmp(CImageDataPointer& objCImageDataPointer, const std::string& strFilePath)
{
    cout<<"aaaaa"<<endl;
    GX_VALID_BIT_LIST emValidBits = GX_BIT_0_7;
    uchar* pBuffer = NULL;

    if ((objCImageDataPointer.IsNull()) || (strFilePath == ""))
    {
        throw std::runtime_error("Argument is error");
    }

    //检查图像是否改变并更新Buffer
    __UpdateBitmap(objCImageDataPointer);

    emValidBits = GetBestValudBit(objCImageDataPointer->GetPixelFormat());

    if (m_bIsColor)
    {
        pBuffer = (uchar*)objCImageDataPointer->ConvertToRGB24(emValidBits, GX_RAW2RGB_NEIGHBOUR, true);
    }
    else
    {
        if (__IsPixelFormat8(objCImageDataPointer->GetPixelFormat()))
        {
            pBuffer = (uchar*)objCImageDataPointer->GetBuffer();
        }
        else
        {
            pBuffer = (uchar*)objCImageDataPointer->ConvertToRaw8(emValidBits);
        }
        // 黑白相机需要翻转数据后显示
        for (int i = 0; i < m_nImageHeight; i++)
        {
            memcpy(m_pImageBuffer + i * m_nImageWidth, pBuffer + (m_nImageHeight - i - 1) * m_nImageWidth, (size_t)m_nImageWidth);
        }
        pBuffer = m_pImageBuffer;
    }

    DWORD		         dwImageSize = (DWORD)(__GetStride(m_nImageWidth, m_bIsColor) * m_nImageHeight);
    BITMAPFILEHEADER     stBfh = { 0 };
    DWORD		         dwBytesRead = 0;

    stBfh.bfType = (WORD)'M' << 8 | 'B';			 //定义文件类型
    stBfh.bfOffBits = m_bIsColor ? sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER)
                                 : sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + (256 * 4);	//定义文件头大小true为彩色,false为黑白
    stBfh.bfSize = stBfh.bfOffBits + dwImageSize; //文件大小

    DWORD dwBitmapInfoHeader = m_bIsColor ? sizeof(BITMAPINFOHEADER)
                                          : sizeof(BITMAPINFOHEADER) + (256 * 4);	//定义BitmapInfoHeader大小true为彩色,false为黑白

    //创建文件
    HANDLE hFile = ::CreateFile(stringToLPCWSTR(strFilePath),
                                GENERIC_WRITE,
                                0,
                                NULL,
                                CREATE_ALWAYS,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);

    if (hFile == INVALID_HANDLE_VALUE)
    {
        throw std::runtime_error("Handle is invalid");
    }

    ::WriteFile(hFile, &stBfh, sizeof(BITMAPFILEHEADER), &dwBytesRead, NULL);
    ::WriteFile(hFile, m_pBmpInfo, dwBitmapInfoHeader, &dwBytesRead, NULL); //黑白和彩色自适应
    ::WriteFile(hFile, pBuffer, dwImageSize, &dwBytesRead, NULL);

    CloseHandle(hFile);
}
//----------------------------------------------------------------------------------
/**
\brief     存储Raw图像
\param     objCImageDataPointer  图像数据对象
\param     strFilePath  显示图像文件名
\return    无
*/
//----------------------------------------------------------------------------------
void CGXBitmap2::SaveRaw(CImageDataPointer& objCImageDataPointer, const std::string& strFilePath)
{
    if ((objCImageDataPointer.IsNull()) || (strFilePath == ""))
    {
        throw std::runtime_error("Argument is error");
    }

    //检查图像是否改变并更新Buffer
    __UpdateBitmap(objCImageDataPointer);

    DWORD   dwImageSize = (DWORD)objCImageDataPointer->GetPayloadSize();  // 写入文件的长度
    DWORD   dwBytesRead = 0;                // 文件读取的长度

    BYTE* pbuffer = (BYTE*)objCImageDataPointer->GetBuffer();
    if (!m_bIsColor)
    {
        // 黑白相机需要翻转数据后显示
        for (int i = 0; i < m_nImageHeight; i++)
        {
            memcpy(m_pImageBuffer + i * m_nImageWidth, pbuffer + (m_nImageHeight - i - 1) * m_nImageWidth, (size_t)m_nImageWidth);
        }
        pbuffer = m_pImageBuffer;
    }

    // 创建文件
    HANDLE hFile = ::CreateFile(stringToLPCWSTR(strFilePath),
                                GENERIC_WRITE,
                                FILE_SHARE_READ,
                                NULL,
                                CREATE_ALWAYS,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);

    if (hFile == INVALID_HANDLE_VALUE)   // 创建失败则返回
    {
        throw std::runtime_error("Handle is invalid");
    }
    else                                 // 保存Raw图像
    {
        ::WriteFile(hFile, pbuffer, dwImageSize, &dwBytesRead, NULL);
        CloseHandle(hFile);
    }
}
//----------------------------------------------------------------------------------
/**
\brief     是否支持彩色
\param     objCGXDevicePointer  [in]    设备句柄
\param     bIsColorFilter       [out]   是否支持彩色
\return
*/
//----------------------------------------------------------------------------------
void CGXBitmap2::__IsSupportColor(CGXDevicePointer& objCGXDevicePointer, bool &bIsColorFilter)
{
    GX_STATUS emStatus = GX_STATUS_SUCCESS;
    bool      bIsImplemented = false;
    bool      bIsMono = false;
    gxstring  strPixelFormat = "";

    strPixelFormat = objCGXDevicePointer->GetRemoteFeatureControl()->GetEnumFeature("PixelFormat")->GetValue();
    strPixelFormat.substr(0, 4);

    if (0 == memcmp(strPixelFormat.c_str(), "Mono", 4))
    {
        bIsMono = true;
    }
    else
    {
        bIsMono = false;
    }

    bIsImplemented = objCGXDevicePointer->GetRemoteFeatureControl()->IsImplemented("PixelColorFilter");

    // 若当前为非黑白且支持PixelColorFilter则为彩色
    if ((!bIsMono) && (bIsImplemented))
    {

        bIsColorFilter = true;
    }
    else
    {

        bIsColorFilter = false;
    }
}

LPCWSTR CGXBitmap2::stringToLPCWSTR(std::string orig)
{
    size_t origsize = orig.length() + 1;
    const size_t newsize = 100;
    size_t convertedChars = 0;
    wchar_t* wcstring = (wchar_t*)malloc(sizeof(wchar_t) * (orig.length() - 1));
    mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);

    return wcstring;
}



void CGXBitmap2::getimage(CImageDataPointer &objImageDataPointer)
{
    Show(objImageDataPointer);
    // cout<<"aaa:"<<QThread::currentThreadId()<<endl;
    // SaveBmp(objImageDataPointer,"D:/qt/project/PogopinCcd/release/image/1.bmp");

}

