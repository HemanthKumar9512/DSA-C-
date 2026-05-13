/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& matrix){
    if(matrix.empty()) return {};
    int m=matrix.size(), n=matrix[0].size();
    int srow=0, scol=0, erow=m-1, ecol=n-1;
    vector<int> ans;
    while(srow<=erow && scol<=ecol){
        // Top row
        for(int j=scol; j<=ecol; j++){
            ans.push_back(matrix[srow][j]);
        }
        // Right Last Column
        for(int i=srow+1; i<=erow; i++){
            ans.push_back(matrix[i][ecol]);
        }
        // Bottom Row
        for(int j=ecol-1; j>=scol; j--){
            if(srow==erow) break;
            ans.push_back(matrix[erow][j]);
        }
        // Left Column
        for(int i=erow-1; i>=srow+1; i--){
            if(scol==ecol) break;
            ans.push_back(matrix[i][scol]);
        }
        srow++; erow--; scol++; ecol--;
    }
    return ans;
}
int main(){      // Time Complexity: O(m*n)
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans=spiralMatrix(matrix);
    for( int x: ans){
        cout<<x<<" ";
    }
    return 0;
}