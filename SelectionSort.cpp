#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define loop(i,a,b)  for(int i=a;i<=b;i++)
#define logarr(arr,a,b) for(int i=a;i<=b;i++) cout<<arr[i]<<"  " ; cout<<endl;

int find_min(vector<int> &arr,int i)
{
  int min_idx=i;
  while(i<arr.size())
  {
    if(arr[i] < arr[min_idx])
    {
      min_idx=i;
    }
    i++;
  }
  return min_idx;
}
void Selection_Sort(vector<int> &arr)
{
    int n=arr.size();
    loop(i,0,n-1)
    {
      int min_idx=find_min(arr,i);
      if(min_idx!=i)
      {
        swap(arr[min_idx],arr[i]);
      }
    }
}

int main()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  loop(i,0,n-1)
    cin>>arr[i];
  Selection_Sort(arr);
   logarr(arr,0,n-1);

  return 0;
}
