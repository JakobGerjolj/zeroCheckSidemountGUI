#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_CanHandler = new canHandler;

    QTimer *timer  = new QTimer(this);
    connect(timer, &QTimer::timeout,this, &MainWindow::setRawValue);
    timer->start(5);


}

MainWindow::~MainWindow()
{
    delete m_CanHandler;
    delete ui;
}

void MainWindow::setRawValue(){

    ui -> RawValue -> setText(QString::number(m_CanHandler -> getRawValue()));
    ui -> ZeroValue -> setText(QString::number(m_CanHandler -> getZeroValue()));

}
