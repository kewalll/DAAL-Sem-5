#include <iostream>
using namespace std;

int binary_search(int arr[], int low, int high, int target) {
  if (low > high) { 
    return -1;
  }

  int mid = low + (high - low) / 2;
  if (target == arr[mid]) {
    return mid;
  } else if (target < arr[mid]) {
    return binary_search(arr, low, mid - 1, target);
  } else {
    return binary_search(arr, mid + 1, high, target);
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target = 5;
  int N = sizeof(arr) / sizeof(arr[0]);
  int res = binary_search(arr, 0, N - 1, target);
  if (res == -1) {
    cout << "Element not found." << endl;
  } else {
    cout << "Element found at index " << res << "." << endl;
  }
  return 0;
}
