#include<iostream>
using namespace std;
int sumOfNumbers(int n){
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}
int main(){
    int n=10;
    cout<<sumOfNumbers(n);
    return 0;
}

//sort(nums.begin(), nums.end());  
 //sort(nums.begin(),nums.end(), greater<int>()) -> Descending Order