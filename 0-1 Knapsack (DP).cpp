#include <iostream>
using namespace std;
int knapsack(int weights[], int values[], int capacity, int n) {
    if (capacity == 0 || n == 0) {
        return 0;
    }
    if (weights[n - 1] > capacity) {
        return knapsack(weights, values, capacity, n - 1);
    }
    else {
        return max(values[n - 1] + knapsack(weights, values, capacity - weights[n - 1], n - 1),
                   knapsack(weights, values, capacity, n - 1));
    }
}
int main() {
    int weights[] = {20, 10, 30};
    int values[] = {100, 60, 120};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);
    int maxProfit = knapsack(weights, values, capacity, n);
    cout << "Maximum profit: " << maxProfit << endl;
    return 0;
}
