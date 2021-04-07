#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "webclass.h"

#include <QBoxLayout>
#include <QJsonArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QBoxLayout *layout = new QHBoxLayout;
    qWebEngineView = new QWebEngineView(this);
    qDebug()<<QCoreApplication::applicationDirPath();
    qWebEngineView->load(QUrl::fromLocalFile(QCoreApplication::applicationDirPath()+ "/../../qtwebengine_echarts_demo/html/echarts_webchannel_demo.html"));
    qWebChannel = new QWebChannel;
    webClass = new WebClass();
    qWebChannel->registerObject("webClass", webClass);
    qWebEngineView->page()->setWebChannel(qWebChannel);

    layout->addWidget(qWebEngineView);
    ui->widget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

struct Pos
{
    double x,y,z;
};

QList<QList<Pos> > qList;
int objNum = 5;

void MainWindow::on_pushButton_clicked()
{
    for(int i=0;i<objNum;i++)
    {
        QList<Pos> qListItem;
        qList.append(qListItem);
    }

    qTimer = new QTimer;
    connect(qTimer, &QTimer::timeout, this,
            [&]()
    {
        for(int i=0;i<qList.size();i++)
        {
            Pos pos;
            pos.x=qrand()%10;
            pos.y=qrand()%10;
            pos.z=qrand()%10;
            qList[i].append(pos);
        }

        QJsonArray jsonItem;
        for(int i=0;i<qList.size();i++)
        {
            QJsonArray jsonItemArray;
            for(int j=0;j<qList.at(i).size();j++)
            {
                QJsonArray jsonItemArrayPos;
                jsonItemArrayPos.append(qList.at(i).at(j).x);
                jsonItemArrayPos.append(qList.at(i).at(j).y);
                jsonItemArrayPos.append(qList.at(i).at(j).z);
                jsonItemArray.append(jsonItemArrayPos);
            }
            jsonItem.append(jsonItemArray);
        }

        qJsonObject["line"]=jsonItem;
        qJsonObject["point"] = jsonItem;

        webClass->setProperty("jsonData", qJsonObject);

    });
    qTimer->start(1000);
}
