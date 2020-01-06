#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n;
lli *arr;
int main()
{
int i,p=0;

cin>>n;
arr=new lli[n];
lli distinct[n];
for(i=0;i<n;i++)
cin>>arr[i];
sort(arr,arr+n);


int dis=0;
for(i=0;i<n-1;i++)
{

while(arr[i]==arr[i+1])
{
i++;
}
distinct[p++]=arr[i];
}
if(arr[n-1]!=arr[n-2])
distinct[p++]=arr[i];

dis=p;
if(dis==1)
cout<<"YES";
 else if(dis==2)
cout<<"YES";
else if(dis==3)
{
if(2*distinct[1]==(distinct[0]+distinct[2]))
cout<<"YES";
else
cout<<"NO";

}
else if(dis>=4)
cout<<"NO";
}



