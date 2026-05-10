/*
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int bruteForce(vector<int>& arr){
    int n=arr.size();                  // Time Complexity: O(nlogn)
    sort(arr.begin(), arr.end());      // Space Complexity: O(1)
    for(int i=0; i<n; i++){
        if(arr[i]==arr[i+1]){
            return arr[i];
        }
    }
    return -1;
}
int optimal(vector<int>& nums){
    //Initialize Duplicate                           Time Complexity: O(n)
    int slow=nums[0];                            //  Space Complexity: O(1)
    int fast=nums[2];
    //Move slow by 1 step and fast by 2 step until they meet
    do{
        slow=nums[slow];
        fast=nums[nums[fast]];
    }while(slow!=fast);
    //Reset fast to start to find the entrance to the cycle
    fast=nums[0];
    //Move both by 1 step until they met at duplicate
    while(slow!=fast){
        slow=nums[slow];
        fast=nums[fast];
    }
    return slow;
}
int main(){
    vector<int> num={1,23,22,3,22};
    cout<<bruteForce(num)<<endl;
    cout<<optimal(num);
    return 0;
}
