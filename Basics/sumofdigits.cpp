#include<iostream>
using namespace std;

int sumofdigits(int n){
    int sum=0;
    while(n>0){
        int digit=n%10;
        sum+=digit;
        n=n/10;
    }
    return sum;
}
int main(){
    int n=134;
    cout<<sumofdigits(n);
    return 0;
}