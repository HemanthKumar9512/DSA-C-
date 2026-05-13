/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] 
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>> BruteForce(vector<int>& nums){       // Time Complexity: O(n^3 * log(unique_Triplets))
    int n=nums.size();                                   // Space Complexity: O(2 * unique_Triplets)
    set<vector<int>> s;
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int> trip={nums[i], nums[j], nums[k]};
                    sort(trip.begin(), trip.end());
                    if(s.find(trip)==s.end()){
                        s.insert(trip);
                        ans.push_back(trip);
                    }
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> BetterApproach(vector<int>& nums){
    int n=nums.size();
    //vector<vector<int>> ans;
    set<vector<int>> uniqueTriplets;     // To Store Unique Elements
    for(int i=0; i<n; i++){
        int tar=-nums[i];
        set<int>s;
        for(int j=i+1; j<n; j++){
            int third = tar-nums[j];
            if(s.find(third)!=s.end()){
                vector<int> trip={nums[i], nums[j], third};
                sort(trip.begin(), trip.end());
                uniqueTriplets.insert(trip);
            }
            s.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
    return ans;
}

vector<vector<int>> optimalApproach(vector<int>& nums){  // Time Complexity: O(nlog n + n^2)
    int n=nums.size();                                   // Space Complexity: O(uniqueTriplets)
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j=i+1, k=n-1;
        while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum<0)j++;
            else if(sum>0) k--;
            else{
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j<k && nums[j]==nums[j-1])j++;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> nums={-1, 0, 1, 2, -1, -4};
    vector<vector<int>> sol=BruteForce(nums);
    cout<<"Brute Force:"<<endl;
    for(auto val: sol){
        for(auto ans: val){
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    cout<<"Better Approach"<<endl;
    vector<vector<int>> res=BetterApproach(nums);
    for(auto val: res){
        for(auto ans: val){
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    cout<<"Optimal Approach: "<<endl;
    vector<vector<int>> result=optimalApproach(nums);
    for(auto val: result){
        for(auto ans: val){
            cout<<ans<<" ";
        }
        cout<<endl;
    }

    return 0;
}