#include "header/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :   QMainWindow(parent), 
                                            ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }



void MainWindow::on_procBtn_clicked()
{
    this->setAttribute(Qt::WA_QuitOnClose);
    this->close();
    imgproc img;
    img.setModal(true);
    img.exec();
}