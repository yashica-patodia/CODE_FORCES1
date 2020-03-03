#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,c=0,t,des,dest=0;
	cin>>n;
	priority_queue<int>pq;
	for(i=0;i<n;i++)
	{
		cin>>t>>des;
		pq.push(des);
		dest+=des;
		while(dest>t)
		{
			dest-=pq.top();
			c++;
			pq.pop();

		}


	}
	cout<<c;
}