#include<bits/stdc++.h>
using namespace std;
#define logarr(arr,a,b) for(int i=a;i<=b;i++) cout<<arr[i]<<"  "; cout<<endl;

void heapify(vector<int> &arr,int n,int i)
{
  int largest=i;
  int left=2*i+1;
  int right=2*i+2;
  if(left < n && arr[left] > arr[largest])
  {
    largest=left;
  }
  if(right < n && arr[right] > arr[largest])
  {
    largest=right;
  }
  if(largest!=i)
  {
    swap(arr[i],arr[largest]);
    heapify(arr,n,largest);op
  }
}
void HeapSort(vector<int> &arr)
{
  int n=arr.size();
  for(int i=n/2-1;i>=0;i--)
  {
    heapify(arr,n,i);
  }
  for(int i=n-1;i>=0;i--)
  {
    swap(arr[i],arr[0]);
    heapify(arr,i,0);
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
  HeapSort(arr);
  logarr(arr,0,n-1);
  return 0;
}
