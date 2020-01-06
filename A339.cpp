#include<bits/stdc++.h>
using namespace std;
int main()
{
string s;
cin>>s;
int arr[51];
int i,k=0;
for(i=0;i<s.length();i+=2)
{
arr[k++]=s[i]-48;
}
sort(arr,arr+k);
for(i=0;i<k-1;i++)
cout<<arr[i]<<"+";
cout<<arr[k-1];
}




