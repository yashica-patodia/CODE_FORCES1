#include<bits/stdc++.h>
using namespace std;
int sum(int n);
int main()
{
int n,k;
cin>>n;
int c=0;
int s=n;
while(s>9)
{
k=sum(s);
c++;
s=k;
}
cout<<c;
}
int sum(int n)
{
int s=0;
while(n!=0)
{
s=s+n%10;
n=n/10;
}
return s;
}
