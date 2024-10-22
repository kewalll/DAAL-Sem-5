#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int optimalMergeCost(vector<int>& files) {

    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int size : files) {
        minHeap.push(size);
    }
    int totalCost = 0;
    while (minHeap.size() > 1) {
        int file1 = minHeap.top();
        minHeap.pop();
        int file2 = minHeap.top();
        minHeap.pop();
        int mergeCost = file1 + file2;
        totalCost += mergeCost;
        minHeap.push(mergeCost);
    }

    return totalCost;
}

int main() {
    vector<int> files = {5, 10, 15, 20, 25};
    int cost = optimalMergeCost(files);
    cout << "Total cost of merging files: " << cost << endl;

    return 0;
}
