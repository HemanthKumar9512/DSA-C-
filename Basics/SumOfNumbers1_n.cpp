<<<<<<< HEAD
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
=======
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
>>>>>>> 7d119c5dc7759d842d5b4ad458c4c6beb9323297
 //sort(nums.begin(),nums.end(), greater<int>()) -> Descending Order