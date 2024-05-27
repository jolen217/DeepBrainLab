#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;

int main() {
    VideoCapture cap; // Open default camera (index 0)
    cap.open(0);
    if (!cap.isOpened()) {
        cout << "Error: Camera not opened\n";
        return -1;
    }

    CascadeClassifier face_cascade, eye_cascade;
    string faces_cascade_name = "../../data/haarcascades/haarcascade_frontalface_alt.xml";
    string eyes_cascade_name = "../../data/haarcascades/haarcascade_eye.xml";
    if (!face_cascade.load(faces_cascade_name)) {
        cout << "Error: loading faces cascade fails" << endl;
        return -1;
    }
    if (!eye_cascade.load(eyes_cascade_name)) {
        cout << "Error: loading eyes cascade fails" << endl;
        return -1;
    }

    Mat frame;
    while (true) {
        cap >> frame; // Grab a frame from the camera

        if (frame.empty()) {
            cout << "Error: Blank frame grabbed\n";
            break;
        }

        vector<Rect> faces;
        face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(100,100));
        for (size_t ii = 0; ii < faces.size(); ii++) {
            Point center(faces[ii].x + faces[ii].width*0.5, faces[ii].y + faces[ii].height*0.5);
            ellipse(frame, center, Size(faces[ii].width*0.5, faces[ii].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
            vector<Rect> eyes;
            Mat faceROI = frame(faces[ii]);
            eye_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(5,5));
            for (size_t i = 0; i < eyes.size(); i++) {
                Point center(faces[ii].x + eyes[i].x + eyes[i].width*0.5, faces[ii].y + eyes[i].y + eyes[i].height*0.5);
                int radius = (eyes[i].width + eyes[i].height) * 0.25;
                circle(frame, center, radius, Scalar(255, 0, 0), 4, 8, 0);
            }
        }

        imshow("Camera", frame); // Display the frame in a window

        char key = waitKey(1); // Wait for a key press (1ms)
        if (key == 27) // Press 'ESC' to exit the loop (ASCII code for 'ESC' is 27)
            break;
    }

    destroyAllWindows(); // Close all OpenCV windows

    return 0;
}
