<<<<<<< HEAD
#include<iostream>
using namespace std;
int factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=1;
    }
    return fact;
}

int ncr(int n, int r){
    int fact_n=factorial(n);
    int fact_r=factorial(r);
    int fact_nmr=factorial(n-r);
    return fact_n/(fact_r*fact_nmr);
}
int main(){
    int n=4;
    int r=4;
    cout<<ncr(n,r);
    return 0;
=======
#include<iostream>
using namespace std;
int factorial(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=1;
    }
    return fact;
}

int ncr(int n, int r){
    int fact_n=factorial(n);
    int fact_r=factorial(r);
    int fact_nmr=factorial(n-r);
    return fact_n/(fact_r*fact_nmr);
}
int main(){
    int n=4;
    int r=4;
    cout<<ncr(n,r);
    return 0;
>>>>>>> 7d119c5dc7759d842d5b4ad458c4c6beb9323297
}