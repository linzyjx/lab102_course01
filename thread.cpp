#include <iostream>
#include <thread>
#include <opencv2/opencv.hpp>
#include <mutex>

cv::Mat ex_frame;
std::mutex frame_mutex;

void msleep(unsigned long millsec);

void takeImage(cv::VideoCapture &cap);

int main() {
    std::cout << "Hello, World!" << std::endl;
    cv::Mat frame;
    cv::VideoCapture cap0(0);
    cv::namedWindow("test");
    std::thread td_capture0(takeImage, std::ref(cap0));
    msleep(3000);
    while (1) {
//      cap0.read(frame);
        frame_mutex.lock();
        frame = ex_frame;
        frame_mutex.unlock();
        cv::imshow("test", frame);
        cv::waitKey(200);
    }
    return 0;
}

void takeImage(cv::VideoCapture &cap) {
    while (1) {
        cv::Mat frame;
        cap >> frame;
        frame_mutex.lock();
        ex_frame = frame;
        frame_mutex.unlock();
//        std::cout<<"do"<<std::endl;
        msleep(10);
    }
}

void msleep(unsigned long millsec) {
    struct timespec req = {0}, rem = {0};
    time_t sec = (int) (millsec / 1000);
    millsec = millsec - (sec * 1000);
    req.tv_sec = sec;
    req.tv_nsec = millsec * 1000000L;
    nanosleep(&req, &req);
}
