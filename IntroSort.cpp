#include<bits/stdc++.h>
using namespace std;
#define logarr(arr,a,b) for(int i=a;i<=b;i++) cout<<arr[i]<<"  ";cout<<endl;


void InsertionSort(vector<int> &arr)
{
  for(int i=1;i<arr.size();i++)
  {
    int key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j] > key)
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  }
}
int partition(vector<int> &arr,int lo,int hi)
{
  int pivot=hi;
  int m=lo;
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
int middle(int a,int b,int c)
{
  if (a < b && b < c)
        return (b);

    if (a < c && c <= b)
        return (c);

    if (b <= a && a < c)
        return (a);

    if (b < c && c <= a)
        return (c);

    if (c <= a && a < b)
        return (a);

    if (c <= b && b <= a)
        return (b);
}
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
    swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
  }
}
void HeapSort(vector<int> &arr)
{
  int n=arr.size();
  for(int i=n/2-1;i>=0;i--)
     heapify(arr,n,i);
  for(int i=n-1;i>=0;i--)
  {
    swap(arr[0],arr[i]);
    heapify(arr,i,0);
  }
}
void IntroSort(vector<int> &arr,int start,int end,int depth)
{

  int size=end-start;
  if(size<16)
  {
    InsertionSort(arr);
    return;
  }
  if(depth==0)
  {

    HeapSort(arr);
    return ;
  }
  int pivot=middle(start,start+end/2,end);
  swap(arr[pivot],arr[end]);
  int m=partition(arr,start,end);
  IntroSort(arr,start,m-1,depth-1);
  IntroSort(arr,m+1,end,depth-1);
  return;
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
  int depth=2*log(n-1);
  IntroSort(arr,0,n-1,depth);
  logarr(arr,0,n-1);
  return 0;
}
