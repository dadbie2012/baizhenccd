      #include "motioncontrolform.h"
#include "ui_motioncontrolform.h"

const QString SheetStyle_red = QString("background-color: rgb(255, 0, 0);");
const QString SheetStyle_green = QString("background-color: rgb(0, 255, 0);");
const QString SheetStyle_degreen = QString("background-color: rgb(34, 104, 51);");
const QString SheetStyle_blue = QString("background-color: rgb(0, 0, 255);");

extern axis *axis_1;//轴
extern axis *axis_2;

extern AxisUiData Axis_UI_Data;
extern DEVICESTATE Ax_State;

QVector<QCheckBox*> AxisGroupChoose;
QVector<QLineEdit*> AxisGroupLineedit;

MotionControlForm::MotionControlForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MotionControlForm)
{
    ui->setupUi(this);
    setWindowTitle("Motion Control");
    this->ui_limit();

    qRegisterMetaType<QVector<int>>("QVector<int>");
    qRegisterMetaType<QVector<ulong>>("QVector<ulong>");
    qRegisterMetaType<QVector<double>>("QVector<double>");

    init_SensorConfigTable();
    ui->comboBox_axis_choose->setCurrentIndex(0);
    on_comboBox_axis_choose_currentIndexChanged(0);

    AxisWorkOne = new axisThreadOne();
    AxisThreadOne = new QThread();
    AxisWorkOne ->moveToThread(AxisThreadOne);
    connect(AxisThreadOne, &QThread::finished, AxisWorkOne, &QObject::deleteLater);
    connect(this, SIGNAL(sigAxisMoveRelPT(int ,double ,double ,double )), AxisWorkOne, SLOT(slotAxisMoveRelPT(int ,double ,double ,double )));
    connect(this, SIGNAL(sigAxisMoveAbsPT(int ,double ,double ,double )), AxisWorkOne, SLOT(slotAxisMoveAbsPT(int ,double ,double ,double )));
    connect(this, SIGNAL(sigAxisGroupMoveAbsPT(QVector<ulong> ,QVector<double> ,QVector<double> ,QVector<double> )), AxisWorkOne, SLOT(slotAxisGroupMoveAbsPT(QVector<ulong> ,QVector<double> ,QVector<double> ,QVector<double> )));
    AxisThreadOne ->start();

    AxisWorkTwo = new axisThreadTwo();
    AxisThreadTwo = new QThread();
    AxisWorkTwo ->moveToThread(AxisThreadTwo);
    connect(AxisThreadTwo, &QThread::finished, AxisWorkTwo, &QObject::deleteLater);
    AxisThreadTwo ->start();

    AxisWorkThree = new axisThreadThree();
    AxisThreadThree = new QThread();
    AxisWorkThree ->moveToThread(AxisThreadThree);
    connect(AxisThreadThree, &QThread::finished, AxisWorkThree, &QObject::deleteLater);
    connect(this, SIGNAL(sigDeviceOpen()), AxisWorkThree, SLOT(slotDeviceOpen()));
    connect(this, SIGNAL(sigAxisEnable(QVector<int> )), AxisWorkThree, SLOT(slotAxisEnable(QVector<int>)));
    connect(this, SIGNAL(sigAxisDisable(QVector<int> )), AxisWorkThree, SLOT(slotAxisDisable(QVector<int> )));
    connect(this, SIGNAL(sigAxisPowerOn()), AxisWorkThree, SLOT(slotAxisPowerOn()));
    connect(this, SIGNAL(sigAxisPowerOff()), AxisWorkThree, SLOT(slotAxisPowerOff()));
    connect(this, SIGNAL(sigAxisErrorAllClear()), AxisWorkThree, SLOT(slotAxisErrorAllClear()));
    connect(this, SIGNAL(sigAxisAllStop()), AxisWorkThree, SLOT(slotAxisAllStop()));
    connect(this, SIGNAL(sigAxisReset(ulong)), AxisWorkThree, SLOT(slotAxisReset(ulong)));
    connect(this, SIGNAL(sigAxisStop(ulong)), AxisWorkThree, SLOT(slotAxisStop(ulong)));
    connect(this, SIGNAL(sigAxisGohome(ulong)), AxisWorkThree, SLOT(slotAxisGohome(ulong)));
    AxisThreadThree ->start();

    axis_status_1 = new axis_status();
    axis_status_1->setAttribute(Qt::WA_QuitOnClose,false);
    axis_status_1->setWindowTitle("轴1");
    axis_status_2 = new axis_status();
    axis_status_2->setAttribute(Qt::WA_QuitOnClose,false);
    axis_status_2->setWindowTitle("轴2");

    timer_AxisRelData = new QTimer;
    connect(timer_AxisRelData,SIGNAL(timeout()),AxisWorkThree,SLOT(AxisGetAllRealData()));
    connect(timer_AxisRelData,SIGNAL(timeout()),this,SLOT(Updata_UI_Axis()));
    timer_AxisRelData->start(50);



    AxisGroupChoose<<ui->checkBox_axis_move_distance_1<<ui->checkBox_axis_move_distance_2;
    AxisGroupLineedit<<ui->lineEdit_axis_move_distance_1<<ui->lineEdit_axis_move_distance_2;

    this->setAttribute(Qt::WA_QuitOnClose, false);
}

