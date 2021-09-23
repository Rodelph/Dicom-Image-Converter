#include "./header/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :   QMainWindow(parent), 
                                            ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap map(path);
    width = ui->label->width();
    height = ui->label->height();
    ui->label->setPixmap(map.scaled(width, height, Qt::KeepAspectRatio));

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

void MainWindow::on_actionAbout_us_triggered()
{
    QMessageBox::information(this,
                            "More info about the program",
                            this->_details
                            );
}

void MainWindow::on_actionProgram_version_triggered()
{
    QMessageBox::information(this,
                            "Program Version",
                            this->_versionDetails
                            );
}
