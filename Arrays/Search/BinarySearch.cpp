// Finding a word in a Dictionary, Searching number in contacts, ......
/*
Condition: Array need to be sorted (Monotonic)
Monotonic function which is not decreasing or increasing
*/
#include<iostream>
using namespace std;

int binarySearch(int* arr, int n, int tar){               // Time Complexity: O(logn)
    int st=0, end=n-1;                                    // Space Complexity: O(1)
    while(st<=end){
        int mid=(st+end)/2;                      // To overflow, use mid= start + [(end-start)/2]
        if (tar>arr[mid]){
            st=mid+1;
        }
        else if(tar<arr[mid]){
            end=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=3;
    cout<<binarySearch(arr, n, target)<<endl;
    return 0;
}

