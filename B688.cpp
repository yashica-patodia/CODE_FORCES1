#include<bits/stdc++.h>
using namespace std;
int main()
{
string n;
cin>>n;
string str;
str=n;
reverse(n.begin(),n.end());
str+=n;
cout<<str;
}
