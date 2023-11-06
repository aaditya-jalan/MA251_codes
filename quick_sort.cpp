#include<bits/stdc++.h>
using namespace std;
int  partion(int* a,int low,int high){
int pivot=a[low];
int i=low;
int j=high;
while(i<j){

    do{
    i++;}while(a[i]<=pivot);

    do{j--;
    }while(a[j]>pivot);

    if(i<j){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}
a[low]=a[j];
a[j]=pivot;
return j;

}
void quick_sort(int* a,int low,int high){
    if(low<high){
int parti=partion(a,low,high);
quick_sort(a,low,parti);
quick_sort(a,parti+1,high);
}}
int main(){
    int n;
    cin>>n;
    int arr[n+1];
    arr[n]=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
