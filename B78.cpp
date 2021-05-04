#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,i;
cin>>n;
string str="ROYGBIV";
string s;
int d=n/7;
int r=n%7;
for(i=0;i<d;i++)
s+=str;
if(r<=2)
s+= str.substr(3,r);
if(r>2 &&  r<=4)
s+=str.substr(2,r);
if(r>4 && r<=6)
s+=str.substr(1,r);
cout<<s;
}
