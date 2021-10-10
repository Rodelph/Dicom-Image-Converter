#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include <opencv2/opencv.hpp>

#include <QMainWindow>
#include <QMessageBox>
#include <QFileDialog>
#include <QErrorMessage>

#include <iostream>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:

        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:

        void on_actionProgram_version_triggered();
        void on_procBtn_clicked();
        void on_actionAbout_us_triggered(); 

    private:
   
        Ui::MainWindow *ui;
        int width, height;
        const char* path = "resAppPng/app.png";
        QMessageBox msgBox;
        const QString _details = tr("This project can transform .dcm files to .png format !" );
        std::string nameFile;
        const QString _versionDetails = tr( "Dicom Image Converter <br>" "Version 0.0.1 <br>" );

        QErrorMessage *msgEr;
        const QString pathToDcm = "../../resDcm";
};

#endif // MAINWINDOW_H
