#include<iostream>
using namespace std;
void quicksort(int arr[],int l,int h)
{
    if(l<h)
    {
        int pivot=l,i=l+1,j=h;
        while(i<=j)
        {
            while(arr[i]<=arr[pivot] && i<=h)
            i++;
            while(arr[j]>arr[pivot] &&i>=l)
            j--;
            if(i<j)
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }    
        }
        int temp=arr[l];
        arr[l]=arr[j];
        arr[j]=temp;
        quicksort(arr,l,j-1);
        quicksort(arr,j+1,h);
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[]={64, 25, 12, 22, 11,5,85,15,3,41,59};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n);
    printArray(arr,n);
    return 0;
}
