#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QFile>
#include <QIODevice>
#include <QCoreApplication> //Для обнаружение полного пути (вдруг на Linux запустят)
#include <QMessageBox>      //Для вывода информации об ошибках ошибок
#include <QFileDialog>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Зануление значений
    pred=0; dist=0; lastMaxDist=0;
    lastEndPoint=-1; lastStartPoint=-1;

    //Создание переменной для указателя
    resultZ3=new int;

    this->setWindowTitle("Задание от 'МАНС' (выполено: Новиков М.В.)");

    //Загрузка данных аэродромов из файла в таблицу
    if(loadFile(QCoreApplication::applicationDirPath()+"/airports.csv")==false)
    {
        //Если файл не найдер в каталоге запуска , то его выбирает пользователь
        QString name=QFileDialog::getOpenFileName(0,"Выберите файл с данными аэродромов","","*.csv\nall(*)");
        if(name.isEmpty() || !loadFile(name)) {ui->pushButton1->setEnabled(false); ui->pushButton2->setEnabled(false); return;}
    }

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(chicleZ3())); //для связи между потоками при поиске маршрута
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::loadFile(QString file_name)
{
    int countRows=0;

    //Названия колонок
    ui->tableWidgetAirports->setColumnCount(3);
    QStringList strl; strl.append("Название"); strl.append("Широта"); strl.append("Долгота");
    ui->tableWidgetAirports->setHorizontalHeaderLabels(strl);

    //Чтение из файла в таблицу
    QFile rFile(file_name);
    if(rFile.open(QIODevice::ReadOnly)==false) return false; //Файл не удалось открыть
    QTextStream read(&rFile); read.setCodec("UTF-8"); read.readLine();
    while(!read.atEnd())
    {
        countRows++; ui->tableWidgetAirports->setRowCount(countRows);
        strl.clear(); strl=read.readLine().split('	',QString::SkipEmptyParts);
        for(int i=0;i<strl.count();i++)
        {
            tw_item=new QTableWidgetItem(strl.value(i));
            ui->tableWidgetAirports->setItem(countRows-1,i,tw_item);
        }
    }
    rFile.close();
    fillMassCords(); //сохранение данных координат в удобном для быстрой работы формате

    return true; //Чтение успешно завершено
}


uint MainWindow::distans(double lat1, double lon1, double lat2, double lon2)
{
    double x,y; uint result;
    //перевод градусов в радианы
    lat1=lat1*M_PI/180.0; lat2=lat2*M_PI/180.0; lon1=lon1*M_PI/180.0; lon2=lon2*M_PI/180.0;
    double delta=lon1-lon2;

    y=pow(cos(lat2)*sin(delta),2) + pow(cos(lat1)*sin(lat2)-sin(lat1)*cos(lat2)*cos(delta),2); y=sqrt(y);
    x=sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(delta);

    result=atan2(y,x)*6372795;   //Результат в метрах
    result/=1000;                //Перевод в километры
    return result;

}

QString MainWindow::conversionCoords(double value)
{
    QString str; int integer; double fraction;
    //Для отрицательных значений
    if(value<0) str+="-"; value=dabs(value);
    //Разделение градусов и минут
    integer=value; fraction=value-integer;
    //Запись градусов
    str+=QString("%1°").arg(integer);
    //Разделение минут и секунд
    value=fraction*60; integer=value; fraction=value-integer;
    //Запись минут
    str+=QString("%1'").arg(integer);
    //Вычисление и запись секунд
    integer=fraction*60;
    str+=QString("%1\"").arg(integer);
    return str;
}

