#include<bits/stdc++.h>
using namespace std;
int  main()
{
int n1,n2;
cin>>n1>>n2;
int max2=(n1>=n2)? n1:n2;
int k=7-max2;
if(k%2==0 && k%3!=0)
{
k/=2;
cout<<k<<"/"<<"3";
}
 else if(k%3==0 && k%2!=0)
{
k/=3;
cout<<k<<"/"<<"2";
}
else if(k%6==0)
{
k/=6;
cout<<k<<"/"<<"1";
}
else
cout<<k<<"/"<<"6";
}


