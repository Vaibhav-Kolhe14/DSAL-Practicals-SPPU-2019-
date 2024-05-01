#include<bits/stdc++.h>
using namespace std;

//to heapify a subtree rooted with node i which is 
//an index in arr[], n is size of heap

void heapify(int arr[],int n,int i){
    int largest = i;   //initialize largest as root
    int l = 2*i+1;    
    int r = 2*i+2;

    //if left child is larger than root
    if(l < n && arr[l] > arr[largest]){
        largest = l;
    }

    //if right child is larger than largest so far
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }

    //if largest is  not root
    if(largest != i){
        swap(arr[i],arr[largest]);
        
        //recursively heapify tha affected sub-tree
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    //Build heap (rearrange array)
    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    
    //one by one extract an element from heap
    for(int i=n-1;i>=0;i--){
        //move current root to end
        swap(arr[0],arr[i]);

        //call max heapify on the reduced heap
        heapify(arr,i,0);

    }

    cout<<"Maximum marks obtained in the subject = "<<arr[n-1]<<endl;
    cout<<"Minimum marks obtained in the subject = "<<arr[0]<<endl;
}


int main(){
    
    int n ;
    cout<<"Enter the length of array :";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    heapSort(arr,n);
    
    cout<<"Sorted array is :"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    return 0;
}