MotionControlForm::~MotionControlForm()
{
    if(timer_AxisRelData->isActive())
    {
        timer_AxisRelData->stop();
    }
    delete timer_AxisRelData;
    AxisThreadOne->quit();
    AxisThreadOne->wait();
    AxisThreadTwo->quit();
    AxisThreadTwo->wait();
    AxisThreadThree->quit();
    AxisThreadThree->wait();
    delete ui;
}

void MotionControlForm::init_SensorConfigTable()
{
    //初始化标定传感器系数表格
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setRowCount(20);
    QStringList headerlabel;
    headerlabel<<QString("序号")<<QString("实际值")<<QString("数码值");
    ui->tableWidget->setHorizontalHeaderLabels(headerlabel);
    QHeaderView *header=ui->tableWidget->verticalHeader();
    header->setHidden(true);
    for (int j=0;j<3;j++) {
        for (int i=0;i<20;i++) {
            QTableWidgetItem *item=new QTableWidgetItem();
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setItem(i,j,item);

        }
    }
    for (int i=0;i<20;i++) {
        ui->tableWidget->item(i,0)->setText(QString::number(i));
    }
}

void MotionControlForm::ax_updata_data(axis *a, QString path)
{
    int fra_num=ui->lineEdit_info_fractional_number->text().toInt();
    double range_up=ui->lineEdit_info_range_up->text().toDouble();
    double range_down=ui->lineEdit_info_range_down->text().toDouble();
    QString units=ui->lineEdit_info_sensor_unit->text();

    a->clear_data_point();
    a->set_sensor_all_par(fra_num,range_up,range_down,units);

    for (int i=0;i<20;i++)
    {
        if((!ui->tableWidget->item(i,1)->text().isEmpty())&&(!ui->tableWidget->item(i,2)->text().isEmpty()))
        {
            a->set_data_point(ui->tableWidget->item(i,1)->text().toDouble(),ui->tableWidget->item(i,2)->text().toDouble());
        }
    }

    a->writeConfig(path);
}

void MotionControlForm::ui_limit()
{
    QIntValidator *intvalidator=new QIntValidator(-999999,999999,this);
    QDoubleValidator *doublevalidator=new QDoubleValidator(-999999,999999,3,this);
    //原始码
    ui->lineEdit_command_location_2->setReadOnly(true);
    ui->lineEdit_command_location_6->setReadOnly(true);
    ui->lineEdit_actual_position_2->setReadOnly(true);
    ui->lineEdit_actual_position_6->setReadOnly(true);
    ui->lineEdit_command_speed_2->setReadOnly(true);
    ui->lineEdit_command_speed_6->setReadOnly(true);

    //单轴控制
    ui->lineEdit_axis_relative_distance_1->setValidator(doublevalidator);
    ui->lineEdit_axis_relative_distance_2->setValidator(doublevalidator);
    ui->lineEdit_axis_relative_time_1->setValidator(doublevalidator);
    ui->lineEdit_axis_relative_time_2->setValidator(doublevalidator);

    //多轴控制 控制集合
    ui->lineEdit_axis_allmove_time->setValidator(intvalidator);
    ui->lineEdit_axis_move_distance_1->setValidator(doublevalidator);
    ui->lineEdit_axis_move_distance_2->setValidator(doublevalidator);

    //传感器标定
    ui->lineEdit_info_fractional_number->setValidator(intvalidator);
    ui->lineEdit_info_range_up->setValidator(doublevalidator);
    ui->lineEdit_info_range_down->setValidator(doublevalidator);
    ui->lineEdit_info_channel->setReadOnly(true);
    ui->lineEdit_info_sensor_name->setReadOnly(true);
    ui->lineEdit_info_sensor_unit->setReadOnly(true);
    ui->lineEdit_info_filtering_number->setReadOnly(true);
}

