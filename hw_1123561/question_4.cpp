//Henry-1123561
//28-11-2024
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Task {
    int profit;
    int deadline;

    bool operator<(const Task& other) const {
        return profit < other.profit;
    }
};

int main() {
    int N;
    cin >> N;
    vector<Task> tasks(N);
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i].profit >> tasks[i].deadline;
    }

    // Sort tasks by profit in descending order
    sort(tasks.rbegin(), tasks.rend());

    int maxDeadline = 0;
    for (const Task& task : tasks) {
        maxDeadline = max(maxDeadline, task.deadline);
    }

    // Use a priority queue to schedule the tasks
    priority_queue<int, vector<int>, greater<int>> pq;
    int totalProfit = 0;
    vector<int> scheduledTasks;

    for (const Task& task : tasks) {
        if (pq.size() < task.deadline) {
            pq.push(task.profit);
            totalProfit += task.profit;
            scheduledTasks.push_back(task.profit);
        } else if (!pq.empty() && pq.top() < task.profit) {
            totalProfit += task.profit - pq.top();
            pq.pop();
            pq.push(task.profit);
            scheduledTasks.push_back(task.profit);
        }
    }

    cout << "Maximum Profit: " << totalProfit << endl;
    cout << "Scheduled Tasks: [";
    for (int i = 0; i < scheduledTasks.size(); ++i) {
        cout << scheduledTasks[i];
        if (i < scheduledTasks.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
