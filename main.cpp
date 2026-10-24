#include <iostream>
#include "common.cpp"
#include "camera_stream.cpp"

using namespace std;

int main() {
    CameraStream camera(60, 20);
    camera.start();

    camera.captureFrame();
    camera.captureFrame();
    camera.captureFrame();

    Frame currentFrame;
    if (!camera.getLatestFrame(currentFrame)) {
        cerr << "Error fetching frame" << endl;
        return 1;
    }

    cout << "Frame captured successfully: " << currentFrame.width << "x" << currentFrame.height << endl;

    return 0;
}
