#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebChannel>
#include <QTimer>
#include <QJsonObject>

#include "webclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QWebEngineView *qWebEngineView;
    QWebChannel *qWebChannel;
    QTimer *qTimer;
    QJsonObject qJsonObject;
    WebClass *webClass;
};
#endif // MAINWINDOW_H
