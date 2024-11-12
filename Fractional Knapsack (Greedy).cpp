#include <bits/stdc++.h>
using namespace std;
struct Item {
	int profit, weight;
	Item(int profit, int weight)
	{
		this->profit = profit;
		this->weight = weight;
	}
};
static bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int N)
{
	sort(arr, arr + N, cmp);
	double finalvalue = 0.0;
	float itemCount = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
			itemCount++;
		}
		else {
		    double fraction = (double)W / (double)arr[i].weight;
			finalvalue += arr[i].profit * fraction;
			itemCount += fraction;
			break;
		}
	}
	cout << "Total number of items (or fractions thereof) in the knapsack: " << itemCount << endl;
	return finalvalue;
}
int main()
{
	int W = 50;
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
	int N = sizeof(arr) / sizeof(arr[0]);
	cout << fractionalKnapsack(W, arr, N);
	return 0;
}
