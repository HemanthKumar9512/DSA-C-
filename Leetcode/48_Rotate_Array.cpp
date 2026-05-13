/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
DO NOT allocate another 2D matrix and do the rotation.

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> rotateClockwise(vector<vector<int>>& matrix){
    int n= matrix.size();                                       // Time Complexity: O(n^2)
    vector<vector<int>> rotated(n, vector<int>(n));             // Space Complexity: O(n^2)
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            rotated[j][n-i-1]=matrix[i][j];
        }
    }
    return rotated;
}

void rotated(vector<vector<int>>& matrix){
    int n = matrix.size();
    for(int i=0; i<n; i++){    // Transpose Matrix
        for(int j=i+1; j<n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main(){                                                    
    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> result=rotateClockwise(matrix);
    for(auto val: result){
        for(auto sol: val){
            cout<<sol<<" ";
        }
        cout<<endl;
    }

    rotated(matrix);
    for(auto val: matrix){
        for(auto res: val){
            cout<<res<<" ";
        }
        cout<<endl;
    }
}