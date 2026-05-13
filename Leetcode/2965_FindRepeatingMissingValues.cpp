/*
You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. 
Each integer appears exactly once except a which appears twice and b which is missing. 
The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

Example 1:
Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> findMissAndRepeat(vector<vector<int>>& grid){      // Time Complexity: O(n^2)
    vector<int> ans;
    int n=grid.size();
    unordered_set<int> s;
    int expSum=0, actSum=0;
    int a,b;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            actSum+=grid[i][j];
            if(s.find(grid[i][j])!=s.end()){
                a=grid[i][j];
                ans.push_back(a);
            }s.insert(grid[i][j]);
        }
    }
    expSum=(n*n)*(n*n+1)/2;
    b=expSum-actSum+a;
    ans.push_back(b);
    return ans;
}
int main(){
    vector<vector<int>> grid={{9,1,7},{8,9,2},{3,4,6}};
    vector<int> ans=findMissAndRepeat(grid);
    for(auto val: ans){
        cout<<val<<" ";
    }
    return 0;
}