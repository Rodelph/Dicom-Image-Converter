#include "header/imgproc.hpp"

imageproc::imageproc() { convertDcmToPng(path); }

imageproc::~imageproc() { delete path; }

void imageproc::convertDcmToPng(char* imageToConv)
{
    afile = "...\\**.dcm";
    result = dfile.loadFile(imageToConv);

    if (result.bad()) { std::cout << "Error when loading !!\n";}

    data = dfile.getDataset();

    Metalnfo = dfile.getMetaInfo();

    tag = Metalnfo->getTag();

    element = NULL;

    result = data->findAndGetElement(DCM_PixelData, element);

    if (result.bad()) { std::cout << "Error when finding element !!\n";}

    imageDcm = new DicomImage(imageToConv);
    nRows = imageDcm->getHeight();
    nCols = imageDcm->getWidth();
    nImgs = imageDcm->getFrameCount();

    data_Len = data->getLength();
    element_Len = element->getLength();

    data->findAndGetOFString(DCM_PatientName, patientName);
    Uint16* pixData16;
    result = element->getUint16Array(pixData16);

    std::cout << "data_len " << data_Len << std::endl;
    std::cout << "elemetn_len " << element_Len << std::endl;

    for (int i = 0; i < 512*512; i++)
        *(pixData16 + i) *= 20; //  Grayscale stretch
    cv::Mat imag = cv::Mat(512, 512, CV_16U, pixData16);
    cv::imshow("image", imag);
    cv::waitKey();
    cv::destroyAllWindows();
}