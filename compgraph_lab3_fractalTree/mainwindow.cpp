#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    this->ui->GLwidget->angle = (double)value;
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    this->ui->GLwidget->iter = value;
}

void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
     this->ui->GLwidget->width = value;
     this->ui->GLwidget->height = value;
}

