#ifndef APP_H
#define APP_H

#include <QObject>
#include<datevar.h>

class APP : public QObject
{
    Q_OBJECT
public:
    //校准配置文件
    static QString ConfigName1;              //配置文件路径
    static QString ConfigName2;              //路径

signals:

};

#endif // APP_H
