#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int key=5;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
        if(arr[i]==key){
            cout<<"Found at index: "<<i<<endl;
            return i;
        }
    }
    return -1;
}
// Space Complexity: O(1)
// Time Complexity: O(n)