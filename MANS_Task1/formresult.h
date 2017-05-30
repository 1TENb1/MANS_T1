#ifndef FORMRESULT_H
#define FORMRESULT_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QCloseEvent>

namespace Ui {
class FormResult;
}

class FormResult : public QWidget
{
    Q_OBJECT

public:
    explicit FormResult(QWidget *parent = 0);

    //Метод добавляет новыую строку в таблицу
    //color - указывает цвет ячейки таблици
    void addTableItem(QString text , double lat , double lon, QColor color = Qt::white);
    void addTableItem(QString text , QString lat , QString lon, QColor color = Qt::white);

    //Метод занаёт загаловок над таблицей
    void setTitle(QString text);

    ~FormResult();

public slots:
    //Переопределение слота закрытия окна , для отчистки памяти при его закрытии
    void closeEvent(QCloseEvent *event);

private:
    Ui::FormResult *ui;
    QTableWidgetItem *tw_item;          //Указатель для создания элементов таблици
};

#endif // FORMRESULT_H
