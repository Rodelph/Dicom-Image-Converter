#ifndef IMGPROC_H
#define IMGPROC_H

#include <QDialog>

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dctk.h"
#include "dcmtk/dcmimgle/dcmimage.h"
#include <opencv2/opencv.hpp>

#include <boost/align.hpp>

#include <iostream>

namespace Ui {
class imgproc;
}

class imgproc : public QDialog
{
    Q_OBJECT

public:
    explicit imgproc(QWidget *parent = nullptr);
    ~imgproc();

    void convertDcmToPng();

private slots:
    void on_testBtn_clicked();

private:
    Ui::imgproc *ui;
};

#endif // IMGPROC_H
