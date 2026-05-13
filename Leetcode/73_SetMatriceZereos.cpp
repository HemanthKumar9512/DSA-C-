#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     // Brute Force 
    void bruteForce(vector<vector<int>>& matrix) {            
        // Get number of rows
        int m = matrix.size();
        // Get number of columns
        int n = matrix[0].size();

        // Traverse each cell of the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If current cell is zero
                if (matrix[i][j] == 0) {
                    // Mark all elements in this row as -1 (except existing zeros)
                    for (int col = 0; col < n; col++) {
                        if (matrix[i][col] != 0)
                            matrix[i][col] = -1;
                    }
                    // Mark all elements in this column as -1 (except existing zeros)
                    for (int row = 0; row < m; row++) {
                        if (matrix[row][j] != 0)
                            matrix[row][j] = -1;
                    }
                }
            }
        }

        // Second pass: replace all -1 markers with 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }
    // Brute Force: O(M*N * (M+N)) Time | O(1) Space
    /*
    Time Complexity: O(m * n * (m + n)), We iterate through every cell (m * n), and for each zero,
     we potentially mark its entire row (O(n)) and column (O(m)), leading to O(m * n * (m + n)) overall.
    Space Complexity: O(1), We are not using any extra data structures, only modifying the matrix in 
    place (apart from a few variables).
    */

    // Better Approach
    void betterApproach(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    row[i]=-1;
                    col[j]=-1;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(row[i]==-1 || col[j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
    }
    // Better Approach: O(M*N) Time | O(M+N) Space
    /*
    Time Complexity: O(m × n),We make two passes over the matrix.First pass to identify rows and columns 
    to be zeroed (O(m × n)).Second pass to update the matrix using the markers (O(m × n)).
    Total time is proportional to the number of cells in the matrix, so O(m × n).
    Space Complexity: O(m + n),We store two extra arrays one for m rows and one for n columns. 
    No other extra space is used besides these arrays.
    */

    // Optimal Solution
    void optimalSolution(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();

        // Flag to be tracked for First Row and Column to be Zeroed
        bool firstRowZero = false;
        bool firstColumnZero = false;

        // Check if first row has any zeros
        for(int j=0; j<n; j++){
            if(matrix[0][j]==0){
                firstRowZero = true;
                break;
            }
        }

        // Check if first column has any zeros
        for(int i=0; i<m; i++){
            if(matrix[i][0]==0){
                firstColumnZero = true;
                break;
            }
        }

        // Mark rows and columns in first row/column
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        // Set Matrix cells to zero on markers
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        // Handle First Row
        if(firstRowZero){
            for(int j=0; j<n; j++){
                matrix[0][j]=0;
            }
        }
        // Handle First Column
        if(firstColumnZero){
            for(int i=0; i<m; i++){
                matrix[i][0]=0;
            }
        }
    }
    // Optimal Solution: O(M*N) Time | O(1) Space
    /*
    Time Complexity: O(m × n),We iterate over the entire matrix a constant number of times 
    (first pass for markers, second pass for zeroing, final pass for first row/col), 
    where m = number of rows and n = number of columns.
    Space Complexity: O(1),No extra space is used apart from a few boolean flags; 
    all marker information is stored within the first row and column of the matrix itself.
    */
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    
    // Create Solution object
    Solution sol;
    
    // Call function to modify matrix only one at a time
    // sol.bruteForce(matrix);
    // sol.betterApproach(matrix);   
     sol.optimalSolution(matrix);
    
    // Print final matrix
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}