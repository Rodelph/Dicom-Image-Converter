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
    nameFile = ui->lineEdit->text().toStdString(); 
    if (ui->lineEdit->text().toStdString() == "")
    {
        msgEr = new QErrorMessage(this);
        msgEr->showMessage("Please insert a file name in the text area !!");  
        return;
    }
    
    QString pathF = QFileDialog::getOpenFileName(this,
                                                "Dicom images",
                                                 pathToDcm + "/**",
                                                 "Image (*.dcm)"
                                                 );

    DicomImage *image = new DicomImage(pathF.toStdString().c_str());
    image->setMinMaxWindow();
    cv::Mat dst;
    cv::Mat inputImage(uint16_t(image->getHeight()), uint16_t(image->getWidth()), CV_16UC1, (uint16_t*)image->getOutputData(16));
    cv::medianBlur(inputImage, dst, 3);
    cv::imshow("image", dst);
    
    msgBox.setText("Selecting the file to convert.");
    msgBox.setInformativeText("Do you want to save your changes ?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) 
    {
       case QMessageBox::Save:         
           cv::imwrite("../../resPng/" + nameFile + ".png", dst);
           cv::waitKey();
           cv::destroyAllWindows();
           break;

       case QMessageBox::Cancel:
           break;
    }
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

