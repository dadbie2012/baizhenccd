#ifndef AXIS_STATUS_H
#define AXIS_STATUS_H

#include <QWidget>
#include <QDebug>
#include <QLabel>
#include<datevar.h>
namespace Ui {
class axis_status;
}

class axis_status : public QWidget
{
    Q_OBJECT

public:
    explicit axis_status(QWidget *parent = nullptr);
    ~axis_status();

    void change_state_clear();
    void change_state(int state);

    void change_motionstate_clear();
    void change_motionstate(int state);

    void change_iostate_clear();
    void change_iostate(int state);

private:
    Ui::axis_status *ui;

    QList <QLabel*> lab_ax_state;
    QList <QLabel*> lab_ax_motionstate;
    QList <QLabel*> lab_ax_iostate;
};

#endif // AXIS_STATUS_H
