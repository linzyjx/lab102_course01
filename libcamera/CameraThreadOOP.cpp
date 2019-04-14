//
// Created by linzy on 2019/04/14.
//

#include "CameraThreadOOP.h"

CameraThreadOOP::CameraThreadOOP(int n) {
    cap = cv::VideoCapture(n);
    cap >> frame;
    msleep(500);
    std::cout << "use:video" << n << std::endl;
}

int CameraThreadOOP::start() {
    CameraThread_ = std::thread(std::bind(&CameraThreadOOP::CameraThread, this));
}

int CameraThreadOOP::stop() {
    stop_flag = true;
    CameraThread_.join();
}

cv::Mat CameraThreadOOP::getPicture() {
    cv::Mat frame_;
    frame_mutex.lock();
    frame_ = frame;
    frame_mutex.unlock();
    return frame_;
}

int CameraThreadOOP::CameraThread() {
//    std::cout << "Thread up" << std::endl;
    while (stop_flag == false) {
        cv::Mat frame_;
        cap >> frame_;
        frame_mutex.lock();
        frame = frame_;
        frame_mutex.unlock();
//        std::cout<<"do"<<std::endl;
        msleep(10);
    }
}

void CameraThreadOOP::msleep(unsigned long millsec) {
    struct timespec req = {0}, rem = {0};
    time_t sec = (int) (millsec / 1000);
    millsec = millsec - (sec * 1000);
    req.tv_sec = sec;
    req.tv_nsec = millsec * 1000000L;
    nanosleep(&req, &req);
}