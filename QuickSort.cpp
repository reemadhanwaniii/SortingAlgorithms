#include<bits/stdc++.h>
using namespace std;
#define logarr(arr,a,b) for(int i=a;i<=b;i++) cout<<arr[i]<<"  "; cout<<endl;

int partition(vector<int> &arr,int lo,int hi)
{
  int m=lo;
  int pivot=hi;
  for(int i=lo;i<hi;i++)
  {
    if(arr[i] < arr[pivot])
    {
      swap(arr[i],arr[m]);
      m++;
    }
  }
  swap(arr[m],arr[pivot]);
  return m;
}
int random_pivot(vector<int> &arr,int lo,int hi)
{
  int n=rand();
  int pivot=lo+(n%(hi-lo+1));
  swap(arr[hi],arr[pivot]);
  return partition(arr,lo,hi);
}
void QuickSort(vector<int> &arr,int lo,int hi)
{
  if(lo < hi)
  {
    int pivot_idx=random_pivot(arr,lo,hi);
    QuickSort(arr,lo,pivot_idx-1);
    QuickSort(arr,pivot_idx+1,hi);
  }
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
      cin>>arr[i];
    }
    QuickSort(arr,0,n-1);
    logarr(arr,0,n-1);
    return 0;
}
