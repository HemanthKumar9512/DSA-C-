/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. 
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]],
 target = 20
Output: false
*/

#include<iostream>
#include<vector>
using namespace std;
bool searchIn2D(vector<vector<int>>& matrix, int target){
    int m= matrix.size();
    int n= matrix[0].size();
    
    int r=0, c=n-1;
    while(r<m && c>=0){
        if(target==matrix[r][c]){
            return true;
        }
        else if(target<matrix[r][c]){
            c--;    //O(n)
        }
        else{r++;}    //O(m)
    }
    return false;
}
int main(){        // Time Complexity: O(m+n)
    vector<vector<int>> matrix={{1,4,7,11},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,0}};
    int target=11;
    cout<<searchIn2D(matrix, target);
    return 0;
}