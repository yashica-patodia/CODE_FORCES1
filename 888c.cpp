#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int arr[30]={0};
vector<int> index(30,-1);
	int ans=INT_MAX,i,j;
	for(i=0;i<s.length();i++)
	{
		arr[s[i]-'a']=max(i-index[s[i]-'a'],arr[s[i]-'a']);
		index[s[i]-'a']=i;
		//cout<<s[i]<<" "<<arr[s[i]-'a']<<" ";
		//cout<<index[s[i]-'a']<<endl;
	}
	for(j=0;j<26;j++)
	{
		if(arr[j]!=0)
			arr[j]=max(i-index[j],arr[j]);
			//cout<<arr[j]<<endl;
	}
	for(j=0;j<26;j++)
	{
		if(arr[j])
		{
			ans=min(ans,arr[j]);
		}
	}
	cout<<ans<<endl;
}