#include<iostream>
#include<vector>
#include<climits>   // For INT_MIN
using namespace std;
/* 
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/

// Continuous Part of Array == SubArray

// int arr={1,2,3,4,5}

/*
1 12 123 1234 12345
2 23 234 2345
3 34 345
4 45
5 
*/

int subArray(int* arr, int st, int end, int n){
    for (int st=0;st<n;st++){
        for(int end=st; end<n; end++){
            for(int i=st;i<=end;i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<" "<<endl;;
    }cout<<endl;
}

// Maximum SubArray Sum    Time Complexity: O(n^2)
int maxSubArraySum(int* arr,int st, int end, int n){
    int max_sum=INT_MIN;   //INT_MIN
    for(int st=0; st<n; st++){
        int currSum=0;
        for(int end=st; end<n; end++){
            currSum+=arr[end];
            max_sum=max(currSum, max_sum);
        }
    }
    return max_sum;
}

//Dynamic Programming (Kadane's Algorithm)
/*While Calculating crrent sum, if current sum is less than 0 reset it to 0.
 No negative values are presented here.*/
 
 int KadaneAlgorithm(int* arr, int st, int end, int n){   // Time Complexity: O(n)
    int currSum=0, max_sum=INT_MIN;
    for(int i=0;i<n;i++){                 
        currSum+=arr[i];
        max_sum=max(currSum, max_sum);
        if(currSum<0){
            currSum=0;
        }
    }
    return max_sum;
 }

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int st=0, end=n-1;
    subArray(arr,st,end,n);
    cout<<"Brute Force Method: "<<maxSubArraySum(arr,st,end,n)<<endl;
    cout<<"Optimal Approach: "<<KadaneAlgorithm(arr,st,end,n);
    return 0;
}




