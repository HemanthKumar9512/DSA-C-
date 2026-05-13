#include<iostream>
#include<algorithm>
using namespace std;
/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear 
order.
For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], 
[2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation 
of its integer. More formally, if all the permutations of the array are sorted in one container 
according to their lexicographical order, then the next permutation of that array is the 
permutation that follows it in the sorted container. If such arrangement is not possible, 
the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a 
lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.
The replacement must be in place and use only constant extra memory.

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]
*/

// Brute Forcce: Find all permutations and then find the next lexical,  Time Complexity: O(n!*n)
//Optimal
int optimal(int* nums, int n){
    int pivot=-1;
    for(int i=n-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            pivot=i;
            break;
        }
    }
    if(pivot==-1){
        reverse(nums, nums+n);
    }
    for(int i=n-1;i>pivot;i--){
        if(nums[i]>nums[pivot]){
            swap(nums[i], nums[pivot]);
            break;
        }
    }
    int i=pivot+1, j=n-1;
    while(i<=j){
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
}
int main(){
    int nums[]={1,2,3};
    int n=sizeof(nums)/sizeof(nums[0]);
    optimal(nums, n);
    return 0;
}