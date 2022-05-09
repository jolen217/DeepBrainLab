#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
    int x, y;
};

// @brief: Calculate area of irregular polygon
// @param[in] v: input vertex coordinates
// @return: area of polygon
// @warning: polygon with self-crossing/overlap is out of scope
// @see https://www.mathopenref.com/polygonirregulararea.html
double PolygonArea(const vector<Vertex>& v) {
    int num = v.size();
    if (num < 3) return 0.0;

    int area = (v[num-1].x + v[0].x) * (v[num-1].y - v[0].y);
    for (int i = 1; i < num; i++) {
        area += (v[i-1].x + v[i].x) * (v[i-1].y - v[i].y);
    }
    if (area < 0) area = 0 - area;

    return area / 2.0;
}