void MainWindow::on_pushButton1_clicked() //поиск аэродромов в радиусе
{
    //Проверка на наличие входных данных
    if(ui->tableWidgetAirports->selectedRanges().count()!=1) return;

    QTableWidget *tw=ui->tableWidgetAirports;
    int r=ui->spinBox->value(); int selI=tw->selectedRanges().value(0).bottomRow();
    fResult=new FormResult(); fResult->setTitle(QString("Аэродромы в радиусе %1км\nот %2 (%3   %4)").arg(r).arg(tw->item(selI,0)->text()).arg(tw->item(selI,1)->text()).arg(tw->item(selI,2)->text())); int count=0;

    for(int i=0;i<ui->tableWidgetAirports->rowCount();i++)
    {
        if(i==selI) continue; //выбранный аэродром разумеется тоже находится в радиусе, но это как-то странно...
        //Возможно расстояние очевидно слишком большое и можно не использовать формулы?
        if(dabs(cords[selI][0]-cords[i][0])*100 > r) continue;  //Слишком далеко по широте
        if(dabs(cords[selI][1]-cords[i][1])*30 > r) continue;   //Слишком далеко даже при минимальной "цене" долготы
        //Поиск расстояния между точками (в километрах)
        uint dist=distans(cords[selI][0],cords[selI][1] , cords[i][0],cords[i][1]);
        if(dist>r)  continue; //не подошёл , переходим к следующему
        fResult->addTableItem(tw->item(i,0)->text(),tw->item(i,1)->text(),tw->item(i,2)->text()); count++;
    }

    fResult->show();
}

void MainWindow::on_pushButton2_clicked()
{
    QString errorStr="";
    if(ui->tableWidgetAirports->selectedRanges().count()!=2) //Проверка на наличие входных данных
    { errorStr="Для выполнения опеарции должны быть выбраны ДВА аэродрома.\n\nВыбрать их можно с помощью клавиши Cntrl и левой кнопки мыши"; }
    if(errorStr!="") {QMessageBox *mb=new QMessageBox(); mb->setText(errorStr); mb->setWindowTitle("Ошибка"); mb->show(); return;}

    QTableWidget *tw=ui->tableWidgetAirports;

    int startP=tw->selectedRanges().value(0).bottomRow();
    int endPoint=tw->selectedRanges().value(1).bottomRow();

    //Может на прямик долетит?
    int d=distans(cords[startP][0],cords[startP][1] , cords[endPoint][0],cords[endPoint][1]);
    if(d < ui->spinBox->value())
    {
        fResult=new FormResult(); fResult->setTitle(QString("Маршрут полёта из %1 в %2\nСуммарное расстояние перелёта %3км.").arg(ui->tableWidgetAirports->item(startP,0)->text()).arg(ui->tableWidgetAirports->item(endPoint,0)->text()).arg(d));
        fResult->addTableItem(tw->item(startP,0)->text(),tw->item(startP,1)->text(),tw->item(startP,2)->text(),Qt::yellow);
        fResult->addTableItem(tw->item(endPoint,0)->text(),tw->item(endPoint,1)->text(),tw->item(endPoint,2)->text(),Qt::green);
        fResult->show(); return;
    }

    //Может все пути из стартовой точки уже найдены? (особенность алгоритма Дейкстры)
    //Для этого необходимо сохранение стартовой точки и максимально расстояния перелёта без посадки
    if(startP==lastStartPoint && lastMaxDist==ui->spinBox->value())
    {
        *resultZ3=1; lastEndPoint=endPoint;
        chicleZ3(); return;
    }

    //Запуск поиска пути в отдельном потоке , чтоб окно не зависало
    //Теперь оптимизации достаточно чтобы этого не происходило , но пускай будет
    ui->pushButton2->setEnabled(false); //на всякий случай отключим кнопку
    timer->start();                     //для того что-бы узнать , что метод в другом потоке завершил работу
    if(pred!=0) {delete[] pred; delete[] dist;}         //освобождение памяти
    pred=new int[ui->tableWidgetAirports->rowCount()];  //cоздание массива для кратчайшего пути
    dist=new int[ui->tableWidgetAirports->rowCount()];  //создание массива для суммарного расстояния пути

    lastStartPoint=startP;
    lastEndPoint=endPoint;
    lastMaxDist=ui->spinBox->value();

    std::thread thr(searchingWay,startP,endPoint,ui->spinBox->value(),ui->tableWidgetAirports,cords,pred,dist,resultZ3);
    thr.detach();
}

