#include<bits/stdc++.h>
using namespace std;

#define mid(l,r)     (l+(r-l)/2)
#define logarr(arr,a,b) for(int i=a;i<=b;i++) cout<<arr[i]<<"  "; cout<<endl;

void Merge(vector<int> &arr,int start,int End)
{
  int m=mid(start,End);
  int i=start,j=m+1;
  unique_ptr<int[]> result(new int[End-start]);
  int k=0;
  while(i<=m && j<=End)
  {
    if(arr[i] < arr[j])
      result[k++]=arr[i++];
    else
      result[k++]=arr[j++];
  }
  while(i<=m)
  {
    result[k++]=arr[i++];
  }
  while(j<=End)
  {
    result[k++]=arr[j++];
  }
  k=0;
  for(int i=start;i<=End;i++)
  {
    arr[i]=result[k];
    k++;
  }
}
void MergeSort(vector<int> &arr,int start,int End)
{
  if(start>=End)
    return;
  int m=mid(start,End);
  MergeSort(arr,start,m);
  MergeSort(arr,m+1,End);
  Merge(arr,start,End);
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
  MergeSort(arr,0,n-1);
  logarr(arr,0,n-1);
  return 0;
}
