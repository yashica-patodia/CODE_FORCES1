#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<vector<int> >adj;
 vector<bitset<210>>vis;
vector<pair<int,int>>edges;
void dfs(int u);

int main()
{
	int t;
	cin>>t;
	int i,j;
	for(i=1;i<=t;i++)
	{
		adj.clear();
		vis.clear();
		edges.clear();
		int n,m;
		cin>>n>>m;
		adj.resize(n+1);
		vis.resize(n+1);
		vector<int>degree(n+1,0);
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
			degree[u]++;
			degree[v]++;
		}
		int odd=0;
		for(j=1;j<=n;j++)
		{
			if(degree[j]%2)
			{
				adj[0].push_back(j);
				adj[j].push_back(0);
				odd++;
			}
		}
		for(j=0;j<=n;j++)
			dfs(j);
		cout<<n-odd<<endl;
		for(j=0;j<edges.size();j++)
			if(edges[j].first && edges[j].second)
				cout<<edges[j].first<<" "<<edges[j].second<<endl;
	}


}
void dfs(int u)
{
	for(auto v:adj[u])
	{
		if(!vis[u][v])
		{
			vis[u][v]=vis[v][u]=true;
			edges.push_back(pair<int,int>(u,v));
			dfs(v);
		}
	}
}