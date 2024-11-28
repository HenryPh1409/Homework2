//Henry-1123561
//28-11-2024
#include <iostream>
#include <queue>
#include <vector>
#include <sstream> 
using namespace std;

struct Element {
    int value;
    int arrayIndex;
    int elementIndex;

    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    vector<int> result;

    // Insert the first element of each array into the min heap
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    // Extract the smallest element from the heap and insert the next element from the same array
    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();
        result.push_back(current.value);

        if (current.elementIndex + 1 < arrays[current.arrayIndex].size()) {
            minHeap.push({arrays[current.arrayIndex][current.elementIndex + 1], current.arrayIndex, current.elementIndex + 1});
        }
    }

    return result;
}

int main() {
    int K;
    cin >> K;
    cin.ignore(); // Ignore the newline after reading K
    vector<vector<int>> arrays(K);

    for (int i = 0; i < K; ++i) {
        string line;
        getline(cin, line); // Read the entire line
        stringstream ss(line); 
        int num;
        while (ss >> num) {
            arrays[i].push_back(num);
        }
    }

    vector<int> mergedArray = mergeKSortedArrays(arrays);
    cout << "Merged Array: [";
    for (int i = 0; i < mergedArray.size(); ++i) {
        cout << mergedArray[i];
        if (i < mergedArray.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
