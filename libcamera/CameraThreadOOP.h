//
// Created by linzy on 2019/04/14.
//

#include <iostream>
#include <thread>
#include <opencv2/opencv.hpp>
#include <mutex>

#ifndef CAMERATEST_CAMERATHREADOOP_H
#define CAMERATEST_CAMERATHREADOOP_H

class CameraThreadOOP {
public:
    CameraThreadOOP(int);

    int start();

    int stop();

    cv::Mat getPicture();

private:
    int CameraThread();

    cv::Mat frame;
    cv::VideoCapture cap;
    std::thread CameraThread_;
    std::mutex frame_mutex;
    bool stop_flag = false;

    void msleep(unsigned long);
};


#endif //CAMERATEST_CAMERATHREADOOP_H
