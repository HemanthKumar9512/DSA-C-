#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int lar=0;
    int small=9999;
    for(int i=0;i<n;i++){
        if(arr[i]<small){
            small=arr[i];
        }
        if(arr[i]>lar){
            lar=arr[i];
        }
    }
    cout<<"Largest Element: "<<lar<<endl;
    cout<<"Smallest Element: "<<small<<endl;

    for(int i=0;i<n;i++){
        int smallest=min(arr[i],small);
        int largest=max(arr[i],lar);
    }
    return 0;
}