void MotionControlForm::on_btn_AxisStatus_2_clicked()
{
    axis_status_1->activateWindow();
    axis_status_1->show();
}

void MotionControlForm::on_btn_AxisStatus_6_clicked()
{
    axis_status_2->activateWindow();
    axis_status_2->show();
}

void MotionControlForm::on_comboBox_axis_choose_currentIndexChanged(int index)
{
    ui->tableWidget->clear();
    ui->lineEdit_info_channel->clear();
    ui->lineEdit_info_range_up->clear();
    ui->lineEdit_info_range_down->clear();
    ui->lineEdit_info_sensor_name->clear();
    ui->lineEdit_info_sensor_unit->clear();
    ui->lineEdit_info_filtering_number->clear();
    ui->lineEdit_info_fractional_number->clear();
    init_SensorConfigTable();

    QString path_name;
    if(index==0)
    {
        path_name=APP::ConfigName1;
    }
    else
    {
        path_name=APP::ConfigName2;
    }

    QSettings  *setting = new QSettings(path_name, QSettings::IniFormat);

    setting->beginGroup("parameter");
    ui->lineEdit_info_fractional_number->setText(QString::number(setting->value("sen_fra_num").toInt()));
    ui->lineEdit_info_range_up->setText(QString::number(setting->value("sen_range_up").toFloat()));
    ui->lineEdit_info_range_down->setText(QString::number(setting->value("sen_range_down").toFloat()));
    ui->lineEdit_info_sensor_unit->setText(setting->value("sen_units").toString());
    ui->lineEdit_info_sensor_name->setText(setting->value("sen_name").toString());
    setting->endGroup();

    setting->beginGroup("arraypoint");
    int data_size=setting->value("data_size").toInt();
    QString key,val;
    for (int i=0;i<data_size;i++)
    {
        key.clear();
        val.clear();
        key="actual"+QString::number(i);
        val="code"+QString::number(i);

        ui->tableWidget->item(i,1)->setText(QString::number(setting->value(key).toDouble()));
        ui->tableWidget->item(i,2)->setText(QString::number(setting->value(val).toDouble()));
    }
    setting->endGroup();
}

void MotionControlForm::Updata_UI_Axis()
{
    try {
        ui->lcd_coor_2->display(Axis_UI_Data.AxisRel_1.AxisRealData);
        ui->lcd_coor_6->display(Axis_UI_Data.AxisRel_2.AxisRealData);

        ui->lineEdit_command_location_2->setText(QString::number(Axis_UI_Data.AxisRel_1.AxisCmdPos));
        ui->lineEdit_command_location_6->setText(QString::number(Axis_UI_Data.AxisRel_2.AxisCmdPos));
        //qDebug()<<"实际位置"<<axis_ui_data.AxisRel_1.Axisactuallocation;
        ui->lineEdit_actual_position_2->setText(QString::number(Axis_UI_Data.AxisRel_1.AxisActPos));
        ui->lineEdit_actual_position_6->setText(QString::number(Axis_UI_Data.AxisRel_2.AxisActPos));
        //qDebug()<<"当前速度"<<axis_ui_data.AxisRel_1.Axiscommandspeed;
        ui->lineEdit_command_speed_2->setText(QString::number(Axis_UI_Data.AxisRel_1.AxisCmdSpeed));
        ui->lineEdit_command_speed_6->setText(QString::number(Axis_UI_Data.AxisRel_2.AxisCmdSpeed));
    } catch (...) {

    }

    try {
        axis_status_1->change_state_clear();
        axis_status_2->change_state_clear();
        axis_status_1->change_state(Axis_UI_Data.AxisRel_1.AxisState);
        axis_status_2->change_state(Axis_UI_Data.AxisRel_2.AxisState);

        Updata_UI_Axis_label(&Axis_UI_Data.AxisRel_1,ui->btn_AxisStatus_2);
        Updata_UI_Axis_label(&Axis_UI_Data.AxisRel_2,ui->btn_AxisStatus_6);

        axis_status_1->change_motionstate_clear();
        axis_status_2->change_motionstate_clear();
        axis_status_1->change_motionstate(Axis_UI_Data.AxisRel_1.AxisMotionState);
        axis_status_2->change_motionstate(Axis_UI_Data.AxisRel_2.AxisMotionState);

        axis_status_1->change_iostate_clear();
        axis_status_2->change_iostate_clear();
        axis_status_1->change_iostate(Axis_UI_Data.AxisRel_1.AxisMotionIOState);
        axis_status_2->change_iostate(Axis_UI_Data.AxisRel_2.AxisMotionIOState);

    } catch (...) {

    }

    try {
        if(Ax_State.isPowerOn)
        {
            ui->label_power_onoff->setStyleSheet(SheetStyle_green);
        }
        else
        {
            ui->label_power_onoff->setStyleSheet(SheetStyle_red);
            //Ax_State.isDeviceAxisInit=false;
        }
        if(Ax_State.isDeviceAxisInit)
        {
            ui->label_load->setStyleSheet(SheetStyle_green);
        }
        else
        {
            ui->label_load->setStyleSheet(SheetStyle_red);
        }
        //qDebug()<<"Ax_State.isDeviceAxisInit:"<<Ax_State.isDeviceAxisInit;
    } catch (...) {

    }

    try {

        if(Axis_UI_Data.AxisRel_1.isAxisServoOn)
        {
            ui->btn_AxisEnable_2->setChecked(true);
        }
        else
        {
            ui->btn_AxisEnable_2->setChecked(false);
        }

        if(Axis_UI_Data.AxisRel_2.isAxisServoOn)
        {
            ui->btn_AxisEnable_6->setChecked(true);
        }
        else
        {
            ui->btn_AxisEnable_6->setChecked(false);
        }

    } catch (...) {

    }
}

