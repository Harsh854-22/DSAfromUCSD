#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <float.h>
using namespace std;

struct Point {
    long long x, y;
};

bool compareX(Point a, Point b) {
    return a.x < b.x;
}

bool compareY(Point a, Point b) {
    return a.y < b.y;
}

double dist(Point p1, Point p2) {
    return sqrt((double)(p1.x - p2.x) * (p1.x - p2.x) + (double)(p1.y - p2.y) * (p1.y - p2.y));
}

double bruteForce(vector<Point> &points, int left, int right) {
    double minDist = DBL_MAX;
    for (int i = left; i < right; ++i) {
        for (int j = i + 1; j < right; ++j) {
            minDist = min(minDist, dist(points[i], points[j]));
        }
    }
    return minDist;
}

double stripClosest(vector<Point> &strip, double d) {
    double minDist = d;
    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; ++j) {
            minDist = min(minDist, dist(strip[i], strip[j]));
        }
    }

    return minDist;
}

double closestUtil(vector<Point> &pointsSortedX, int left, int right) {
    if (right - left <= 3)
        return bruteForce(pointsSortedX, left, right);

    int mid = (left + right) / 2;
    Point midPoint = pointsSortedX[mid];

    double dl = closestUtil(pointsSortedX, left, mid);
    double dr = closestUtil(pointsSortedX, mid, right);

    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if (abs(pointsSortedX[i].x - midPoint.x) < d)
            strip.push_back(pointsSortedX[i]);
    }

    return min(d, stripClosest(strip, d));
}

double closest(vector<Point> &points) {
    vector<Point> pointsSortedX = points;
    sort(pointsSortedX.begin(), pointsSortedX.end(), compareX);
    return closestUtil(pointsSortedX, 0, pointsSortedX.size());
}

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    printf("%.9lf\n", closest(points));
    return 0;
}
    