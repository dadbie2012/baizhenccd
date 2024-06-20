#include "autofocusthread.h"

AutofocusThread::AutofocusThread(int num)
{
biaoji=num;
//getautofocusroirect(Rect(400,1540,400,400));
}
void AutofocusThread::run(){
   //  cout << "xianchengkaishi"<<endl;

    autorun=true;
    Autofocus_image_definition.clear();
    Autofocus_time.clear();
    while(autorun){
        if(buffer.empty()){
            Sleep(20);
        }else {
                void* pRGB24Buffer = buffer.front()->ConvertToRaw8(GX_BIT_0_7);
                Mat image = cv::Mat::zeros(cv::Size(buffer.front()->GetWidth(), buffer.front()->GetHeight()), CV_8UC1);
                memcpy(image.data, pRGB24Buffer, buffer.front()->GetWidth() *  buffer.front()->GetHeight());
                Mat ROI_img(image, imageroi);


                if(biaoji==1){
                   Autofocus_image_definition.push_back(ImageDefinitionBrenner(ROI_img));
                  // cout<<"aaa"<<endl;
                }else if(biaoji==2){
                    Autofocus_image_definition.push_back(ImageDefinitionxiangsu(ROI_img));
                }

                buffer.pop();
          //  cout<<"autofocusjianshaoshuliang"<<buffer.size()<<endl;




        }




    }
   //cout << "xianchengjieshu"<<endl;
    quit();

}
void AutofocusThread::getautodate(QDateTime time,CImageDataPointer & objImageDataPointer){

    //cout << "autofocus:"<<time.toString("yyyy-MM-dd hh:mm:ss:zzz").toStdString()<<endl;
    Autofocus_time.push_back(time);
    buffer.push(objImageDataPointer);
   // cout<<"bbb"<<endl;
  //  cout << "autobufferzengjiasize:"<<buffer.size()<<endl;

}

double AutofocusThread::ImageDefinitionBrenner(cv::Mat &image)
{
    //assert(image.empty());

    /*cv::Mat gray_img;
    if (image.channels() == 3) {
        cv::cvtColor(image, gray_img, CV_BGR2GRAY);
    }*/
  int count = 0;
    double result = .0f;
    for (int i = 0; i < image.rows; ++i) {
        uchar *data = image.ptr<uchar>(i);
        for (int j = 0; j < image.cols; ++j) {
            result += pow(data[j + 2] - data[j], 2);
            if(data[j]>100){
                count ++;
            }

        }
    }
//    if(count<700){
//        return 0;
//    }
  //  cout<<result / image.total()<<endl;
    return result / image.total();
}
double AutofocusThread::ImageDefinitionxiangsu(Mat &image)
{
    int result = .0f;
    for (int i = 0; i < image.rows; ++i) {
        uchar *data = image.ptr<uchar>(i);
        for (int j = 0; j < image.cols; ++j) {
            if(data[j]>100){
                result ++;
            }

        }
    }
    cout<<result<<endl;
    return result ;
}

double AutofocusThread::ImageDefinitionconnect(Mat &gray_img)
{
    threshold(gray_img,gray_img,180,255,cv::THRESH_BINARY);
    if(gray_img.channels()!=3){

        //        cvtColor(dst, dst, COLOR_GRAY2RGB);
        cvtColor(gray_img,gray_img,COLOR_BGR2RGB);
    }
    Mat img8bit = Mat::zeros(Size(gray_img.cols, gray_img.rows), CV_8UC1);
    for (int i = 0; i < gray_img.rows; i++)
    {
        uchar* data = gray_img.ptr<uchar>(i);
        for (int j = 0; j < gray_img.cols * 3; j = j + 3)
        {
            img8bit.at<uchar>(i, j / 3) = data[j];
        }
    }

    RNG rng(10086);
    Mat out,stats,centroids;
    int number=connectedComponentsWithStats(img8bit,out,stats,centroids,8,CV_16U);
   // cout<<"number:"<<number<<endl;
    vector<Vec3b>colors;
    for(int i=0;i<number;i++){
        Vec3b vec3=Vec3b(rng.uniform(0,256),rng.uniform(0,256),rng.uniform(0,256));
        colors.push_back(vec3);

    }
    Mat result2=Mat::zeros(gray_img.size(),gray_img.type());
    int w=result2.cols;
    int h=result2.rows;
    int centerx=0;
    int centery=0;

    for(int i=1;i<number;i++){
        int center_x=centroids.at<double>(i,0);
        int center_y=centroids.at<double>(i,1);
        double x=stats.at<int>(i,CC_STAT_LEFT);
        double y=stats.at<int>(i,CC_STAT_TOP);
        int w=stats.at<int>(i,CC_STAT_WIDTH);
        int h=stats.at<int>(i,CC_STAT_HEIGHT);
        int area=stats.at<int>(i,CC_STAT_AREA);


        if(area>1000&&area<3000){

            circle(gray_img,Point(center_x,center_y),2,Scalar(0,255,0),2,8,0);
            Rect rect(x,y,w,h);
            rectangle(gray_img,rect,colors[i],3,8,0);
            putText(gray_img,format("%d",i),Point(center_x,center_y),FONT_HERSHEY_SIMPLEX,1,Scalar(0,0,255),1);
            cout<<",x:"<<x<<",y:"<<y<<",width:"<<w<<",height"<<h<<",area:"<<area<<" changkuanbi:"<<double(h)/double(w)<<" bilv:"<<double(area)/(double(w)*double(h))<<" all:"<<double(area)/(double(w)*double(h))+double(h)/double(w)<<endl;
            return  double(area)/(double(w)*double(h))+double(h)/double(w);


        }

    }
}
void AutofocusThread::getautofocusroirect(Rect roi)
{
    this->imageroi=roi;
     cout<<"imageroi.x"<<endl;
    cout<<imageroi.x<<endl;
    cout<<imageroi.y<<endl;
    cout<<imageroi.width<<endl;
    cout<<imageroi.height<<endl;
}
