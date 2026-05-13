#include<iostream>
using namespace std;
/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two 
integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside 
the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements 
denote the elements that should be merged, and the last n elements are set to 0 and should be 
ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
*/
int mergeArrays(int* nums1, int* nums2, int m, int n){
    int idx=m+n-1, j=n-1, i=m-1;
    while(i>=0 && j>=0){
        if(nums1[i]>=nums2[j]){
            nums1[idx--]=nums1[i--];
        }
        else{
            nums1[idx--]=nums2[j--];
        }
    }
    while(j>=0){
        nums1[idx--]=nums2[j--];
    }
    for(int i=0;i<m+n;i++){
        if(nums1[i]!=0){
            cout<<nums1[i]<<" ";
        }
    }
    cout<<endl;
}
int main(){
    int nums1[6]={1,2,3};
    int nums2[]={4,5,6};
    int m=sizeof(nums1)/sizeof(nums1[0]);
    int n=sizeof(nums2)/sizeof(nums2[0]);
    mergeArrays(nums1, nums2, m, n);
    return 0;
}