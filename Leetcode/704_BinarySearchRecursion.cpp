/*
Given an array of integers nums which is sorted in ascending order, and an integer target, 
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

#include<iostream>
#include<vector>
using namespace std;

int bS(vector<int> arr, int target, int st, int end){
    int mid=st+(end-st)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]<=target){
        return bS(arr, target, mid+1, end);
    }
    else{
        return bS(arr, target, st, mid-1);
    }
    return -1;
}
int main(){
    vector<int> arr={1,2,3,4,5};           // Time Complexity: O(log n)
    int n=arr.size();                      // Space Complexity: O(log n)
    int target = 2;
    int st=arr[0];
    int end=arr[n-1];
    cout<<bS(arr, target, st, end);
}