#include "pill_counter.h"

PillCounter::Result PillCounter::countPills(const std::string& imagePath) {
    // 读取图片
    cv::Mat image = cv::imread(imagePath);
    if (image.empty()) {
        throw std::runtime_error("Cannot open image: " + imagePath);
    }

    // 预处理图片
    cv::Mat processed = preprocess(image);

    // 检测药丸
    auto contours = detectPills(processed);

    // 在原图上绘制结果
    cv::Mat result = image.clone();
    for (const auto& contour : contours) {
        cv::drawContours(result, std::vector<std::vector<cv::Point>>{contour}, 0, cv::Scalar(0, 255, 0), 2);
    }

    return Result{
        static_cast<int>(contours.size()),
        result
    };
}

cv::Mat PillCounter::preprocess(const cv::Mat& input) {
    cv::Mat processed;
    
    // 转换为灰度图
    cv::cvtColor(input, processed, cv::COLOR_BGR2GRAY);
    
    // 高斯模糊去噪
    cv::GaussianBlur(processed, processed, cv::Size(5, 5), 0);
    
    // 自适应阈值分割
    cv::adaptiveThreshold(processed, processed, 255,
        cv::ADAPTIVE_THRESH_GAUSSIAN_C,
        cv::THRESH_BINARY_INV, 11, 2);
    
    // 形态学操作
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
    cv::morphologyEx(processed, processed, cv::MORPH_OPEN, kernel);
    
    return processed;
}

std::vector<std::vector<cv::Point>> PillCounter::detectPills(const cv::Mat& processed) {
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    
    // 查找轮廓
    cv::findContours(processed, contours, hierarchy,
        cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    
    // 过滤小轮廓（噪声）
    std::vector<std::vector<cv::Point>> validContours;
    for (const auto& contour : contours) {
        double area = cv::contourArea(contour);
        if (area > 1000) { // 面积阈值可以根据实际情况调整
            validContours.push_back(contour);
        }
    }
    
    return validContours;
}
