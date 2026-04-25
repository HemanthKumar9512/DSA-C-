#include<iostream>
using namespace std;
//  n-1 iterations --> n-1 smaller

/*
arr={4,1,5,2,3}

41523       1 4523     12  543      123  45   12345    
  US        S   US      S   US        S   US    S       
*/
int selectionSort(int* arr, int n){    // Time Complexity: O(n^2)
    for(int i=0;i<n-1;i++){
        int smallest_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[smallest_idx]){
                smallest_idx=j;
            }
        }
        swap(arr[i],arr[smallest_idx]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={1,4,3,5,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    return 0;
}