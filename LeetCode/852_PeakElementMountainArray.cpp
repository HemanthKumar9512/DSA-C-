/*
You are given an integer mountain array arr of length n where the values increase to a peak 
element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1
*/

#include<iostream>
using namespace std;
// arr[0], arr[n-1] != peak

int peakElement(int* arr, int n){                  // Time Complexity: O(logn)
    int st=1, end=n-2;
    int mid= st+(end-st)/2;
    if (arr[mid]-1<arr[mid] && arr[mid]>arr[mid+1]){
        return mid;
    }
    if(arr[mid-1]<arr[mid]){
        st=mid+1;
    }
    else{
        end=mid-1;
    }
}
int main(){
    int arr[]={0,3,8,9,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<peakElement(arr,n)<<endl;
    return 0;
}