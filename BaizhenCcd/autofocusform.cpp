#include "autofocusform.h"
#include "ui_autofocusform.h"
#include<datevar.h>
extern VisionDaHengCamera *camera_1;
extern VisionDaHengCamera *camera_2;

AutofocusForm::AutofocusForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AutofocusForm)
{
    ui->setupUi(this);
    init();
    initstatic();
    buttonGroup= new QButtonGroup();
    buttonGroup->addButton(ui->radioButton,1);
    buttonGroup->addButton(ui->radioButton_2,2);
    connect(buttonGroup, SIGNAL(buttonToggled(int,bool)), this, SLOT(cam1_linebutton(int,bool)));
}

AutofocusForm::~AutofocusForm()
{
    delete ui;
}

void AutofocusForm::init()
{
    double autoparameter_1[15]{0};
    double autoparameter_2[15]{0};
    QSettings settings("./AutoFocus.ini",QSettings::IniFormat);
    if(cam_biaoji==1){
        int num =  settings.beginReadArray("cam1_1");
        for (int j = 0; j < 15; ++j) {
            settings.setArrayIndex(j);
            autoparameter_1[j]=settings.value("cam1", "0").toDouble();
            //std::cout<<"array[i][j]"<<settings.value("cam1", "0").toDouble()<<std::endl;
        }
        settings.endArray();
    }else{
        int num =  settings.beginReadArray("cam2_2");
        for (int j = 0; j < 15; ++j) {
            settings.setArrayIndex(j);
            autoparameter_1[j]=settings.value("cam2", "0").toDouble();
            //std::cout<<"array[i][j]"<<settings.value("cam2", "0").toDouble()<<std::endl;
        }
        settings.endArray();
    }

    ui->ROI_start_x->setText(QString::number(autoparameter_1[0]));
    ui->ROI_start_y->setText(QString::number(autoparameter_1[1]));
    ui->ROI_width->setText(QString::number(autoparameter_1[2]));
    ui->ROI_height->setText(QString::number(autoparameter_1[3]));
    if(autoparameter_1[4]==1){
        ui->radioButton->click();
    }else{
        ui->radioButton_2->click();
    }
    ui->function_choose->setCurrentIndex(autoparameter_1[5]-1);
    ui->startposition->setText(QString::number(autoparameter_1[6]));
    ui->updistance->setText(QString::number(autoparameter_1[7]));
    ui->uptime->setText(QString::number(autoparameter_1[8]));
    ui->downdistance->setText(QString::number(autoparameter_1[9]));
    ui->downtime->setText(QString::number(autoparameter_1[10]));
    ui->returntime->setText(QString::number(autoparameter_1[11]));
    ui->jixiebuchang->setText(QString::number(autoparameter_1[12]));
    ui->fenshuyuzhi->setText(QString::number(autoparameter_1[13]));
    if(autoparameter_1[14]==1){
        ui->hanshunihe->setChecked(true);
    }else{
        ui->hanshunihe->setChecked(false);
    }






}

