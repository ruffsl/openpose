#ifndef OPENPOSE__CORE__SCALE_KEY_POINTS_HPP
#define OPENPOSE__CORE__SCALE_KEY_POINTS_HPP

#include "array.hpp"

namespace op
{
    OPENPOSE_API void scaleKeyPoints(Array<float>& keyPoints, const double scale);

	OPENPOSE_API void scaleKeyPoints(Array<float>& keyPoints, const double scaleX, const double scaleY);

	OPENPOSE_API void scaleKeyPoints(Array<float>& keyPoints, const double scaleX, const double scaleY, const double offsetX, const double offsetY);
}

#endif // OPENPOSE__CORE__SCALE_KEY_POINTS_HPP
