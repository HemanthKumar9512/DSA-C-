#include <iostream>
#include<cmath>
using namespace std;
void fun(int x){
    int count=0;
    for(int i=2;i<sqrt(x);i++){
        if(x%i==0){
            count++;
        }
    }
    if (count>1){
        cout<<"Not Prime"<<endl;
    }
    else{
        cout<<"Prime"<<endl;
    }
}

bool isPrime(int n){
    for(int i=2;i<sqrt(n);i++){
        if((n%i)==0){
            return false;
        }
    }
    return true;
}
int main() {
    int a=63;
    fun(a);
    cout<<isPrime(a);
    return 0;
}


