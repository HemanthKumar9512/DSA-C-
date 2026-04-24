/* 
Given a non-empty array of integers nums, every element appears twice except for one. 
Find the single one. You must implement a solution within a linear runtime complexity 
and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
*/
#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums){
    int ans=0;
    for(int val: nums){
        ans=ans^val;                    //n^n=0      Bitwise Operator: Same inputs -> 0
    }                                  // n^0=n 
    cout<<ans;                                     
    return ans;
}
int main(){
    vector<int>vec={2,2,1};          // Time Complexity: O(1)
    singleNumber(vec);
    return 0;
}