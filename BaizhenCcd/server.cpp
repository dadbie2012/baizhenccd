#include "server.h"
#include "ui_server.h"

Server::Server(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->spinBox->setRange(0,10000);
    ui->spinBox->setValue(900);
}

Server::~Server()
{
    delete ui;
}
