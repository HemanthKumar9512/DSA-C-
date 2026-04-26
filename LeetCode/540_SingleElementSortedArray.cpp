/*
You are given a sorted array consisting of only integers where every element appears exactly twice,
 except for one element which appears exactly once.
Return the single element that appears only once.
Your solution must run in O(log n) time and O(1) space.

 Example 1:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:
Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

#include<iostream>
using namespace std;
int singleElement(int* arr, int n){
    if(n==1){
        return arr[0];     // Only one element in array
    }
    if(arr[0]!= arr[1]){
        return arr[0];    //arr={1,2,2,3,3}
    }
    if(arr[n-1]!= arr[n-2]){
        return arr[n-1];    //arr={1,1,2,2,3}
    }
    // Edges cases are above
    int st=1, end=n-2;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid-1]!=arr[mid] && arr[mid]!=arr[mid+1]){
            return arr[mid];
        }
        if(mid%2==0){                       //Even Mid
            if(arr[mid-1]==arr[mid]){
                end=mid-1;                  //Left
            }
            else{                           // Right
                st=mid+1;
            }
        }
        else{                               // Odd Mid
            if(arr[mid-1]==arr[mid]){       // Right
                st=mid+1;
            }
            else{                           // Left
                end=mid-1;
            }
        }
    }
}
int main(){
    int arr[]={1,1,2,3,3,7,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<singleElement(arr, n);
    return 0;
}