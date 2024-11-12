#include<iostream>
using namespace std;

int linear_search(int arr[], int N, int t){
    if (N == 0)
        return -1;
    
    if(arr[N-1] == t)
        return N-1;
    
    return linear_search(arr, N-1, t);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int t = 5;
    int N = sizeof(arr)/sizeof(arr[0]);
    int res = linear_search(arr, N, t);
    if (res == -1){
        cout << "Element not found.";
    }
    else{
        cout << "Element found at index " << res << "."; 
    }
}
