#include<bits/stdc++.h>
using namespace std;
int main()
{
int t,i;
cin>>t;
int *arr;
arr=new int[t];
for(i=0;i<t;i++)
cin>>arr[i];
for(i=0;i<t;i++)
{
double d=360.0/(180.0-arr[i]);
if(d-(int)d==0)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;
}
}
