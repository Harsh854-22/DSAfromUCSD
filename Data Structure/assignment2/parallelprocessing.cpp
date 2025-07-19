#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Thread {
    int id;
    long long time;

    bool operator<(const Thread &other) const {
        if (time == other.time)
            return id > other.id;
        return time > other.time;
    }
};

int main() {
    int num_threads, num_jobs;
    cin >> num_threads >> num_jobs;

    vector<long long> jobs(num_jobs);
    for (int i = 0; i < num_jobs; i++)
        cin >> jobs[i];

    priority_queue<Thread> pq;
    for (int i = 0; i < num_threads; i++)
        pq.push({i, 0});

    for (int i = 0; i < num_jobs; i++) {
        Thread t = pq.top();
        pq.pop();
        cout << t.id << " " << t.time << "\n";
        t.time += jobs[i];
        pq.push(t);
    }

    return 0;
}
