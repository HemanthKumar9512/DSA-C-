/*
Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> approach1(int numRows){    // Time Complexity: O(n^2)
    vector<vector<int>> triangle;             // Space Complexity: O(n^2)
    for(int i=0; i<numRows; i++){
        vector<int> row(i+1, 1);
        for( int j=1; j<i; j++){
            row[j]=triangle[i-1][j-1]+triangle[i-1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}

vector<long long> approach2(int n){                     // Time Complexity: O(n)
    vector<long long> row;                               // Space Complexity: O(n)
    long long val=1;     // First value will be always 1
    row.push_back(val);
    for(int k=1; k<n; k++){
        val=val*(n-k)/k;
        row.push_back(val);
    }
    return row;
}
// Find nCr
long long findPascalElement(int r, int c){
    int n=r-1;
    int k=c-1;
    long long result=1;
    for(int i=0; i<k; i++){
        result*=(n-i);
        result/=(i+1);
    }
    return result;
    /*
    Time Complexity: O(min(c,r−c)), The loop runs for min(c−1,r−c) iterations because binomial coefficients are symmetric.
    Space Complexity: O(1), constant additional space is used.
    */
}


int main(){
    int numRows=7;
    vector<vector<int>> result=approach1(numRows);
    
    for(auto val: result){
        for(auto ans: val)cout<<ans<<" ";
        cout<<endl;
    }
    cout<<endl;

    vector<long long> ans=approach2(numRows);
    for(auto val: ans){
        cout<<val<<" ";
    }
    cout<<endl;
    cout<<findPascalElement(10,5);
    
    return 0;
}