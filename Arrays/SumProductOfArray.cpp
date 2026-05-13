<<<<<<< HEAD
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    int product=1;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        product*=arr[i];
    }
    cout<<sum<<" "<<product<<endl;
    return 0;
}
=======
#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    int product=1;  
    for(int i=0;i<n;i++){
        sum+=arr[i];
        product*=arr[i];
    }
    cout<<sum<<" "<<product<<endl;
    return 0;
}
>>>>>>> 7d119c5dc7759d842d5b4ad458c4c6beb9323297
