#include<iostream>
using namespace std;
// Compute X^n:
/*
n -> logn(2)+1     (2)-base
n=8    log8+1= 3+1= 4(digits)  1000=8

3^5 = 3^4*3^2*3^1 = 1 0 1 = 3^4*3^1 = 3^5
Time Complexity: O(log n)
*/
int exponentiation(int x, int n){
    int binForm=n, ans=1;
    while(binForm>0){
        if(binForm%2==1){ans=ans*x;}
        x*=x;
        binForm/=2;
    }
// x^-n = 3^-5 = (1/3)^5            //n==0 return 1
    if(n<0){                        // x==1 return 1
        x=1/x;                      // x==0 return 0
        binForm=-binForm;           // x==-1 && n%2==0 return 1
    }                                // x==-1 && n%2!=0 return -1
    return ans;                       
}                              
int main(){
    int x=3;
    int n=5;
    cout<<exponentiation(x,n);
    return 0;
}