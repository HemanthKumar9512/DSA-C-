/*
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

#include<iostream>
#include<vector>
using namespace std;
// Time Complexity: O(n * 2^n)
void getAllSubsets(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>> &allSubsets){
    if( i == arr.size()){
        allSubsets.push_back({ans});
        return;
    }
    ans.push_back(arr[i]);
    getAllSubsets(arr, ans, i+1, allSubsets);
    ans.pop_back();
    getAllSubsets(arr, ans, i+1, allSubsets);
}
vector<vector<int>> subsets(vector<int>& arr){
    vector<vector<int>> allSubsets;
    vector<int> ans;
    getAllSubsets(arr ,ans, 0, allSubsets);
    return allSubsets;
}

int main(){
    vector<int> arr={1,2,3};
    vector<vector<int>> ans;
    ans=subsets(arr);
    for(vector<int> val: ans){
        for(int sol: val){
            cout<<sol;
        }
        cout<<endl;
    }
    return 0;

}