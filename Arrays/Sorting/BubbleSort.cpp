#include<iostream>
using namespace std;
// n-1 iterations   -->  comapare Adjacent Element    -->  If larger push to last and swap
/*
arr=4,1,5,2,3
Iter 1:         Iter 2:         Iter 3:         Iter 4:    Iter 5:
4_,1_,5,2,3     1_,4_,2,3,5     .......
1,4_,5_,2,3     1,4_,2_,3,5     .......
1,4,5_,2_,3     1,2,4_,3_,5     .......         Similarly the comparison will go upto n-1 iterations,
1,4,2,5_,3_     1,2,3,4_,5_     .......        even sorted. So that why, we use an optimization here.
1,4,2,3,5       1,2,3,4,5       ........

*/
int bubbleSort(int* arr, int n){       // Time Complexity: O(n^2)
    bool isSwap;
    for(int i=0;i<n-1;i++){
        isSwap=false;
        for(int j=0;j<n;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }if(!isSwap){    // If the array is already swapped, then no need to run for n-1 iterations.
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={1,4,3,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,n);
    return 0;
}