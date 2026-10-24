#ifndef COMMON_CPP
#define COMMON_CPP

#include <iostream>
#include <vector>
#include <string>

struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct Frame {
    int width;
    int height;
    std::vector<unsigned char> data;
    long long timestamp;

    Frame() : width(0), height(0), timestamp(0) {}
    Frame(int w, int h) : width(w), height(h), data(w * h, 0), timestamp(0) {}
};

struct AsciiConfig {
    int outputWidth = 80;
    int outputHeight = 40;
    std::string densityRamp = " .:-=+*#%@";
    bool useAdaptiveGrid = true;
    bool enableEdgeTracing = true;
};

#endif
