#include<bits/stdc++.h>
using namespace std;
void count_sort(int* a,int n){
int c[n]={0};
for(int i=0;i<n;i++){
    c[a[i]]++;
}
int b[n];
for(int i=1;i<n;i++){
    c[i]+=c[i-1];
}
for(int i=n-1;i>=0;i--){

    b[--c[a[i]]]=a[i];
}
for(int i=0;i<n;i++){
    a[i]=b[i];
}
}
int main(){
int arr[10];
for(int i=0;i<10;i++){
    cin>>arr[i];
}
count_sort(arr,10);
for(int i=0;i<10;i++){
    cout<<arr[i]<<" ";
}cout<<endl;
}
