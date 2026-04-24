/*
There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly left rotated at an unknown 
index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1],
 nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated 
 by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
#include<iostream>
using namespace std;
int searchRotatedSortedArray(int* arr, int n, int &tar){        // Time Complexity: O(logn)
    int st=0, end=n-1;
    int mid=st+(end-st)/2;
    if(arr[mid]==tar){
        return mid;
    }
    if(arr[st]<=arr[mid]){               //Left Sorted
        if(arr[st]<=tar<=arr[mid]){      // Left 
            end=mid-1;
        }
        else {                           //Right
            st=mid+1;
        }
    }
    else{                            //Right Soeted
        if(arr[mid]<=tar<=arr[end]){ //Right
            st=mid+1;
        }
        else{                        //Left
            end=mid-1;
        }
    }
}
int main(){
    int arr[]={3,4,5,6,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=2;
    cout<<searchRotatedSortedArray(arr, n, target);
    return 0;
}