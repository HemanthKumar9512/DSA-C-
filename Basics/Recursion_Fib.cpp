// Time Complexity using Recurrance Relation: Total no. of calls * Work in each call  O(n*k)=O(n)
//Space Complexity: Depth of recurrance tree * Member in each call    O(n*k)=O(n)

#include<iostream>
using namespace std;
int fib(int n){
    if (n<=1){
        return 1;
    }
    return fib(n-1)+fib(n-2);
}
int main(){
    int n=4;
    cout<<fib(4);
    return 0;
}
/*               f(4)            2^0     n=4
               /      \          
              /        \
            f(3)       f(2)      2^1
            /  \      /    \
         f(2)  f(1) f(1)  f(0)   2^2
         /  \    |    |     |
      f(1)  f(0)                 2^3


      [2^0+2^1+2^2+......2^(n-1)]  -> Geomentric Progression

      sum=a(r^n-1)/r-1;   a->starting,  r->common difference,  n->no. of terms

      2(2^n-1)/1=2^n-1
      (2^n-1)*k  ===>    Time Complexity: O(2^n)
      n*1 =====> Space Complexity: O(n)
*/