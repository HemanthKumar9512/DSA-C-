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
int main() {
    int a=3;
    fun(a);
    return 0;
}