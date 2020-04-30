#include<bits/stdc++.h>
using namespace std;
int main()
{

	int mt[1010][1010];
	int n,m;
	int i,j;
	cout<<"hello"<<endl;
	cin>>n>>m;
	cout<<n<<m;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			int f;
			cin>>f;
			mt[i][j]=f;
			cout<<f;

		}
	}
	int dp[1010][1010];
	for(i=0;i<n;i++)
		dp[i][0]=mat[i][0];
	for(j=0;j<m;j++)
		dp[0][j]=mat[0][j];
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			// if(mat[i-1][j-1]>=1 && mat[i-1][j]>=1 && mat[i][j-1]>=1)
			// 	dp[i][j]=2;
			int m1=max(mat[i-1][j-1],mat[i-1][j]);
			int m2=max(mat[i][j-1],m1);
			//)
			// 	dp
			int a=mat[i-1][j-1];
			int b=mat[i-1][j];
			int c=mat[i][j-1];
			if(a==b && b==c)
				dp[i][j]=m2+1;
			else 
				dp[i][j]=m2;

		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	int t;
	int x1,y1,x2,y2;
	cin>>t;
	while(t--)
	{
		cin>>x1>>y1>>x2>>y2;



	}
	#include <cstdio> #include <algorithm> #include <iostream> #include <cstring>using namespace std;const int n = 1e3 + 100;int N, M, Dp[11][11][n][n], T, lg[n];void buildst () {lg[1] = 0;for (int i = 2; I <= 1000;  ++i) Lg[i] = lg[i >> 1] + 1;for (int x = 1; x <= n; ++x) for (int i = 1; I <=, ++i) for (int y = 1; y <= M  ++y) if (y + (1<<i-1) <= m) dp[0][i][x][y] = max (Dp[0][i-1][x][y], dp[0][i-1][x][y+ (1<<i-1)]); for (int i = 1; I <= 10; ++i) for (int x = 1; x <= N, ++x) for (int j = 0; J <=, ++j) for (int y = 1; y <= m; ++y) if (x + (1<<i- 1) <= n) dp[i][j][x][y] = max (Dp[i-1][j][x][y], dp[i-1][j][x+ (1<<i-1)][y]);} int query (int x1, int y1, int x2, int y2) {int lx = lg[x2-x1 + 1], ly = lg[y2-y1 + 1];x2 = x2-(1 << lx) + 1;y 2 = y2-(1 << ly) + 1;return max (max (dp[lx][ly][x1][y1], dp[lx][ly][x1][y2]), Max (Dp[lx][ly][x2][y1], dp[lx][ly] [X2] [Y2]));} int main () {scanf ("%d%d", &n,&AMP;M); for (int i = 1; I <= n; ++i) {for (int j = 1; j <= m; ++j) {int x;scanf ("%d", &x); if (x = = 1) dp[0][0][i ][j] = min (dp[0][0][i-1][j], min (dp[0][0][i][j-1], dp[0][0][i-1][j-1])) + 1;}} BUILDST (); scanf ("%d", &t), while (t--) {int x1, y1, x2, y2;scanf ("%d%d%d%d", &x1, &y1, &x2, &y2); int L = 0, r = min (x2-x1 + 1, y2-y1 + 1), while (L < r) {int mid = L + R + 1 >> 1;if (query (x1 + mid-1, y1 + mi D-1, x2, y2) >= mid) L = mid;else r = mid-1;} cout << l << Endl;} return 0;}

}