#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
getline(cin>>ws,s);
int l=s.length();
int c=1,f=0;
string s1("ABC");
while(c<=6)
{
c++;
int k=s.find(s1);

if(k!=-1)
{
f=1;
break;
}
if(c%2==0)
swap(s1[0],s1[1]);
else
swap(s1[1],s1[2]);

}
if(f==1)
cout<<"Yes";
else
cout<<"No";
}
