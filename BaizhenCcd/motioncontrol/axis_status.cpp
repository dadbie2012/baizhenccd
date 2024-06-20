#include "axis_status.h"
#include "ui_axis_status.h"

const QString SheetStyle_red = QString("background-color: rgb(255, 0, 0);");
const QString SheetStyle_green = QString("background-color: rgb(0, 255, 0);");
const QString SheetStyle_degreen = QString("background-color: rgb(34, 104, 51);");
const QString SheetStyle_blue = QString("background-color: rgb(0, 0, 255);");

axis_status::axis_status(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::axis_status)
{
    ui->setupUi(this);

    lab_ax_state<<ui->label_STA_AxDisable<<ui->label_STA_AxReady<<ui->label_STA_Stopping<<ui->label_STA_AxErrorStop
               <<ui->label_STA_AxHoming<<ui->label_STA_AxPtpMotion<<ui->label_STA_AxContiMotion<<ui->label_STA_AxSyncMotion
              <<ui->label_STA_AX_EXT_JOG<<ui->label_STA_AX_EXT_MPG;
    lab_ax_motionstate<<ui->label_Stop<<ui->label_Res1<<ui->label_WaitERC<<ui->label_Res2
                     <<ui->label_CorrectBksh<<ui->label_Res3<<ui->label_InFA<<ui->label_InFL
                    <<ui->label_InACC<<ui->label_InFH<<ui->label_InDEC<<ui->label_WaitINP;
    lab_ax_iostate<<ui->label_RDY<<ui->label_ALM<<ui->label_LMT_positive<<ui->label_LMT_negative
                 <<ui->label_ORG<<ui->label_DIR<<ui->label_EMG<<ui->label_PCS
                <<ui->label_ERC<<ui->label_EZ<<ui->label_CLR<<ui->label_LTC
               <<ui->label_SD<<ui->label_INP<<ui->label_SVON<<ui->label_ALRM
              <<ui->label_SLMT_positive<<ui->label_SLMT_negative<<ui->label_CMP<<ui->label_CAMDO;
}

axis_status::~axis_status()
{
    delete ui;
}

void axis_status::change_state_clear()
{
    for (int i=0;i<lab_ax_state.count();i++) {
        lab_ax_state.at(i)->setStyleSheet(SheetStyle_degreen);
    }
}

void axis_status::change_state(int state)
{
    if(state<0||state>=lab_ax_state.count())
    {
        return;
    }
    lab_ax_state.at(state)->setStyleSheet(SheetStyle_green);
}

void axis_status::change_motionstate_clear()
{
    for (int i=0;i<lab_ax_motionstate.count();i++) {
        lab_ax_motionstate.at(i)->setStyleSheet(SheetStyle_degreen);
    }
}

void axis_status::change_motionstate(int state)
{
    if(state<0||state>=lab_ax_motionstate.count())
    {
        return;
    }
    lab_ax_motionstate.at(state)->setStyleSheet(SheetStyle_green);
}

void axis_status::change_iostate_clear()
{
    for (int i=0;i<lab_ax_iostate.count();i++) {
        lab_ax_iostate.at(i)->setStyleSheet(SheetStyle_degreen);
    }
}

void axis_status::change_iostate(int state)
{
    if(state<0||state>=lab_ax_iostate.count())
    {
        return;
    }
    lab_ax_iostate.at(state)->setStyleSheet(SheetStyle_green);
}
