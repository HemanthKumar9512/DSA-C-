// Sorting based on cards
#include<iostream>
using namespace std;

/*
arr={4,1,,5,2,3}
4  1 5 2 3  => curr=1, prev=4
S

1 4  5 2 3  => curr=5, prev=4
 S     US

1 4 5  2 3  => curr=2, prev=5
  S     US

1 4 _ 5 3   => curr=2, prev=4
1 2 4 5  3  => curr=3, prev=5
    S    US 

1 2 4 _ 5   => curr=3, prev=4
1 2 3 4 5
*/

int InsertionSort(int* arr, int n){             // Time Complexity: O(n^2)
    for(int i=1;i<n;i++){
        int curr=arr[i], prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[]={3,2,1,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    InsertionSort(arr, n);
    return 0;
}