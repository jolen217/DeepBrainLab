// t0: {x1,y1,w1,h1,c1}, {x2,y2,w2,h2,c2} => IoU
// t1: {0,0,3,3,0.9}, {1,1,4,4,0.9}
// t2: {0,0,3,3,0.9}, {2,2,5,5,0.8}
// t3: {0,0,3,3,0.9}, {3,3,5,5,0.7}
// t4: {0,0,3,3,0.9}, {1,1,1,1,0.6}
// t5: {0,0,3,3,0.9}, {0,0,3,3,0.5}
// t6: {0,0,3,3,0.9}, {0,1,3,2,0.4}

#include <iostream>
#include <vector>
#include <algorithm>
#include "DBLImage.hpp"

using namespace std;

class BBox {
public:
    BBox(int xx, int yy, int ww, int hh, double cc) : x(xx), y(yy), w(ww), h(hh), conf(cc) {}
    int x;  // x of lower left corner
    int y;  // y of lower left corner
    int w;  // width
    int h;  // height
    double conf;  // confidence
};

bool is_greater(BBox bbox1, BBox bbox2) {
    return bbox1.conf > bbox2.conf;
}

double IoU(BBox bbox1, BBox bbox2) {
    if (bbox1.w <= 0 || bbox1.h <= 0 || bbox2.w <= 0 || bbox2.h <= 0) return 0;
    int illx = max(bbox1.x, bbox2.x);
    int illy = max(bbox1.y, bbox2.y);
    int iurx = min(bbox1.x+bbox1.w-1, bbox2.x+bbox2.w-1);
    int iury = min(bbox1.y+bbox1.h-1, bbox2.y+bbox2.h-1);
    double inter_area = static_cast<double>((iurx - illx + 1) * (iury - illy + 1));
    return inter_area / (bbox1.w*bbox1.h + bbox2.w*bbox2.h - inter_area);
}

vector<BBox> NMS(vector<BBox>& v_bbox, double th_conf) {
    int len = v_bbox.size();
    if (len == 0) return v_bbox;

    vector<BBox> res;
    vector<bool> del(len, false);
    sort(v_bbox.begin(), v_bbox.end(), is_greater);
    for (int i = 0; i < len; i++) {
        if (del[i]) continue;
        for (int j = i+1; j < len; j++) {
            if (!del[j] && IoU(v_bbox[i], v_bbox[j]) > th_conf) del[j] = true;
        }
    }
    for (int i = 0; i < len; i++) {
        if (!del[i]) res.push_back(v_bbox[i]);
    }

    return res;
}

int main() {
    cout << "PI = " << PI << endl;

    vector<BBox> v_bbox;
    v_bbox.push_back(BBox(0,0,3,3,0.9));
    // t6: {0,0,3,3,0.9}, {0,1,3,2,0.4}
    v_bbox.push_back(BBox(0,1,3,2,0.4));
    // t5: {0,0,3,3,0.9}, {0,0,3,3,0.5}
    v_bbox.push_back(BBox(0,0,3,3,0.5));
    // t4: {0,0,3,3,0.9}, {1,1,1,1,0.6}
    v_bbox.push_back(BBox(1,1,1,1,0.6));
    // t3: {0,0,3,3,0.9}, {3,3,5,5,0.7}
    v_bbox.push_back(BBox(3,3,5,5,0.7));
    // t2: {0,0,3,3,0.9}, {2,2,5,5,0.8}
    v_bbox.push_back(BBox(2,2,5,5,0.8));
    // t1: {0,0,3,3,0.9}, {1,1,4,4,0.9}
    v_bbox.push_back(BBox(1,1,4,4,0.9));
    vector<BBox> res;
    res = NMS(v_bbox, 0.5);
    cout << "===>Before NMS: " << endl;
    for (auto bbox : v_bbox) {
        cout << "(" << bbox.x << ","
            << bbox.y << ","
            << bbox.w << ","
            << bbox.h << ","
            << bbox.conf << ")" << endl;
    }
    cout << "===>After NMS: " << endl;
    for (auto bbox : res) {
        cout << "(" << bbox.x << ","
            << bbox.y << ","
            << bbox.w << ","
            << bbox.h << ","
            << bbox.conf << ")" << endl;
    }
    return 0;
}
