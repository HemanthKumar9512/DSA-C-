/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> merge(vector<vector<int>>& intervals){
    int n=intervals.size();                                 // Time Complexity: O(n^2)
    sort(intervals.begin(), intervals.end());              // Space Complexity: O(n)
    vector<vector<int>> ans;
    for(int i=0; i<n;){
        int start=intervals[i][0];
        int end=intervals[i][1];
        int j=i+1;              // Merge with overlapping intervals
        while(j<n && intervals[j][0]<=end){
            end=max(end, intervals[j][1]);
            j++;
        }
        ans.push_back({start, end});
        i = j;
    }
    return ans;
}

vector<vector<int>> optimal(vector<vector<int>>& intervals){
    sort(intervals.begin(), intervals.end());               // Time Complexity: O(N*logN) + O(N)
    vector<vector<int>> merged;                            // Space Complexity: O(n)
    for(auto interval: intervals){
        // If merged is empty or current interval does not overlap
        if(merged.empty() || merged.back()[1]<interval[0]){
            // Add current element as new non-overlappind
            merged.push_back(interval);
        }
        else{
            // Overlapping: Merge by extending end time
            merged.back()[1]=max(interval[1], merged.back()[1]);
        }
    }
    return merged;
}
int main(){
    vector<vector<int>> intervals={{1,2},{3,6},{7,11},{6,8}};
    vector<vector<int>> result=merge(intervals);
    for(auto interval: result){
        cout <<"[" << interval[0] <<","<< interval[1] <<"]";
    }
    cout<<endl;
    vector<vector<int>> ans=optimal(intervals);
    for(auto val: ans){
        cout<< "[" << val[0] << "," << val[1] <<"]";
    }
    return 0;
}