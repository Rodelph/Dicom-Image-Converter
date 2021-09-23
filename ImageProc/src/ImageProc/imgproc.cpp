#include "./header/imgproc.h"
#include "ui_imgproc.h"

imgproc::imgproc(QWidget *parent) : QDialog(parent),
                                    ui(new Ui::imgproc)
{
    ui->setupUi(this);
}

imgproc::~imgproc() { delete ui; }

void imgproc::on_convBtn_clicked()
{
    DicomImage *image = new DicomImage("../../resDcm/1-002.dcm");
    image->setMinMaxWindow();
    
    cv::Mat dst;
    cv::Mat inputImage(uint16_t(image->getHeight()), uint16_t(image->getWidth()), CV_16UC1, (uint16_t*)image->getOutputData(16));
    cv::medianBlur(inputImage, dst, 3);
    cv::imshow("image", dst);
    cv::imwrite("../../resPng/1-001.png", dst);
    cv::waitKey();
    cv::destroyAllWindows();
}