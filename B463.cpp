#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i;
cin>>n;
int *arr;
arr=new int[n];
for(i=0;i<n;i++)
cin>>arr[i];
int s=0,c=0;
for(i=0;i<n-1;i++)
{
if(s<=(arr[i+1]-arr[i]) && arr[i]<arr[i+1])
{
c+=arr[i+1]-arr[i]-s;
s=0;

}
else
s+=arr[i]-arr[i+1];
}
c+=arr[0];
cout<<c;
}






