#pragma once

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <dcmtk/dcmimgle/dcmimage.h>
#include <dcmtk/dcmdata/dctk.h>
#include <dcmtk/dcmdata/dcfilefo.h>

#include <boost/align.hpp>

#include <iostream>

class imageproc
{
    public:
        imageproc();
        ~imageproc();

        void convertDcmToPng(char* imageToConv);

    private:
        cv::Mat img;

        DicomImage *imageDcm;

        DcmFileFormat dfile;

        DcmDataset *data;

        DcmMetaInfo *Metalnfo;

        DcmElement *element;

        DcmTag tag;

        std::string afile;

        OFCondition result;

        OFString patientName;

        char* path = "D:/Health/manifest-1592933468162/CPTAC-HNSCC/C3L-04844/02-24-2005-NA-CT SOFT TISSUE NECK ENHANCEDNK-16104/605.000000-100 C SP AXIAL BONE 2X1-89647/1-001.dcm";

        uint32_t nRows, nCols, nImgs, data_Len, element_Len;
};