void MotionControlForm::Updata_UI_Axis_label(AxisRelData *sta, QPushButton *btn)
{
    if((sta->AxisState==STA_AX_DISABLE)||(sta->AxisState==STA_AX_ERROR_STOP))
    {
        btn->setStyleSheet(SheetStyle_red);
    }
    else
    {
        btn->setStyleSheet(SheetStyle_green);
    }
}

void MotionControlForm::on_pushButton_info_set_clicked()
{
    try {
        if(ui->comboBox_axis_choose->currentIndex()==0)
        {
            ax_updata_data(axis_1,APP::ConfigName1);
        }
        else
        {
            ax_updata_data(axis_2,APP::ConfigName2);
        }
    } catch (...) {

    }
}

void MotionControlForm::on_pushButton_power_on_off_clicked()
{
    //emit sigAxisPowerOn();
}

void MotionControlForm::on_pushButton_power_off_clicked()
{
    emit sigAxisPowerOff();
}

void MotionControlForm::on_pushButton_load_clicked()
{
    emit sigDeviceOpen();
}

void MotionControlForm::on_pushButton_clear_error_all_clicked()
{
    emit sigAxisErrorAllClear();
}

void MotionControlForm::on_pushButton_enable_all_clicked()
{
    QVector<int> index;
    index<<0<<1;
    emit sigAxisEnable(index);
}

void MotionControlForm::on_pushButton_disable_all_clicked()
{
    QVector<int> index;
    index<<0<<1;
    emit sigAxisDisable(index);
}

void MotionControlForm::on_btn_axis_increase_1_clicked()
{
    if(!axis_1->get_isrange(axis_1->get_actual_value(Axis_UI_Data.AxisRel_1.AxisCmdPos)+ui->lineEdit_axis_relative_distance_1->text().toDouble()))
    {
        qDebug()<<"超量程";
        return;
    }
    emit sigAxisMoveRelPT(0,10000,axis_1->get_code_value(ui->lineEdit_axis_relative_distance_1->text().toDouble()),ui->lineEdit_axis_relative_time_1->text().toDouble());
}

void MotionControlForm::on_btn_axis_increase_2_clicked()
{
    if(!axis_2->get_isrange(axis_2->get_actual_value(Axis_UI_Data.AxisRel_2.AxisCmdPos)+ui->lineEdit_axis_relative_distance_2->text().toDouble()))
    {
        qDebug()<<"超量程";
        return;
    }
    emit sigAxisMoveRelPT(1,10000,axis_2->get_code_value(ui->lineEdit_axis_relative_distance_2->text().toDouble()),ui->lineEdit_axis_relative_time_2->text().toDouble());
}

