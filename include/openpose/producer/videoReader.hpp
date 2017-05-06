#ifndef OPENPOSE__PRODUCER__VIDEO_READER_HPP
#define OPENPOSE__PRODUCER__VIDEO_READER_HPP

#include "videoCaptureReader.hpp"

namespace op
{
    /**
     * VideoReader is a wrapper of the cv::VideoCapture class for video. It allows controlling a webcam (extracting frames,
     * setting resolution & fps, etc).
     */
    class OPENPOSE_API VideoReader : public VideoCaptureReader
    {
    public:
        /**
         * Constructor of VideoReader. It opens the video as a wrapper of cv::VideoCapture. It includes a flag to indicate
         * whether the video should be repeated once it is completely read.
         * @param videoPath const std::string parameter with the full video path location.
         */
        explicit VideoReader(const std::string& videoPath);

        std::string getFrameName();

        inline double get(const int capProperty)
        {
            return VideoCaptureReader::get(capProperty);
        }

    private:
        const std::string mPathName;

        cv::Mat getRawFrame();

        DELETE_COPY(VideoReader);
    };
}

#endif // OPENPOSE__PRODUCER__VIDEO_READER_HPP
