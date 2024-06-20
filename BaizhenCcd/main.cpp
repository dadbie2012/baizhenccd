#include "visionmainwindow.h"
#pragma execution_character_set("utf-8")
#include <QApplication>
#include<QFile>
#include <QtDebug>
#include <QFile>
#include <QTextStream>
void outputMessage2file(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd");
    QString folderPath =QApplication::applicationDirPath()+"/log/"+time+"_log.txt";
    //cout<<folderPath.toStdString()<<endl;
    QFile file(folderPath);
    if(!file.exists()){
       file.open(QFile::WriteOnly|QFile::Text|QIODevice::Append);
    }
    static QMutex mutex;
    mutex.lock();
    QString text;
    switch(type)
    {
        //case QtDebugMsg: text = QString("Debug:"); break;
      //  case QtWarningMsg: text = QString("Warning:"); break;
        case QtCriticalMsg: text = QString("Critical:"); break;
        case QtFatalMsg: text = QString("Fatal:"); break;
    }
  //  QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss zzz");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3").arg(current_date).arg(text).arg(msg);
    //QFile file("C:/Users/user/Desktop/log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();
    mutex.unlock();
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QPixmap pixmap(":/image/image/pStart.png");//创建QPixmap对象，设置启动图片
    pixmap.scaled(QApplication::desktop()->availableGeometry().size(), Qt::KeepAspectRatio);
    QSplashScreen splash(pixmap);//利用QPixmap对象创建一个QSplashScreen对象
    splash.show();//显示此启动图像
    a.processEvents();//使程序在显示启动画面时仍能响应鼠标等其他事件
    QString qss;
    QFile qssFile(":/css/qss.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
      qss = QLatin1String(qssFile.readAll());
      qApp->setStyleSheet(qss);
      qssFile.close();
    }
     qInstallMessageHandler(outputMessage2file);
    VisionMainWindow w;
    w.show();
    splash.finish(&w);
    return a.exec();
}
