#include<iostream>
using namespace std;
//Two-Pointer Approach
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int st=0;
    int end=n-1;
    while(st<end){
        swap(arr[st],arr[end]);
        st++;
        end--;
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
/*Swap smallest and largest by
swap(smallest,largest);*/

//Time Complexity: O(n)
//Space Complexity: O(1)