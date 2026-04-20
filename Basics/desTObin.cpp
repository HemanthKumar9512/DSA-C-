#include<iostream>
using namespace std;
int decTObin(int decNum){
    int rem=0, ans=0, pow=1;
    while(decNum>0){
        rem=decNum%2;
        decNum/=2;
        ans+=rem*pow;
        pow=pow*10;
    }
    return ans;
}
int main(){
    int decNum=5;
    cout<<decTObin(decNum)<<endl;
    for(int i=0;i<=10;i++){
        cout<<decTObin(i)<<endl;
    }
    return 0;
}
