#pragma once
#include <opencv2/opencv.hpp>
#include <string>

class PillCounter {
public:
    struct Result {
        int pillCount;
        cv::Mat processedImage;
    };

    static Result countPills(const std::string& imagePath);

private:
    static cv::Mat preprocess(const cv::Mat& input);
    static std::vector<std::vector<cv::Point>> detectPills(const cv::Mat& processed);
};
