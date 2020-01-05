#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{
int n,k,i,j=0;
cin>>n>>k;
string s;
for(i=97;i<=122,j<k;i++)
{
s+=(char)i;
j++;

}


string str=s.substr(0,j);

n=n-k;
int d=n/k;
int r=n%k;
for(i=1;i<=d;i++)
s+=str;
s+=str.substr(0,r);
cout<<s<<endl;

}
