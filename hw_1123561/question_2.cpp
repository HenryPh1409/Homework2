//Henry-1123561
//28-11-2024
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    int priority;

    // Overload the < operator for the priority queue
    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

int main() {
    priority_queue<Task> pq;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string command;
        cin >> command;
        if (command == "ADD") {
            string name;
            int priority;
            cin >> name >> priority;
            pq.push({name, priority});
        } else if (command == "GET") {
            if (!pq.empty()) {
                cout << pq.top().name << endl;
                pq.pop();
            }
        }
    }

    cout << "Remaining tasks: ";
    vector<Task> remainingTasks;
    while (!pq.empty()) {
        remainingTasks.push_back(pq.top());
        pq.pop();
    }

    cout << "[";
    for (int i = 0; i < remainingTasks.size(); ++i) {
        cout << "('" << remainingTasks[i].name << "', " << remainingTasks[i].priority << ")";
        if (i < remainingTasks.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
