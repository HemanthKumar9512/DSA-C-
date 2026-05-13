#include<iostream>
#include<vector>
using namespace std;
/*
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/
void reverseString(vector<char> &s){       // Time Complexity: O(n)
    int st=0;
    int end=s.size()-1;
    while(st<end){
        swap(s[st],s[end]);
        st++;
        end--;
    }
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
}
int main(){
    vector<char> s={'h','e','l','l','o'};
    reverseString(s);
    return 0;
}
