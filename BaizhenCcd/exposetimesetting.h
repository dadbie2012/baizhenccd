#ifndef EXPOSETIMESETTING_H
#define EXPOSETIMESETTING_H

#include <QMainWindow>
#include<datevar.h>
#include<QSettings>
#include<QMessageBox>

namespace Ui {
class exposetimesetting;
}

class exposetimesetting : public QMainWindow
{
    Q_OBJECT

public:
    explicit exposetimesetting(QWidget *parent = nullptr);
    ~exposetimesetting();
    int num;
    Ui::exposetimesetting *ui;
    void exposetimeget(int id);
private slots:
    void on_pushButton_clicked();
};

#endif // EXPOSETIMESETTING_H
