#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define loop(a,b) for(int i=a;i<=b;i++)
#define logarr(arr,a,b) for(int i=a;i<=b;i++) cout<<arr[i]<<" ";
#define mid(l,r) (l+(r-l)/2)


int find_min_element(vector<int> arr, int i, int n) {
    int min_idx = i;
    while(i<n) {
        if(arr[i] < arr[min_idx]) min_idx = i;
        i++;
    }
    return min_idx;
}

void selection_sort(vector<int>&arr, int n) {
    int min_idx;
    for(int i=0;i<n;i++) {
        min_idx = find_min_element(arr,i,n);
        if(min_idx != i) {
            swap(arr[min_idx],arr[i]);
        }
    }
}

void insertion_sort(vector<int> &arr,int n) {
    for(int i=1;i<n;i++) {
        for(int j=i;j>0;j--) {
            if(arr[j] < arr[j-1]) {
                swap(arr[j],arr[j-1]);
            }
        }
    }
}

void bubble_sort(vector<int> &arr,int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<(n-i-1);j++) {
            if(arr[j] > arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

int partition_array(vector<int> &arr,int lo,int hi) {
    int m=lo;
    for(int i=lo;i<hi;i++) {
        if(arr[i] < arr[hi]) {
            swap(arr[i],arr[m]);
            m++;
        }
    }
    swap(arr[m],arr[hi]);
    return m;
}

int random_pivot(vector<int> &arr,int lo,int hi) {
    int n = rand();
    int offset = lo+(n%(hi-lo+1));
    swap(arr[hi],arr[offset]);
    return partition_array(arr,lo,hi);
}

void quick_sort(vector<int> &arr,int lo,int hi) {
    if(lo < hi) {
        int pivot = random_pivot(arr,lo,hi);
        quick_sort(arr,lo,pivot-1);
        quick_sort(arr,pivot+1,hi);
    }
}

void merge(vector<int> &arr,int start,int end) {
    int m = mid(start,end);
    int i=start,j=m+1;
    unique_ptr<int[]> result(new int[end-start+1]);
    int k=0;
    while(i<=m && j<=end) {
        if(arr[i] < arr[j]) {
            result[k++] = arr[i++];
        } else{
            result[k++] = arr[j++];
        }
    }
    while(i<=m) {
        result[k++] = arr[i++]; 
    }
    while(j<=end) {
        result[k++] = arr[j++];
    }
    
    k=0;
    for(int i=start;i<=end;i++) {
        arr[i] = result[k++];
    }
    
}

void merge_sort(vector<int> &arr, int start, int end) {
    if(start>=end) return;
    int m = mid(start,end);
    merge_sort(arr,start,m);
    merge_sort(arr,m+1,end);
    merge(arr,start,end);
}

void counting_sort(vector<int> &arr) {
    int val = *max_element(arr.begin(),arr.end());
    vector<int> freq(val+1,0);
    for(int i=0;i<arr.size();i++) {
        freq[arr[i]]++;
    }
    for(int i=1;i<=val;i++) {
        freq[i] = freq[i]+freq[i-1];
    }
    vector<int> output(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        output[freq[arr[i]]-1] = arr[i];
        freq[arr[i]]--;
    }
    arr=output;
}


int main() {
    vector<int> arr = {12,53,47,21,90,34,1,2,3,-1,-19,-178,199,100,10,-7};
    int n = arr.size();
    merge_sort(arr,0,n-1);
    logarr(arr,0,n-1);
    vector<int> arr1 = {7,6,5,4,3,2,1,7,6,4,4,4,3,3,3,2,1,0};
    counting_sort(arr1);
    cout<<endl;
    logarr(arr1,0,arr1.size()-1);
}
