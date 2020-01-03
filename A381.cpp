#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,c,s=0,d=0,i,max2,n2;
cin>>n;
n2=n;
c=0;
int *arr;
 arr=new int [n];
for(i=0;i<n;i++)
cin>>arr[i];
i=0;
while(c<n2)
{
max2=(arr[i]>=arr[n-1])? i:n-1;
if(c%2==0)
s+=arr[max2];
else
d+=arr[max2];
if(max2==i)
i++;
if(max2==(n-1))
n--;
c++;
}
cout<<s<<" "<<d;
}
