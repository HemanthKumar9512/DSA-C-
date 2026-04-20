/*
Input, nums=[2,7,11,15]
target=9
Output, [0,1]
*/
#include<iostream>
#include<vector>
using namespace std;

class solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            int n=nums.size();
            int i=0,j=n-1;
            vector<int>ans;
            while(i<j){
                int pairSum=nums[i]+nums[j];
                if(pairSum>target){
                    j--;
                }
                else if(pairSum<target){
                    i++;
                }
                else{
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
            return ans;
        }
}