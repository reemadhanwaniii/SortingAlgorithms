#include<bits/stdc++.h>
using namespace std;
#define logarr(arr,a,b) for(int i=a;i<=b;i++) cout<<arr[i]<<"  "; cout<<endl;

void BubbleSort(vector<int> &arr)
{
  int n=arr.size();
  for(int i=0;i<n-1;i++)
  {
    bool is_sorted=false;
    for(int j=0;j<n-i-1;j++)
    {
      if(arr[j] > arr[j+1])
       {
         swap(arr[j],arr[j+1]);
         is_sorted=true;
       }
    }
    if(!is_sorted)
      break;
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
  BubbleSort(arr);
  logarr(arr,0,n-1);
  return 0;
}
