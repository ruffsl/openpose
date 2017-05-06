#ifndef OPENPOSE__UTILITIES__PROFILER_HPP
#define OPENPOSE__UTILITIES__PROFILER_HPP

#include <string>

// Enable PROFILER_ENABLED on Makefile.config in order to use this function. Otherwise nothing will be outputted.

// How to use - example:
// For GPU - It can only be applied in the main.cpp file:
    // Profiler::profileGpuMemory(__LINE__, __FUNCTION__, __FILE__);
// For time:
    // // ... inside continuous loop ...
    // const auto profilerKey = Profiler::timerInit(__LINE__, __FUNCTION__, __FILE__);
    // // functions to do...
    // Profiler::timerEnd(profilerKey);
    // Profiler::printAveragedTimeMsOnIterationX(profilerKey, __LINE__, __FUNCTION__, __FILE__, 1000);

namespace op
{
    class OPENPOSE_API Profiler
    {
    public:
        static const std::string timerInit(const int line, const std::string& function, const std::string& file);

        static void timerEnd(const std::string& key);

        static void printAveragedTimeMsOnIterationX(const std::string& key, const int line, const std::string& function, const std::string& file, const unsigned long long x);

        static void printAveragedTimeMsEveryXIterations(const std::string& key, const int line, const std::string& function, const std::string& file, const unsigned long long x);

        static void profileGpuMemory(const int line, const std::string& function, const std::string& file);
    };
}

#endif // OPENPOSE__UTILITIES__PROFILER_HPP
