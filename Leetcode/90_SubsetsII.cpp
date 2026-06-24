/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Time Complexity: O(n * 2^n)
void getAllSubsets(vector<int>& nums, vector<int>& ans, size_t i, vector<vector<int>>& subsets){
    if(i == nums.size()){
        subsets.push_back(ans);
        return;
    }
    ans.push_back(nums[i]);
    getAllSubsets(nums, ans, i+1, subsets);
    ans.pop_back();
    size_t idx = i+1;
    while(idx<nums.size() && nums[idx]==nums[idx-1]){
        idx++;
    }
    getAllSubsets(nums, ans, idx, subsets);

}
vector<vector<int>> allSubsets(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<int> ans;
    vector<vector<int>> subsets;
    getAllSubsets(nums, ans, 0, subsets);
    return subsets;
}
int main(){
    vector<int> nums={1,2,2};
    vector<vector<int>> ans;
    ans = allSubsets(nums);
    for(vector<int> val: ans){
        for(int sol: val){
            cout<<sol;
        }
        cout<<endl;
    }
    return 0;
}