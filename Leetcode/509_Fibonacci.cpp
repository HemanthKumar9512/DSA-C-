/*
Find the fibonnaci value of the given n-th term.
*/


#include<iostream>
#include<vector>
using namespace std;

int fib(int n){
    if(n==0||n==1){
        return n;
    }
    return fib(n-1)+fib(n-2);      // Time Complexity: O(2^n)
}                                  // Space Complexity: O(n)
int main(){
    int n=30;
    cout<<fib(n);
    return 0;
}