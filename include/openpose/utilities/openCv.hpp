#ifndef OPENPOSE__UTILITIES__OPEN_CV_HPP
#define OPENPOSE__UTILITIES__OPEN_CV_HPP

#include <opencv2/core/core.hpp> // cv::Mat, cv::Point
#include <opencv2/imgproc/imgproc.hpp> // cv::warpAffine, cv::BORDER_CONSTANT

namespace op
{
	OPENPOSE_API void putTextOnCvMat(cv::Mat& cvMat, const std::string& textToDisplay, const cv::Point& position, const cv::Scalar& color, const bool normalizeWidth);

	OPENPOSE_API void floatPtrToUCharCvMat(cv::Mat& cvMat, const float* const floatImage, const cv::Size& resolutionSize, const int resolutionChannels);

	OPENPOSE_API void unrollArrayToUCharCvMat(cv::Mat& cvMatResult, const Array<float>& array);

	OPENPOSE_API void uCharCvMatToFloatPtr(float* floatImage, const cv::Mat& cvImage, const bool normalize);

	OPENPOSE_API double resizeGetScaleFactor(const cv::Size& initialSize, const cv::Size& targetSize);

	OPENPOSE_API cv::Mat resizeFixedAspectRatio(const cv::Mat& cvMat, const double scaleFactor, const cv::Size& targetSize, const int borderMode = cv::BORDER_CONSTANT,
                                   const cv::Scalar& borderValue = cv::Scalar{0,0,0});
}

#endif // OPENPOSE__UTILITIES__OPEN_CV_HPP
