#include<iostream>
using namespace std;
int binarySearch(int* arr, int tar, int st, int end){
    if(st<=end){
        int mid=st+(end-st)/2;
        if(tar>arr[mid]){
            return binarySearch(arr, tar, mid+1, end);
        }
        else if(tar<arr[mid]){
            return binarySearch(arr, tar, st, mid-1);
        }
        else{
            return mid;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,3,4,5};
    int target=1;
    int n=sizeof(arr)/sizeof(arr[0]);
    int st=0;
    int end=n-1;
    cout<<binarySearch(arr, target, st, end);
    return 0; 
}

// Time Complexity: O(logn)