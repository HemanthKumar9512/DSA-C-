#include<iostream>
using namespace std;
int factorial(int n){
    if (n==0) return 1;
    int fact=1;
    for (int i=1;i<=n;i++){
        fact=fact*i;
    }
    return fact;
}

int main(){
    int n=4;
    cout<<factorial(n);
    return 0;
}