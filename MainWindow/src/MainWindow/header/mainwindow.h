#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "../../../../ImageProc/src/ImageProc/header/imgproc.h"

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
    const char* path = "../../resPng/1-001.png";

    const QString _details = tr(
        "This project can transform .dcm files to any other image format"
        "and then manipulate theses images for you need !!"
    );

    const QString _versionDetails = tr(
        "Dicom Image Converter "
        "Version 0.0.1 <br>"
    );
};

#endif // MAINWINDOW_H
