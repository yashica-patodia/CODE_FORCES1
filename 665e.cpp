#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

typedef struct data
{
	data* bit[2];
	int cnt=0;
}trie;

int n, k, ans=0;
int a[N], pref[N];
trie* head;

void insert(int x)
{
	//int yp
	trie* node = head;
	for(int i=30;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		cout<<curbit<<" ";
		if(node->bit[curbit]==NULL)
		{
			cout<<i<<" "<<"y"<<endl;
			node->bit[curbit]=new trie();
		}
		node=node->bit[curbit];
		node->cnt++;
		cout<<"count"<<node->cnt<<endl;
	}
}

int query(int x)
{
	trie* node = head;
	int ans=0;
	cout<<x<<endl;
	for(int i=30;i>=0;i--)
	{
		int curbit=(x>>i)&1;
		cout<<curbit<<" q"<<endl;
		if((k>>i)&1)
		{
			if(node->bit[curbit^1]!=NULL)
			{
				node=node->bit[curbit^1];
				cout<<"1NN"<<endl;
			}
			else
			{
				cout<<"1null"<<endl;
				return ans;
			}
		}
		else
		{
			if(node->bit[curbit^1]!=NULL)
			{
				ans+=node->bit[curbit^1]->cnt;
				cout<<ans<<" NNNyp"<<i<<endl;
			}
			
			if(node->bit[curbit]!=NULL)
			{
				node=node->bit[curbit];
				cout<<ans<<" Nyp"<<i<<endl;
			}
			else
				return ans;
		}
	}
	ans+=node->cnt;
	cout<<ans<<" "<<"end"<<endl;
	return ans;
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS;
	head = new trie();
	insert(0);
	 cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1]^a[i];
		ans+=query(pref[i]);
		cout<<query(pref[i])<<"imain"<<endl;
		insert(pref[i]);
	}
	cout<<ans;
	return 0;
} 