void AutofocusForm::initstatic()
{
    double autoparameter_1[15]{0};
    double autoparameter_2[15]{0};
    QSettings settings("./AutoFocus.ini",QSettings::IniFormat);

    int num =  settings.beginReadArray("cam1_1");
    for (int j = 0; j < 15; ++j) {
        settings.setArrayIndex(j);
        autoparameter_1[j]=settings.value("cam1", "0").toDouble();
        //std::cout<<"array[i][j]"<<settings.value("cam1", "0").toDouble()<<std::endl;
    }
    settings.endArray();
    DateVar::autofocusroi_1_start_x=autoparameter_1[0];
    DateVar::autofocusroi_1_start_y=autoparameter_1[1];
    DateVar::autofocusroi_1_width=autoparameter_1[2];
    DateVar::autofocusroi_1_height=autoparameter_1[3];
    DateVar::autofocusfunction_1=autoparameter_1[5];
    DateVar::autofocuspositioncankao_1=autoparameter_1[4];
    DateVar::autofocusstartposition_1=autoparameter_1[6];
    DateVar::autofocusupdistance_1=autoparameter_1[7];
    DateVar::autofocusuptime_1=autoparameter_1[8];
    DateVar::autofocusdowndistance_1=autoparameter_1[9];
    DateVar::autofocusdowntime_1=autoparameter_1[10];
    DateVar::autofocusreturntime_1=autoparameter_1[11];
    DateVar::autofocusjixiebuchang_1=autoparameter_1[12];
    DateVar::autofocusfenshuyuzhi_1=autoparameter_1[13];
    DateVar::autofocusifnihe_1=autoparameter_1[14];


    num =  settings.beginReadArray("cam2_2");
    for (int j = 0; j < 15; ++j) {
        settings.setArrayIndex(j);
        autoparameter_2[j]=settings.value("cam2", "0").toDouble();
        //std::cout<<"array[i][j]"<<settings.value("cam1", "0").toDouble()<<std::endl;
    }
    settings.endArray();
    DateVar::autofocusroi_2_start_x=autoparameter_2[0];
    DateVar::autofocusroi_2_start_y=autoparameter_2[1];
    DateVar::autofocusroi_2_width=autoparameter_2[2];
    DateVar::autofocusroi_2_height=autoparameter_2[3];
    DateVar::autofocusfunction_2=autoparameter_2[5];
    DateVar::autofocuspositioncankao_2=autoparameter_2[4];
    DateVar::autofocusstartposition_2=autoparameter_2[6];
    DateVar::autofocusupdistance_2=autoparameter_2[7];
    DateVar::autofocusuptime_2=autoparameter_2[8];
    DateVar::autofocusdowndistance_2=autoparameter_2[9];
    DateVar::autofocusdowntime_2=autoparameter_2[10];
    DateVar::autofocusreturntime_2=autoparameter_2[11];
    DateVar::autofocusjixiebuchang_2=autoparameter_2[12];
    DateVar::autofocusfenshuyuzhi_2=autoparameter_2[13];
    DateVar::autofocusifnihe_2=autoparameter_2[14];
    cout<<DateVar::autofocusroi_2_start_x<<endl;
    cout<<DateVar::autofocusroi_2_start_y<<endl;
    cout<<DateVar::autofocusroi_2_width<<endl;
    cout<<DateVar::autofocusroi_2_height<<endl;
    cout<<DateVar::autofocusfunction_2<<endl;
    cout<<DateVar::autofocuspositioncankao_2<<endl;
    cout<<DateVar::autofocusstartposition_2<<endl;
    cout<<DateVar::autofocusupdistance_2<<endl;
    cout<<DateVar::autofocusuptime_2<<endl;
    cout<<DateVar::autofocusdowndistance_2<<endl;
    cout<<DateVar::autofocusdowntime_2<<endl;
    cout<<DateVar::autofocusreturntime_2<<endl;
    cout<<DateVar::autofocusjixiebuchang_2<<endl;
    cout<<DateVar::autofocusfenshuyuzhi_2<<endl;
    cout<<DateVar::autofocusifnihe_2<<endl;
}

void AutofocusForm::on_save_clicked()
{
    QMessageBox::information(this,"info","The setting of the line is successful");
    QSettings settings("./AutoFocus.ini",QSettings::IniFormat);
    settings.setIniCodec("utf-8");
    double array[15]={ui->ROI_start_x->text().toInt(),ui->ROI_start_y->text().toInt(),ui->ROI_width->text().toInt(),ui->ROI_height->text().toInt(),
                      positioncankao,autofunction,ui->startposition->text().toDouble(), ui->updistance->text().toDouble(),
                      ui->uptime->text().toDouble(),ui->downdistance->text().toDouble(),ui->downtime->text().toDouble(),
                      ui->returntime->text().toDouble(),ui->jixiebuchang->text().toDouble(), ui->fenshuyuzhi->text().toDouble(),ui->hanshunihe->isChecked()};
    if(cam_biaoji==1){
        settings.beginWriteArray("cam1_"+QString::number(cam_biaoji));
        for (int j = 0; j < 15; ++j) {
            settings.setArrayIndex(j);
            settings.setValue("cam1", array[j]);

        }
        settings.endArray();
        DateVar::autofocusroi_1_start_x=ui->ROI_start_x->text().toInt();
        DateVar::autofocusroi_1_start_y=ui->ROI_start_y->text().toInt();
        DateVar::autofocusroi_1_width=ui->ROI_width->text().toInt();
        DateVar::autofocusroi_1_height=ui->ROI_height->text().toInt();
        DateVar::autofocusfunction_1=autofunction;
        DateVar::autofocuspositioncankao_1=positioncankao;
        DateVar::autofocusstartposition_1=ui->startposition->text().toDouble();
        DateVar::autofocusupdistance_1=ui->updistance->text().toDouble();
        DateVar::autofocusdowndistance_1=ui->downdistance->text().toDouble();
        DateVar::autofocusuptime_1= ui->uptime->text().toDouble();
        DateVar::autofocusdowntime_1=ui->downtime->text().toDouble();
        DateVar::autofocusreturntime_1=ui->returntime->text().toDouble();
        DateVar::autofocusjixiebuchang_1=ui->jixiebuchang->text().toDouble();
        DateVar::autofocusfenshuyuzhi_1= ui->fenshuyuzhi->text().toDouble();
        DateVar::autofocusifnihe_1=ui->hanshunihe->isChecked();
        return;
    }else if(cam_biaoji==2){
        settings.beginWriteArray("cam2_"+QString::number(cam_biaoji));
        for (int j = 0; j < 15; ++j) {
            settings.setArrayIndex(j);
            settings.setValue("cam2", array[j]);

        }
        settings.endArray();
        DateVar::autofocusroi_2_start_x=ui->ROI_start_x->text().toInt();
        DateVar::autofocusroi_2_start_y=ui->ROI_start_y->text().toInt();
        DateVar::autofocusroi_2_width=ui->ROI_width->text().toInt();
        DateVar::autofocusroi_2_height=ui->ROI_height->text().toInt();
        DateVar::autofocusfunction_2=autofunction;
        DateVar::autofocuspositioncankao_2=positioncankao;
        DateVar::autofocusstartposition_2=ui->startposition->text().toDouble();
        DateVar::autofocusupdistance_2=ui->updistance->text().toDouble();
        DateVar::autofocusdowndistance_2=ui->downdistance->text().toDouble();
        DateVar::autofocusuptime_2= ui->uptime->text().toDouble();
        DateVar::autofocusdowntime_2=ui->downtime->text().toDouble();
        DateVar::autofocusreturntime_2=ui->returntime->text().toDouble();
        DateVar::autofocusjixiebuchang_2=ui->jixiebuchang->text().toDouble();
        DateVar::autofocusfenshuyuzhi_2= ui->fenshuyuzhi->text().toDouble();
        DateVar::autofocusifnihe_2=ui->hanshunihe->isChecked();
        return;

    }
}

