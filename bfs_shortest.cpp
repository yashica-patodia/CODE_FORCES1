#include<bits/stdc++.h>
using namespace std;

int main()
{
	int V,u,w,i,j,s,f=0;
	int dest,src;
	cin>>V;
	vector<int> adj[V];
	for(i=0;i<4;i++)
	{
		cin>>u>>w;
		adj[u].push_back(w);
		 adj[w].push_back(u);
	}
	queue<int>qu;
	vector<bool>vis(V,false);
	vector<int>dis(V,0);
	vector<int>pred(V,-1);
	cin>>src>>dest;
	qu.push(src);
	// int s;
	vis[src]=true;
	dis[src]=0;
	pred[src]=-1;


	 while(!qu.empty())
	 {
	 	s=qu.front();
	 	// cout<<s<<" ";
	 	qu.pop();
	 	for(auto j:adj[s])
	 	{
	 		if(!vis[j])
	 		{
	 			vis[j]=true;
	 			dis[j]=dis[s]+1;
	 			// cout<<dis[s]<<" "<<dis[j]<<" ";
	 			pred[j]=s;
	 			// cout<<pred[j]<<endl;
	 			qu.push(j);
	 			if(j==dest)
	 			{
	 				f=1;
	 				break;
	 			}
	 		}
	 	}
	 	// for(i=0;i<V;i++)
	 	// {
	 	// 	cout<<pred[i]<<" "<<dis[i]<<endl;
	 	// }


	 }
	 vector<int>path;
	 int back=dest;
	 path.push_back(back);
	 while(pred[back]!=-1)
	 {
	 	path.push_back(pred[back]);
	 	back=pred[back];
	 }
	 for(i=path.size()-1;i>=0;i--)
	 	cout<<path[i]<<" ";

}