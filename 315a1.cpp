#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y;
	cin>>n;
	int i,count=0;
	vector<int>a;
	vector<int>b;
	int c[1010]={0};
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		a.push_back(x);
		b.push_back(y);
		

		c[y]+=1;
	}
	for(i=0;i<n;i++)
	{
		c[b[i]]--;
		if(c[a[i]]==0)
		// 	continue;
		// else
			count++;
		c[b[i]]++;
	}
	cout<<count;
}