void AutofocusForm::on_camerachoose_currentIndexChanged(int index)
{
    cam_biaoji=index+1;
    init();


}

void AutofocusForm::cam1_linebutton(int num, bool bo)
{
    positioncankao=num;
    cout<<positioncankao<<endl;


}

void AutofocusForm::on_function_choose_currentIndexChanged(int index)
{
    autofunction=index+1;
}



void AutofocusForm::on_showimage_clicked()
{
    if(cam_biaoji==1){
        if(!camera_1->image.data){
            QMessageBox::critical(this,"critical","image is empty!");
        }else{
            Sourceimage=camera_1->image.clone();
            QImage  imgForDisplay = QImage((const uchar*)(Sourceimage.data), Sourceimage.cols, Sourceimage.rows, Sourceimage.cols * Sourceimage.channels(), QImage::Format_Indexed8);
            ui->form->setScaledContents(true);
            ui->form->setPixmap(QPixmap::fromImage(imgForDisplay));
            QMessageBox::information(this,"info","show image succeed!");

        }
    }else if(cam_biaoji==2){
        if(!camera_2->image.data){
            QMessageBox::critical(this,"critical","image is empty!");
        }else{
            Sourceimage=camera_2->image.clone();
            QImage  imgForDisplay = QImage((const uchar*)(Sourceimage.data), Sourceimage.cols, Sourceimage.rows, Sourceimage.cols * Sourceimage.channels(), QImage::Format_Indexed8);
            ui->form->setScaledContents(true);
            ui->form->setPixmap(QPixmap::fromImage(imgForDisplay));
            QMessageBox::information(this,"info","show image succeed!");
        }
    }
}

void AutofocusForm::on_showroi_clicked()
{
    if(!Sourceimage.data){
        QMessageBox::critical(this,"critical","sourceimage is empty!");
    }else{
        Mat roi=Sourceimage.clone();
        cvtColor(roi,roi,COLOR_BGR2RGB);
        //cv::rectangle(roi,Rect(ui->ROI_start_x->text().toDouble(),ui->ROI_start_y->text().toDouble(),ui->ROI_width->text().toDouble(),ui->ROI_height->text().toDouble(),1),cv::Scalar(38, 255,255),1,LINE_8,0);
        cv::rectangle(roi,Rect(ui->ROI_start_x->text().toDouble(),ui->ROI_start_y->text().toDouble(),ui->ROI_width->text().toDouble(),ui->ROI_height->text().toDouble()),cv::Scalar(255, 0,0),5,LINE_8,0);
        QImage  imgForDisplay = QImage((const uchar*)(roi.data), roi.cols, roi.rows, roi.cols * roi.channels(), QImage::Format_RGB888);
        QPixmap pixmap = QPixmap::fromImage(imgForDisplay);
        int with = imgForDisplay.width();
        int height = imgForDisplay.height();
        QPixmap fitpixmap = pixmap.scaled(with, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        // ui->form->setScaledContents(true);
        ui->form->setPixmap(fitpixmap);
        QMessageBox::information(this,"info","show image succeed!");

    }
}

void AutofocusForm::on_pushButton_clicked()
{

    std::string pattern_jpg;
    std::vector<cv::String> image_files;
    cout << "image_files[ii]" << endl;
    pattern_jpg = "C:/qt/QtprojectOfficial/BaizhenCcd/release/image/2024-04-08/unsame/*.bmp";
    cv::glob(pattern_jpg, image_files);
    for(int ii=0;ii<image_files.size();ii++)
    {


        cout<<image_files[ii]<<endl;
        cv::Mat lap_image;

        cv::Mat gray_img, smd_image_x, smd_image_y, G;

        gray_img=imread(image_files[ii],0);


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



            }

        }


    }

}
