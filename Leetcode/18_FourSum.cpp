/*
Given an array nums of n integers, return an array of all the unique quadruplets 
[nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums){    // Time Complexity: O(nlogn+n^3)
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1; j<n; ){

            int p=j+1, q=n-1;
            while(p<q){
                long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[p]+(long long)nums[q];
                if(sum>0){
                    q--;
                }
                else if(sum<0){
                    p++;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[p], nums[q]});
                    p++;
                    q--;
                    while(p<q && nums[p]==nums[p-1]) p++;
                }
            }
            j++;
            while(j<n && nums[j]==nums[j-1])j++;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={-2, -1, -1, 1, 1, 2, 2};
    vector<vector<int>> res=fourSum(arr);
    for(auto val: res){
        for(auto ans: val){
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}