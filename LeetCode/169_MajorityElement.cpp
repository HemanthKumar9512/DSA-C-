/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

// Brute ForceApproach:  Time Complexity: O(n^2), Space Complexity: O(1)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int majorityElementBruteForce(vector<int>& nums){
    int n=nums.size();
    for(int val: nums){
        int freq=0;
        for(int elem: nums){
            if (elem==val){
                freq++;
            }
        }
        if (freq>n/2){
            return val;
        }
    }
    return -1;
}


//Optimized Approach: Time Complexity: O(n.logn+n)=O(nlogn), Space Complexity: O(1)
int majorityElementOptimized(vector<int>&nums){
    sort(nums.begin(),nums.end());   //Sorting by vector
    int n=nums.size();               //1,1,1,2,2,2,2
    return nums[n/2];
}

//Moore's Algorithm: Time Complexity:O(n)
int morreAlgorithm(vector<int>&nums){
    //same_el:freq++      dif_el:freq--;
    int freq=0, ans=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(freq==0){
            ans=nums[i];
        }
        if(ans==nums[i]){
            freq++;
        }
        else{freq--;}
    }
    return ans;
}

int main(){
    vector<int>nums={2,2,1,1,1,2,2};
    cout<<"Brute Force: "<<majorityElementBruteForce(nums)<<endl;;
    cout<<"Optimized: "<<majorityElementOptimized(nums)<<endl;
    cout<<"Moore Algorithm: "<<morreAlgorithm(nums)<<endl;
    return 0;
}