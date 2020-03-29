#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

vector<lli >adj[3010];
queue<pair<int,int>>q;
lli dis[3010][3010],path[3010][3010];
bool vis[3010][3010];
map<pair<int,int>,set<int>>super;
void find(int u,int v);

int main()
{
	int n,m,k,i,j;
	int x,y;
	cin>>n>>m>>k;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);

	}
	int a,b,c;
	for(i=0;i<k;i++)
	{
		cin>>a>>b>>c;
		super[{a,b}].insert(c);
	
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
			dis[i][j]=INT_MAX;

	}
	int u,v;
	q.push({0,1});
	dis[0][1]=0;
	while(!q.empty())
	{
		u=q.front().first;
		v=q.front().second;
		vis[u][v]=true;
		for(auto ii:adj[v])
		{
			if(!vis[v][ii] && !super[{u,v}].count(ii))
			{
				dis[v][ii]=dis[u][v]+1;
				path[v][ii]=u;
				vis[v][ii]=true;
				q.push({v,ii});
			}
		}
		q.pop();

	}
	v=n;
	int mind=INT_MAX;
	for(i=1;i<=n;i++)
	{
		if(dis[i][n]<mind)
		{
			mind=dis[i][n];
			u=i;
		}
	}
	if(mind<INT_MAX)
	{
		cout<<mind<<endl;
		find(u,v);
	}
	else
		cout<<-1;
}
void find(int u,int v)
{
	if(v>1)
		find(path[u][v],u);
	cout<<v<<" ";
}