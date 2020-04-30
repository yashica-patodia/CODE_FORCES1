#include<bits/stdc++.h>
using namespace std;

struct node
{
	int x;
	int y;
	int dis;
};
int bfs(int mat[10][11],node src,node dest);

  int pred[10][11];

int main()
{
	int mat[10][11]= { 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 }, 
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 }, 
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, 
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 }, 
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 } 
    }; 
   node src,dest;
    src.x=0;
   src.y=0;
   dest.x=3;
   dest.y=4;

    int d=bfs(mat,src,dest,pred);
    cout<<d;


}
int row[]={-1,0,1,0};
int col[]={0,1,0,-1};
int bfs(int mat[10][11],node src,node dest,int pred[][11])
{
	bool vis[10][11];
	memset(vis,false,sizeof(vis));
	memset(pred,-1,sizeof(pred));
	vis[src.x][src.y]=true;
	queue<node>q;
	node s={src.x,src.y,0};
	q.push(s);
	while(!q.empty())
	{
		node curr=q.front();
		if(curr.x==dest.x &&  curr.y==dest.y)
			return curr.dis;
		q.pop();
		for( int i=0;i<4;i++)
		{
			int r=curr.x+row[i];
			int co=curr.y+col[i];
			if(r>=0 && r<9 && co>=0 && co<10 && mat[r][co] && !vis[r][co])
			{
				vis[r][co]=true;
				node adj={r,co,curr.dis+1};
				pred[r][co]=1;
				q.push(adj);
			}
		}
	}
	return -1;

}