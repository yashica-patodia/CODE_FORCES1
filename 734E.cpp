#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// still can't understand the meaning of dfs2
int n;
vector <int> color;
vector < vector <int> > g;
vector <char> used;
vector <int> comp;
int n1;
vector < vector <int> > g1;
vector <int> dp;
int ans = 0;

void dfs1(int v, int col, int cmp)
{
    if (used[v]) return;
    if (color[v] != col) return;
    used[v] = true;
    comp[v] = cmp;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        dfs1(to, col, cmp);
    }
}

void dfs2(int v, int p = -1)
{
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < g1[v].size(); i++)
    {
        int to = g1[v][i];
        if (to == p) continue;
        dfs2(to, v);
        int val = dp[to] + 1;
        mx2 = max(mx2, val);
        if (mx1 < mx2) swap(mx1, mx2);
    }
    dp[v] = mx1;
    ans = max(ans, mx1 + mx2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    color.resize(n);
    g.resize(n);
    comp.resize(n);
    used.assign(n, false);
    for (int i = 0; i < n; i++) cin >> color[i];
    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b; a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs1(i, color[i], n1++);
    g1.resize(n1);
    dp.resize(n1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < g[i].size(); j++)
        {
            int to = g[i][j];
            cout<<to<<" ";
            cout<<comp[i]<<" "<<comp[to]<<endl;
            if (comp[i] != comp[to])
                g1[comp[i]].push_back(comp[to]);
        }
    dfs2(0);
    cout << (ans + 1) / 2 << endl;
    return 0;
}