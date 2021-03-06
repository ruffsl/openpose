#ifndef OPENPOSE__PRODUCER__PRODUCER_HPP
#define OPENPOSE__PRODUCER__PRODUCER_HPP

#include <chrono>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>      // capProperties of OpenCV
#include "../utilities/macros.hpp"
#include "enumClasses.hpp"

namespace op
{
    /**
     * Producer is an abstract class to extract frames from a source (image directory, video file,
     * webcam stream, etc.). It has the basic and common functions (e.g. getFrame, release & isOpened).
     */
    class Producer
    {
    public:
        /**
         * Constructor of Producer.
         * @param repeatWhenFinished bool indicating whether the producer must be restarted after
         * it finishes.
         */
        explicit Producer(const ProducerType type);

        /**
         * Destructor of Producer. It is virtual so that any children class can implement
         * its own destructor.
         */
        virtual ~Producer();

        /**
         * Main function of Producer, it retrieves and returns a new frame from the frames producer.
         * @return cv::Mat with the new frame. 
         */
        cv::Mat getFrame();

        /**
         * This function returns a unique frame name (e.g. the frame number for video, the
         * frame counter for webcam, the image name for image directory reader, etc.).
         * @return std::string with an unique frame name.
         */
        virtual std::string getFrameName() = 0;

        /**
         * This function sets whether the producer must keep the original fps frame rate or extract the frames as quick
         * as possible.
         * @param fpsMode ProducerFpsMode parameter specifying the new value.
         */
        void setProducerFpsMode(const ProducerFpsMode fpsMode);

        /**
         * This function returns the type of producer (video, webcam, ...).
         * @return ProducerType with the kind of producer.
         */
        inline ProducerType getType()
        {
            return mType;
        }

        /**
         * This function returns whether the Producer instance is still opened and able
         * to retrieve more frames.
         * @return bool indicating whether the Producer is opened.
         */
        virtual bool isOpened() const = 0;

        /**
         * This function releases and closes the Producer. After it is called, no more frames
         * can be retrieved from Producer::getFrame.
         */
        virtual void release() = 0;

        /**
         * This function is a wrapper of cv::VideoCapture::get. It allows getting different properties
         * of the Producer (fps, width, height, etc.). See the OpenCV documentation for all the
         * available properties.
         * @param capProperty int indicating the property to be modified.
         * @return double returning the property value.
         */
        virtual double get(const int capProperty) = 0;

        /**
         * This function is a wrapper of cv::VideoCapture::set. It allows setting different properties
         * of the Producer (fps, width, height, etc.). See the OpenCV documentation for all the
         * available properties.
         * @param capProperty int indicating the property to be modified.
         * @param value double indicating the new value to be assigned.
         */
        virtual void set(const int capProperty, const double value) = 0;

        virtual double get(const ProducerProperty property) = 0;

        virtual void set(const ProducerProperty property, const double value) = 0;

    protected:
        /**
         * Protected function which checks that the frames keeps their integry (some OpenCV versions
         * might return corrupted frames within a video or webcam with a size different to the
         * standard resolution). If the frame is corrupted, it is set to an empty cv::Mat.
         * @param frame cv::Mat with the frame matrix to be checked and modified.
         */
        void checkFrameIntegrity(cv::Mat& frame);

        /**
         * It performs flipping and rotation over the desired cv::Mat.
         * @param cvMat cv::Mat with the frame matrix to be flipped and/or rotated.
         */
        void flipAndRotate(cv::Mat& cvMat) const;

        /**
         * Protected function which checks that the frame producer has ended. If so, if resets
         * or releases the producer according to mRepeatWhenFinished.
         */
        void ifEndedResetOrRelease();

        /**
         * Protected function which forces the producer to get frames at the rate of get(CV_CAP_PROP_FPS).
         */
        void keepDesiredFrameRate();

        /**
         * Function to be defined by its children class. It retrieves and returns a new frame from the frames producer.
         * @return cv::Mat with the new frame. 
         */
        virtual cv::Mat getRawFrame() = 0;

    private:
        const ProducerType mType;
        ProducerFpsMode mProducerFpsMode;
        std::array<double, (int)ProducerProperty::Size> mProperties;
        unsigned int mNumberEmptyFrames;
        // For ProducerFpsMode::OriginalFps
        bool mTrackingFps;
        unsigned long long mFirstFrameTrackingFps;
        unsigned long long mNumberFramesTrackingFps;
        unsigned int mNumberSetPositionTrackingFps;
        std::chrono::high_resolution_clock::time_point mClockTrackingFps;

        DELETE_COPY(Producer);
    };
}

#endif // OPENPOSE__PRODUCER__PRODUCER_HPP
