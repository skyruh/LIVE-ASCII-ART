#ifndef CAMERA_STREAM_CPP
#define CAMERA_STREAM_CPP

#include "common.cpp"
#include <iostream>

using namespace std;

template <typename T>
class CircularQueue {
private:
    T* buffer;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    CircularQueue(int maxCapacity = 10) {
        capacity = maxCapacity;
        buffer = new T[capacity];
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    ~CircularQueue() {
        delete[] buffer;
    }

    bool isFull() const {
        return count == capacity;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    bool enqueue(const T& item) {
        if (isFull()) {
            return false;
        }
        rearIndex = (rearIndex + 1) % capacity;
        buffer[rearIndex] = item;
        count++;
        return true;
    }

    bool dequeue(T& outItem) {
        if (isEmpty()) {
            return false;
        }
        outItem = buffer[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;
        return true;
    }
};

class CameraStream {
private:
    CircularQueue<Frame> frameQueue;
    int frameWidth;
    int frameHeight;
    bool isStreamActive;
    long long frameCounter;

public:
    CameraStream(int width = 80, int height = 40) 
        : frameQueue(8), frameWidth(width), frameHeight(height), 
          isStreamActive(false), frameCounter(0) {}

    bool start() {
        isStreamActive = true;
        cout << "Camera stream started (" << frameWidth << "x" << frameHeight << ")" << endl;
        return true;
    }

    void stop() {
        isStreamActive = false;
        cout << "Camera stream stopped" << endl;
    }

    bool captureFrame() {
        if (!isStreamActive) return false;

        Frame newFrame(frameWidth, frameHeight);
        newFrame.timestamp = ++frameCounter;

        for (int y = 0; y < frameHeight; ++y) {
            for (int x = 0; x < frameWidth; ++x) {
                int val = (x * 255 / frameWidth + y * 255 / frameHeight + frameCounter * 8) % 256;
                newFrame.data[y * frameWidth + x] = static_cast<unsigned char>(val);
            }
        }

        if (!frameQueue.enqueue(newFrame)) {
            Frame dropped;
            frameQueue.dequeue(dropped);
            frameQueue.enqueue(newFrame);
        }

        return true;
    }

    bool getLatestFrame(Frame& outFrame) {
        return frameQueue.dequeue(outFrame);
    }
};

#endif
