/*
Given an array of integers nums and an integer target, return indices of the two numbers such that 
they add up to target. You may assume that each input would have exactly one solution, and you may
not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

#include<iostream>
#include<vector>
#include<algorithm> // Used for sorting
using namespace std;

vector<int> pairSum(vector<int>& nums,int target){
    vector<int>ans;
    int n=nums.size();
    for(int i=0;i<n;i++){  
        for(int j=i+1;j<n;j++){ // Starts at i+1 to avoid picking same element twice
            if (nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans; // Return if answer found
            } 
        }  
    }
    return ans;  //Return empty vector if answer not found
}

//Time Complexity: O(n)
vector<int> Optimized(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) {     // Store value with its original index
        vec.push_back({nums[i], i});
    }
    sort(vec.begin(), vec.end());   // Sort the vector based on values: O(n log n)
    int left = 0, right = n - 1;    // // Use two pointers: O(n)
    while (left < right) {
        int currentSum = vec[left].first + vec[right].first;
        if (currentSum == target) {
            return {vec[left].second, vec[right].second};
        } else if (currentSum < target) {
            left++; // Need a larger sum
        } else {
            right--; // Need a smaller sum
        }
    }

    return {};
}
    
int main(){
    vector<int> nums={5,3,2,4};
    int target=9;
    vector<int> ans=pairSum(nums,target);
    cout<<"Brute Force: "<<ans[0]<<","<<ans[1]<<endl;
    vector<int> res=Optimized(nums,target);
    cout<<"Optimized: "<<res[0]<<","<<res[1]<<endl;
    return 0;
}


