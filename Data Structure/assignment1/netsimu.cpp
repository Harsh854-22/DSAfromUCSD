#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Request {
    int arrival_time, process_time;
};

struct Response {
    bool dropped;
    int start_time;
};

class Buffer {
private:
    int size;
    queue<int> finish_times;

public:
    Buffer(int size) : size(size) {}

    Response Process(const Request &request) {
        while (!finish_times.empty() && finish_times.front() <= request.arrival_time)
            finish_times.pop();

        if (finish_times.size() == size)
            return {true, -1};

        int start_time = max(finish_times.empty() ? 0 : finish_times.back(), request.arrival_time);
        finish_times.push(start_time + request.process_time);
        return {false, start_time};
    }
};

int main() {
    int buffer_size, n;
    cin >> buffer_size >> n;

    vector<Request> requests(n);
    for (int i = 0; i < n; ++i)
        cin >> requests[i].arrival_time >> requests[i].process_time;

    Buffer buffer(buffer_size);
    for (const Request &request : requests) {
        Response response = buffer.Process(request);
        cout << (response.dropped ? -1 : response.start_time) << endl;
    }

    return 0;
}
