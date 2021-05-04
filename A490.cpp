#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i;
cin>>n;
int arr[n];
for(i=0;i<n;i++)
cin>>arr[i];
int arr1[n];
int arr2[n];
int arr3[n];
int c1=0,c2=0,c3=0;
for(i=0;i<n;i++)
{
if(arr[i]==1)
arr1[c1++]=i;
if(arr[i]==2)
arr2[c2++]=i;
if(arr[i]==3)
arr3[c3++]=i;
}
int k=min(c1,c2);
int f=min(k,c3);
cout<<f<<endl;
for(i=1;i<=f;i++)
cout<<arr1[i-1]+1<<" "<<arr2[i-1]+1<<" "<<arr3[i-1]+1<<endl;
}


