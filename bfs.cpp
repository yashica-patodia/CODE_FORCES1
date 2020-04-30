#include<bits/stdc++.h>
using namespace std;

int main()
{
	int V,u,w,i,j,s,q;
	cin>>V;
	vector<int> adj[V];
	for(i=0;i<6;i++)
	{
		cin>>u>>w;
		adj[u].push_back(w);
		// adj[w].push_back(u);
	}
	queue<int>qu;
	vector<bool>vis(V,false);
	qu.push(0);
	// int s;
	vis[0]=true;

	 while(!qu.empty())
	 {
	 	s=qu.front();
	 	cout<<s<<" ";
	 	qu.pop();
	 	for(auto j:adj[s])
	 	{
	 		if(!vis[j])
	 		{
	 			vis[j]=true;
	 			qu.push(j);
	 		}
	 	}

	 }
}