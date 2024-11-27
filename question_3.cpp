#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void printFirstNegative(vector<int> &arr, int k) {
    deque<int> dq;
    for (int i = 0; i < arr.size(); i++) {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        if (arr[i] < 0)
            dq.push_back(i);

        if (i >= k - 1) {
            if (!dq.empty())
                cout << arr[dq.front()] << " ";
            else
                cout << "0 ";
        }
    }
    cout << endl;
}

int main() {
    vector<int> arr = {-8, 2, 3, -6, 10};
    int k = 2;
    cout << "Output: ";
    printFirstNegative(arr, k);

    return 0;
}
