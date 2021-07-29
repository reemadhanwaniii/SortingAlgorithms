#include<bits/stdc++.h>
using namespace std;
#define logarr(arr,a,b) for(int i=0;i<n;i++) cout<<arr[i]<<"  "; cout<<endl;

void CountingSort(vector<int> &arr)
{
  int val=*max_element(arr.begin(),arr.end());
  vector<int> freq(val+1,0);
  for(int i=0;i<arr.size();i++)
  {
    freq[arr[i]]++;
  }
  for(int i=1;i<freq.size();i++)
  {
    freq[i]=freq[i]+freq[i-1];
  }
  vector<int> output(arr.size());
  for(int i=arr.size()-1;i>=0;i--)
  {
    output[freq[arr[i]]-1]=arr[i];
    freq[arr[i]]--;
  }
  arr=output;
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
  CountingSort(arr);
  logarr(arr,0,n-1);
  return 0;
}
