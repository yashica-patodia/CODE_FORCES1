#include<bits/stdc++.h>
using namespace std;
int main()
{
int i,sum=0;
int arr[4];
for(i=0;i<4;i++)
cin>>arr[i];
string s;
cin>>s;
for(i=0;i<s.length();i++)
{
int k=s[i]-48;
sum+=arr[k-1];
}
cout<<sum;
}

