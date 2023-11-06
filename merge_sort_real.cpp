#include<bits/stdc++.h>
using namespace std;
void merger(int*a,int low,int mid,int high){
int n1=mid-low +1;
int n2=high-mid;
int b[n1];
int c[n2];
for(int i=0;i<n1;i++){
    b[i]=a[low+i];
}
for(int i=0;i<n2;i++){
    c[i]=a[mid+1+i];
}
int i=0;
int j=0;
int k=low;
while(i<n1&&j<n2){
    if(b[i]>c[j]){
        a[k]=c[j];
        j++;
        k++;
    }else{
        a[k]=b[i];
        i++;
        k++;

    }

}
while(i<n1){
        a[k]=b[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=c[j];
        j++;
        k++;
    }
}
void merge_sort(int* a,int low ,int high){
int mid=(low+high)/2;
if(high>low){
merge_sort(a,low,mid);
merge_sort(a,mid+1,high);
merger(a,low,mid,high);}
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

