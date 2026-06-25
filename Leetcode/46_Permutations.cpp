/*
Find all the possible permutation of the given number.
*/
#include<iostream>
#include<vector>
using namespace std;
void getPermutate(vector<int>& nums, int idx, vector<vector<int>>& ans){
    if(idx==nums.size()){
        ans.push_back({nums});
        return;
    }
    for(int i=idx; i<nums.size(); i++){
        swap(nums[idx], nums[i]);
        getPermutate(nums, idx+1, ans);
        swap(nums[idx], nums[i]);
    }
}
vector<vector<int>> permutate(vector<int>& nums){
    vector<vector<int>> ans;
    getPermutate(nums, 0, ans);
    return ans;
}
int main(){
    vector<int> nums={1,2,0};
    vector<vector<int>> ans;
    ans = permutate(nums);
    for(auto val: ans){
        for(auto sol: val){
            cout<<sol;
        }
        cout<<endl;
    }
    return 0;
}