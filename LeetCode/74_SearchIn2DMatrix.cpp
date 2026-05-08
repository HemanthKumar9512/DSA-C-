/*
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
*/

#include<iostream>
#include<vector>
using namespace std;

bool searchInRow(vector<vector<int>>& matrix, int target, int row){
    int n=matrix[0].size();
    int st=0, end=n-1;
    while(st<=end){                  // O(log n)
        int mid=st+(end-st)/2;
        if(target==matrix[row][mid]){
            return true;
        }
        else if(target<matrix[row][mid]){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>>& matrix, int target){
    int m=matrix.size();
    if (m==0) return false;
    int n=matrix[0].size();

    int stRow=0, endRow=m-1;
    while(stRow<=endRow){             // O(log m)
        int midRow=stRow+(endRow-stRow)/2;
        if(target>=matrix[midRow][0] && target<=matrix[midRow][n-1]){
            return searchInRow(matrix, target, midRow);
        }
        else if(target>matrix[midRow][n-1]){
            stRow=midRow+1;
        }
        else{
            endRow=midRow-1;
        }
    }
    return false;
}
int main(){         //  Time Complexity: O( log m + log n) = O(log(m*n))
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    int target=40;
    cout<<searchMatrix(matrix, target);
    return 0;
}
