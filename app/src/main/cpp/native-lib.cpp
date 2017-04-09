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

extern "C"
JNIEXPORT void JNICALL
Java_com_kyshel_native_1b_SaltActivity_nProcess(JNIEnv *env, jobject instance, jlong matAddrSrc,
                                                jlong matAddrDst) {

    Mat& mSrc = *(Mat*)matAddrSrc;
    Mat& mDst = *(Mat*)matAddrDst;

    saveMatFrameToImage(mSrc);


}

