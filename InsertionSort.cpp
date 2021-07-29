#include<bits/stdc++.h>
using namespace std;
#define logarr(arr,a,b)  for(int i=a;i<=b;i++) cout<<arr[i]<<"  "; cout<<endl;
#define loop(i,a,b)  for(int i=a;i<=b;i++)


void InsertionSort(vector<int> &arr)
{
    for(int i=1;i<arr.size();i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j] >key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    loop(i,0,n-1)
       cin>>arr[i];
    InsertionSort(arr);
    logarr(arr,0,n-1);
    return 0;
}
