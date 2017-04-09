#include <jni.h>
#include <string>
#include <opencv2/core/core.hpp>
#include <iostream>
#include "logs.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <vector>
#include <opencv2/imgcodecs.hpp>



using namespace std;
using namespace cv;

int test_core(){

    int a = 3333;

    LOGI("native method invoked");




    return a;
}



extern "C" JNIEXPORT jstring JNICALL
Java_com_kyshel_native_1b_MainActivity_savePic(
        JNIEnv *env,
        jobject /* this */) {


    test_core();
    /* */

    std::string hello = "it's native";
    return env->NewStringUTF(hello.c_str());
}


extern "C" JNIEXPORT jstring JNICALL
Java_com_kyshel_native_1b_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Where R U now";


    return env->NewStringUTF(hello.c_str());
}

extern "C"
{
void JNICALL Java_com_kyshel_native_1b_SaltActivity_salt(JNIEnv *env, jobject instance,
                                                                           jlong matAddrGray,
                                                                           jint nbrElem) {
    Mat &mGr = *(Mat *) matAddrGray;
    for (int k = 0; k < nbrElem; k++) {
        int i = rand() % mGr.cols;
        int j = rand() % mGr.rows;
        mGr.at<uchar>(j, i) = 255;
    }
}
}

int toGray(Mat img, Mat& gray)
{
    cvtColor(img, gray, CV_RGBA2GRAY); // Assuming RGBA input
    if (gray.rows == img.rows && gray.cols == img.cols)
    {
        return (1);
    }
    return(0);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_kyshel_native_1b_SaltActivity_nFrame2Gray(JNIEnv *env, jobject instance,jlong matAddrRgba,jlong matAddrGray) {

    //test_core();
    Mat& mRgb = *(Mat*)matAddrRgba;
    Mat& mGray = *(Mat*)matAddrGray;

    int conv;
    jint retVal;

    conv = toGray(mRgb, mGray);
    retVal = (jint)conv;

    return retVal;
}

int saveMatFrameToImage(Mat mSrc)
{
    Mat rgbMatSrc;
    cvtColor(mSrc,rgbMatSrc,COLOR_BGR2RGB);
    imwrite( "/mnt/sdcard/1/aaabbb.jpg", rgbMatSrc );
    return 1;
}

std::vector<cv::Rect> detectLetters(cv::Mat img)
{
	std::vector<cv::Rect> boundRect;
	cv::Mat img_gray, img_sobel, img_threshold, element;
	cvtColor(img, img_gray, CV_BGR2GRAY);
	cv::Sobel(img_gray, img_sobel, CV_8U, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);
	cv::threshold(img_sobel, img_threshold, 0, 255, CV_THRESH_OTSU + CV_THRESH_BINARY);
	element = getStructuringElement(cv::MORPH_RECT, cv::Size(17, 3));
	cv::morphologyEx(img_threshold, img_threshold, CV_MOP_CLOSE, element); //Does the trick
	std::vector< std::vector< cv::Point> > contours;
	cv::findContours(img_threshold, contours, 0, 1);
	std::vector<std::vector<cv::Point> > contours_poly(contours.size());
	for (int i = 0; i < contours.size(); i++)
		if (contours[i].size()>100)
		{
			cv::approxPolyDP(cv::Mat(contours[i]), contours_poly[i], 3, true);
			cv::Rect appRect(boundingRect(cv::Mat(contours_poly[i])));
			if (appRect.width>appRect.height)
				boundRect.push_back(appRect);
		}
	return boundRect;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_kyshel_native_1b_SaltActivity_nProcess(JNIEnv *env, jobject instance, jlong matAddrSrc,
                                                jlong matAddrDst) {

    Mat& mSrc = *(Mat*)matAddrSrc;
    Mat& mDst = *(Mat*)matAddrDst;

    saveMatFrameToImage(mSrc);

    	//Detect
	std::vector<cv::Rect> letterBBoxes1 = detectLetters(mSrc);
    for (int i = 0; i< letterBBoxes1.size(); i++)
        cv::rectangle(mSrc, letterBBoxes1[i], cv::Scalar(0, 255, 0), 3, 8, 0);



}

