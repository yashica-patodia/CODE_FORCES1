#include<bits/stdc++.h>
using namespace std;
char a[55][55];
int n,m,x;
int q;
char t[500011];
int s[128],al[128];
int dis(int x,int x2,int y,int y2)
{
	return (x-x2)*(x-x2)+(y-y2)*(y-y2);
}
int main()
{
	int i,j,q,u,v;
	cin>>n>>m>>x;
	for(i=0;i<n;i++)
	cin>>a[i];
	int shift=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(a[i][j]=='S')
			{
				shift=1;
				for(u=0;u<n;u++)
				{
					for(v=0;v<m;v++)
					{
						if(dis(i,u,j,v)<=(x*x))
						s[(int)a[u][v]]=1;
					}
				}
			}
		
			else
			al[(int)a[i][j]]=1;
		}
	}
	int f=0;
	int ans=0;
	cin>>q;
	cin>>t;
	for(i=0;i<q;i++)
	{
		//if(isupper(t[i]))
		if(t[i]>='A' && t[i]<='Z')
		{
			if(!shift || !al[(int)t[i]+32])
			f=1;
			ans+=!s[(int)t[i]+32];
		}
		 else if(!al[(int)t[i]])
		f=1;
	}
	if(f)
	ans=-1;
	cout<<ans;
}



