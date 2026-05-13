/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
 
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int bruteForce(vector<int>& nums, int k){    // Time Complexity: O(n^2)
    int n=nums.size();                       // Space Complexity: O(1)
    int count=0;
    for(int i=0; i<n; i++){
        int currSum=0;
        for(int j=i; j<n; j++){
            currSum+=nums[j];
            if(currSum==k){
                count++;
            }
        }
    }
    return count;
}

int optimal(vector<int>& nums, int k){         // Time Complexity: O(n)
    int n=nums.size();                         // Space Complexity: O(n)
    vector<int> prefixSum(n, 0);
    int freq=0;
    for(int i=0; i<n; i++){
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }
    unordered_map<int,int> m; // PS, freq
    for(int j=0; j<n; j++){
        if(prefixSum[j]==k) freq++;
        int val=prefixSum[j]-k;
        if(m.find(val)!=m.end()){
            freq+=m[val];
        }
        if(m.find(prefixSum[j])==m.end()){
            m[prefixSum[j]]=0;
        }
        m[prefixSum[j]]++;
    }
    return freq;
}
int main(){
    vector<int> nums={1,2,3,4,5};
    int k=5;
    cout<<"Brute Force: "<<bruteForce(nums, k)<<endl;;
    cout<<"Optimal: "<<optimal(nums,k)<<endl;
    
}