void MotionControlForm::on_btn_axis_decrease_1_clicked()
{
    if(!axis_1->get_isrange(axis_1->get_actual_value(Axis_UI_Data.AxisRel_1.AxisCmdPos)-ui->lineEdit_axis_relative_distance_1->text().toDouble()))
    {
        qDebug()<<"超量程";
        return;
    }
    emit sigAxisMoveRelPT(0,10000,axis_1->get_code_value(-ui->lineEdit_axis_relative_distance_1->text().toDouble()),ui->lineEdit_axis_relative_time_1->text().toDouble());
}

void MotionControlForm::on_btn_axis_decrease_2_clicked()
{
    if(!axis_2->get_isrange(axis_2->get_actual_value(Axis_UI_Data.AxisRel_2.AxisCmdPos)-ui->lineEdit_axis_relative_distance_2->text().toDouble()))
    {
        qDebug()<<"超量程";
        return;
    }
    emit sigAxisMoveRelPT(1,10000,axis_2->get_code_value(-ui->lineEdit_axis_relative_distance_2->text().toDouble()),ui->lineEdit_axis_relative_time_2->text().toDouble());
}

void MotionControlForm::on_pushButton_allaxis_move_clicked()
{
    QVector<ulong> index;
    QVector<double> acceleration;
    QVector<double> distance;
    QVector<double> time;


    if(ui->checkBox_axis_move_distance_1->isChecked()==true)
    {
        index<<0;
        acceleration<<5000;
        distance<<axis_1->get_code_value(ui->lineEdit_axis_move_distance_1->text().toDouble());
        time<<ui->lineEdit_axis_allmove_time->text().toDouble();
    }
    if(ui->checkBox_axis_move_distance_2->isChecked()==true)
    {
        index<<1;
        acceleration<<5000;
        distance<<axis_2->get_code_value(ui->lineEdit_axis_move_distance_2->text().toDouble());
        time<<ui->lineEdit_axis_allmove_time->text().toDouble();
    }

    emit sigAxisGroupMoveAbsPT(index,acceleration,distance,time);
}

void MotionControlForm::on_pushButton_allaxis_stop_clicked()
{
    emit sigAxisAllStop();
}

void MotionControlForm::on_btn_axis_gohome_2_clicked()
{
    emit sigAxisGohome(0);
}

void MotionControlForm::on_btn_axis_gohome_6_clicked()
{
    emit sigAxisGohome(1);
}

//void MotionControlForm::on_btn_axis_resetting_2_clicked()
//{
//    emit sigAxisReset(0);
//}

//void MotionControlForm::on_btn_axis_resetting_6_clicked()
//{
//    emit sigAxisReset(1);
//}

void MotionControlForm::on_btn_axis_stop_2_clicked()
{
    emit sigAxisStop(0);
}

void MotionControlForm::on_btn_axis_stop_6_clicked()
{
    emit sigAxisStop(1);
}

void MotionControlForm::on_btn_AxisEnable_2_clicked(bool checked)
{
    QVector<int> index;
    index<<0;
    if(checked)
    {
        emit sigAxisEnable(index);
    }
    else
    {
        emit sigAxisDisable(index);
    }
}

void MotionControlForm::on_btn_AxisEnable_6_clicked(bool checked)
{
    QVector<int> index;
    index<<1;
    if(checked)
    {
        emit sigAxisEnable(index);
    }
    else
    {
        emit sigAxisDisable(index);
    }
}

void MotionControlForm::initialization_1()
{
    QVector<ulong> index;
    QVector<double> acceleration;
    QVector<double> distance;
    QVector<double> time;
    index<<0;
    acceleration<<1000000;

    distance<<axis_1->get_code_value(-0.1);
    time<<0.2;
    emit sigAxisGroupMoveAbsPT(index,acceleration,distance,time);
}
void MotionControlForm::initialization_2()
{
    QVector<ulong> index;
    QVector<double> acceleration;
    QVector<double> distance;
    QVector<double> time;
    index<<0;
    acceleration<<5000;

    distance<<axis_1->get_code_value(0);
    time<<1.5;
    emit sigAxisGroupMoveAbsPT(index,acceleration,distance,time);
}
void MotionControlForm::initialization_3()
{
    QVector<ulong> index;
    QVector<double> acceleration;
    QVector<double> distance;
    QVector<double> time;
    index<<1;
    acceleration<<5000;

    distance<<axis_2->get_code_value(37.3850);
    time<<2;
    emit sigAxisGroupMoveAbsPT(index,acceleration,distance,time);
}
