#include<iostream>
#include<algorithm>
using namespace std;
/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects 
of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
 
Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
*/

/* Brute Force                            Time Complexity: O(nlogn)
int BruteForce(int* nums){
    sort(nums.begin(), nums.end());
}*/


// Optimized                              Time Complexity: O(n) - 2 pass                    
void Optimized(int* nums, int n){
    int count0=0, count1=0, count2=0, idx=0;
    for(int i=0; i<n;i++){
        if(nums[i]==0){
            count0++;
        }
        else if(nums[i]==1){
            count1++;
        }
        else{
            count2++;
        }
    }
    for(int i=0; i<count0; i++){
        nums[idx++]=0;
    }
    for(int i=0; i<count1; i++){
        nums[idx++]=1;
    }
    for(int i=0; i<count2; i++){
        nums[idx++]=2;
    }
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

// Optimal                Time Complexity: O(n) - i pass
void Optimal(int* nums, int n){
    int mid=0, high=n-1, low= 0;
    while(mid<=high){
        if(nums[mid]==0){
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[high], nums[mid]);
            high--;
        }
    }
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int nums[]={2,1,2,1,2,1,0,0,1};
    int n=sizeof(nums)/sizeof(nums[0]);
    Optimized(nums, n);
    Optimal(nums, n);
    return 0;
}
