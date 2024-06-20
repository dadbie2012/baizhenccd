#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QtNetwork>
#include<iostream>
using namespace std;
namespace Ui {
class Server;
}

class Server : public QWidget
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

private:
    Ui::Server *ui;
};

#endif // SERVER_H
