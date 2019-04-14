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
    cv::VideoCapture cap0(0);
    cv::namedWindow("test");
    cv::Mat frame;
    msleep(3000);
    while (1) {
//      cap0.read(frame);
        cap0 >> frame;
        cv::imshow("test", frame);
        cv::waitKey(200);
    }
    return 0;
}

void msleep(unsigned long millsec) {
    struct timespec req = {0}, rem = {0};
    time_t sec = (int) (millsec / 1000);
    millsec = millsec - (sec * 1000);
    req.tv_sec = sec;
    req.tv_nsec = millsec * 1000000L;
    nanosleep(&req, &req);
}
