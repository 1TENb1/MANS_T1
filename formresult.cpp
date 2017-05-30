#include "formresult.h"
#include "ui_formresult.h"

FormResult::FormResult(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormResult)
{
    ui->setupUi(this); this->setWindowTitle("Результат");
    ui->tableWidgetAirports->setColumnCount(3);
    QStringList strl; strl.append("Название"); strl.append("Долгота"); strl.append("Широта");
    ui->tableWidgetAirports->setHorizontalHeaderLabels(strl);
}

void FormResult::addTableItem(QString text, double lat, double lon, QColor color)
{
    addTableItem(text,QString("%1").arg(lat),QString("%1").arg(lon),color);
}

void FormResult::addTableItem(QString text, QString lat, QString lon , QColor color)
{
    color.setAlpha(100);
    ui->tableWidgetAirports->setRowCount(ui->tableWidgetAirports->rowCount()+1);
    tw_item=new QTableWidgetItem(text); tw_item->setBackgroundColor(color); ui->tableWidgetAirports->setItem(ui->tableWidgetAirports->rowCount()-1,0,tw_item);
    tw_item=new QTableWidgetItem(lat); ui->tableWidgetAirports->setItem(ui->tableWidgetAirports->rowCount()-1,1,tw_item);
    tw_item=new QTableWidgetItem(lon); ui->tableWidgetAirports->setItem(ui->tableWidgetAirports->rowCount()-1,2,tw_item);
}

void FormResult::setTitle(QString text)
{
    ui->labelTitle->setText(text);
}

FormResult::~FormResult()
{
    delete ui;
}

void FormResult::closeEvent(QCloseEvent *event)
{
    delete this;
}
