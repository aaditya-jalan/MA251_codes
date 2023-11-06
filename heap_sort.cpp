#include<bits/stdc++.h>
using namespace std;

void heapify(int a[],int n,int i){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if((left<n)&&(a[left]>a[largest])){
        largest=left;
    }
    if((right<n)&&(a[right]>a[largest])){
        largest=right;
    }
    if(largest!=i){
        int temp;
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }


}
void build_heap(int a[],int n){
for(int i=n/2-1;i>=0;i--){
    heapify(a,n,i);
}

}
void heap_sort(int a[],int n){
build_heap(a,n);
int temp;
for(int i=n-1;i>0;i--){
    temp=a[0];
    a[0]=a[i];
    a[i]=temp;
    heapify(a,i,0);
}
}
int main(){
    int arr[5];
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    heap_sort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
