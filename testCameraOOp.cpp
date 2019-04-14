//
// Created by linzy on 2019/04/14.
//
#include <iostream>
#include <thread>
#include <opencv2/opencv.hpp>
#include <mutex>

#include "libcamera/CameraThreadOOP.h"

using namespace std;

int main() {
    cout << "Hello" << endl;
    CameraThreadOOP camera0(0);
    camera0.start();
    int n = 1000;
    cv::namedWindow("test");
    while (n--) {
        cv::imshow("test", camera0.getPicture());
        cv::waitKey(20);
    }
    cout << "stoping" << endl;
    camera0.stop();
    cout << "stoped" << endl;
}

