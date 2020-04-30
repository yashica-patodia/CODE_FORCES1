#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fr(i, n) for(int i=0;i<n;i++)
#define frr(i, n) for(int i=n;i>=0;i--)
#define fra(i, a, n) for(int i=a;i<n;i++)
#define frra(i, a, n) for(int i=a;i>=n;i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define ff first
#define ss second
#define endl '\n'

typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef set<int> si;
typedef unordered_map<int, int> uii;
typedef unordered_set<int> usi;
typedef vector<int> vi;

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

void solve() {
    //CODE BEGINS
    int n;
    cin >> n;
    vi a(n);
    mii freq;
    usi s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
        s.insert(a[i]);
    }
    vector<pii> b;
    for (auto i:freq)b.eb(i.ss, i.ff);
    sort(all(b));
    int ans = 1;
    for (int j = (int) b.size() - 1; j >= 0; --j) {
        s.erase(b[j].ss);
        ans = max(ans, max(min((int) s.size(), b[j].ff), min((int) s.size() + 1, b[j].ff - 1)));
        s.insert(b[j].ff);
    }
    if (n == 1)cout << 0 << endl;
    else cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)solve();
    return 0;
}

/*
 * remove endl for interactive
 */