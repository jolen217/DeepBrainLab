#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
    cout << "Loading video ..." << endl;

    VideoCapture cap("../data/backfoot03.mp4");
    if (!cap.isOpened()) {
        cout << "Error: loading fails!" << endl;
        return -1;
    }

    while (1) {
        Mat frame; 
        cap >> frame;

        if (frame.empty()) {
            cout << "End of video" << endl;
            break;
        }

        imshow("Frame | Press ESC to close", frame);

        if (waitKey(100) == 27) break;
    }

    cap.release();

    destroyAllWindows();

    return 0;
}