void MainWindow::chicleZ3()
{
    if(*resultZ3!=0)
    {
        timer->stop();
        QString di="~ "; if(pred[lastEndPoint]!=-1) di=QString("%1").arg(dist[lastEndPoint]);
        fResult=new FormResult();
        fResult->setTitle(QString("Маршрут полёта из %1 в %2\nСуммарное расстояние перелёта %3км.").arg(ui->tableWidgetAirports->item(lastStartPoint,0)->text()).arg(ui->tableWidgetAirports->item(lastEndPoint,0)->text()).arg(di));
        printWay(ui->tableWidgetAirports->selectedRanges()[1].bottomRow(),true);
        fResult->show();

        ui->pushButton2->setEnabled(true); return;
    }
    else
    timer->start(100);
}

void MainWindow::fillMassCords() //Сохранение координат в массив , для ускорения работы программы в будущем
{
    int cR=ui->tableWidgetAirports->rowCount();  if(cR==0) return;
    cords=new double*[cR];
    for(int i=0;i<cR;i++)
    {
        cords[i]=new double[2];
        cords[i][0]=ui->tableWidgetAirports->item(i,1)->text().toDouble();
        cords[i][1]=ui->tableWidgetAirports->item(i,2)->text().toDouble();
    }
}


void MainWindow::printWay(int v, bool start)
{
    QColor c=Qt::white;
    if(v==-1 || (start && pred[v]==-1)) return;
    printWay(pred[v],false);
    if(pred[v]==-1) c=Qt::yellow;
    if(start) c=Qt::green;
    QTableWidget *tw=ui->tableWidgetAirports;
    fResult->addTableItem(tw->item(v,0)->text(),tw->item(v,1)->text(),tw->item(v,2)->text(),c);
}

void MainWindow::searchingWay(int startP, int endP, int maxDist, QTableWidget *tw, double **u_cords, int *u_pred, int *dist, int *res)
{
    *res=0; //Ещё нет результата
    //Алгоритм Дейкстры (поиск кратчайшего пути)
    int n=tw->rowCount();
    bool *used=new bool[n];                   //зевершена-ли работа с вершиной
    for(int i=0;i<n;i++) {used[i]=false; dist[i]=INT_MAX/2; u_pred[i]=-1;} dist[startP]=0;

    for(int k=0;k<n;k++)
    {
        int v=-1;
        int distV=INT_MAX/2;
        //Выбор вершины , кратчайшее расстояние до которой ещё не найдено
        for(int i=0;i<n;i++)
        {
            if(used[i]==true || distV<dist[i]) continue;
            v=i; distV=dist[i];
        }

        vector<int> adjacent;   //смежность вершин графа
        vector<uint> weight;    //вес рёбер графа
        //Ищем рёбра для вершины
        for(int i=0;i<n;i++)
        {
            //Формула определения расстояние ресурсозатратна , может и без неё удастся отсеить?
            if(dabs(u_cords[v][0]-u_cords[i][0])*100 > maxDist) continue; //Слишком далеко по широте
            if(dabs(u_cords[v][1]-u_cords[i][1])*30 > maxDist) continue;  //Слишком далеко по долготе
            if(i==v) continue; //Сравнение с самим собой лишнее
            uint r=distans(u_cords[v][0],u_cords[v][1] , u_cords[i][0],u_cords[i][1]);
            if(r > maxDist) continue; //Слишком большое расстояние
            adjacent.push_back(i); weight.push_back(r);
        }
        //Рассматриваем рёбра исходящие из вершины
        for(int i=0;i<adjacent.size();i++)
        {
            int u=adjacent[i]; int weightU=weight[i];
            //релаксация вершины
            if (dist[v] + weightU < dist[u]) {dist[u] = dist[v] + weightU; u_pred[u] = v;}
        }
        used[v]=true;
    }
    if(dist[endP]!=INT_MAX/2) *res=1; else *res=-1; //1 - найден путь , -1 - не найден путь
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    QTableWidget *tw=ui->tableWidgetAirports;
    if(index==1)
    {
    for(int i=0;i<tw->rowCount();i++)
    {
        tw->item(i,1)->setText(conversionCoords(cords[i][0]));
        tw->item(i,2)->setText(conversionCoords(cords[i][1]));
    }
    return;
    }
    for(int i=0;i<tw->rowCount();i++)
    {
        tw->item(i,1)->setText(QString("%1").arg(cords[i][0]));
        tw->item(i,2)->setText(QString("%1").arg(cords[i][1]));
    }
}
