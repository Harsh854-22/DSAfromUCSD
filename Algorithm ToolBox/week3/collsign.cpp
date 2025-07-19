#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int start, end;
};

bool compare(Segment a, Segment b) {
    return a.end < b.end;
}

vector<int> optimal_points(vector<Segment>& segments) {
    sort(segments.begin(), segments.end(), compare);
    vector<int> points;
    int current = -1;

    for (auto s : segments) {
        if (current < s.start) {
            current = s.end;
            points.push_back(current);
        }
    }

    return points;
}

int main() {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (int i = 0; i < n; ++i)
        cin >> segments[i].start >> segments[i].end;

    vector<int> points = optimal_points(segments);
    cout << points.size() << "\n";
    for (int p : points)
        cout << p << " ";
    cout << endl;
    return 0;
}
