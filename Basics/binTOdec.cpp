#include<iostream>
using namespace std;
int binTOdec(int binNum){
    int ans=0, pow=1, rem=0;
    while(binNum>0){
        rem=binNum%10;
        ans+=rem*pow;
        binNum/=10;
        pow*=2;
    }
    return ans;
}
int main(){
    int binNum=110;
    cout<<binTOdec(binNum)<<endl;
    for(int i=000;i<=010;i++){
        cout<<binTOdec(i)<<endl;
    }
    return 0;
}