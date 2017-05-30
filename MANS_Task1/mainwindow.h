#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include "formresult.h"
#include <thread>
#include <QTimer>
#include <math.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //Метод вывода кратчайшего пути (основан на рекурсии)
    //"v" - точка , до которой нужно найти путь.
    //"start" - служит в качестве указания на то, что метод запущен не из рекурсии printWay
    void printWay(int v, bool start);

    //Метод поиска кратчайшего пути, основанный на алгоритме Дейкстры.
    //Может быть запущен в отдельном потоке, для предотвращения подвисания окна программы
    //Входные параметры метода:
    /*1) номер начального аэродрома в таблице 2) номер целевого аэродрома в таблице
     * 3) максимальная дальность перелёта между аэродромами в таблице 4) указатель на таблицу с аэродромами
     * 5) указатель на массив координат аэродромов 6) указатель на массив хранящий кратчайшие пути к аэродромам
     * 7) указатель на массив хранящий расстояние от начального аэродрома 8) указатель на переменную с результатом */
    static void searchingWay(int startP, int endP, int maxDist,
                             QTableWidget *tw, double** u_cords,
                             int* u_pred, int *dist, int *res);

    //Метод находит расстояние между точками в километрах.
    //В качестве параметров - значения широты и долготы точек
    static uint distans(double lat1 , double lon1 , double lat2 , double lon2);

    //Метод возвращающий модуль дробного числа в формате double
    static double dabs(double value) {if(value<0) value*=-1; return value;}

    //Метод преобразует десятичную запись градусов в запись Градусы/Минуты/Секунды
    static QString conversionCoords(double value);

    //Указатель на переменную , используемую для отслеживания остановки работы метода searchingWay
    int *resultZ3;


private slots:
    //Слот кнопки поиска аэродромов в указанном радиусе
    void on_pushButton1_clicked();

    //Слот кнопки поиска кратчайшего пути между аэродромами
    void on_pushButton2_clicked();

    //Слот цикла , в котором проверяется завершение работы метода searchingWay
    //Метод проверяет , что resultZ3 не равен 0 (метод завершил выполнение)
    void chicleZ3();


    void on_comboBox_currentIndexChanged(int index);

private:
    // Переменные и указатели ---------------------------
    Ui::MainWindow *ui;                 //Указатель на элементы визуального интерфейса
    QTableWidgetItem *tw_item;          //Указатель для создания элементов таблици
    FormResult *fResult;                //Указатель для создания окна с результатом
    int *pred;                          //Массив с кратчайшим путём из точки (на случай , если стартовая точка не изменится)
    int *dist;                          //Массив с дальностью  между стартовой и конечными точками.
    int lastStartPoint;                 //Последняя стартовая точка (для третьего задания)
    int lastEndPoint;                   //Последняя конечная точка (для третьего задания)
    int lastMaxDist;                    //Последнее максимальное расстояние перелёта между аэродромами

    double **cords;                     //Указатель на массив со значениями широты и долготы аэродромов
    QTimer *timer;                      //Указатель на таймер, используемый слотом chicleZ3

    // Методы --------------------------------------------
    void fillMassCords();               //Заполнение массива cords данными из таблици
    bool loadFile(QString file_name);   //Загрузка данных из файла в таблицу
};

#endif // MAINWINDOW_H
