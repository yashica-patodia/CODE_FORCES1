#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define LD long double

const int N = 100010;

int inf = 1e9;
int mod = 1e9 + 7;

signed main()
{
    //freopen("IN", "r", stdin);
    //freopen("OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _; cin >> _;
    while(_--) {
        int n, G, L;
        cin >> n >> G >> L;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        if (L % G != 0) {
            cout << "-1\n";
            continue;
        }

        if(n == 1) {
            if(L != G) cout << "-1\n";
            else if(a[0] != L) cout << "1\n";
            else cout << "0\n";
            continue;
        }

        int prefG[n], sufG[n], prefL[n], sufL[n];
        for (int i = 0; i < n; i++) {
            if (!i) {
                prefG[i] = a[i];
                prefL[i] = a[i];
            } else {
                prefG[i] = __gcd(prefG[i - 1], a[i]);
                prefL[i] = a[i] / __gcd(a[i], prefL[i - 1]) * prefL[i - 1];
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                sufG[i] = a[i];
                sufL[i] = a[i];
            } else {
                sufG[i] = __gcd(sufG[i + 1], a[i]);
                sufL[i] = a[i] / __gcd(a[i], sufL[i + 1]) * sufL[i + 1];
            }
        }

        vector<int> invalid;

        for (int i = 0; i < n; i++) {
            if (a[i] > L) invalid.push_back(i);
            else if (a[i] % G != 0) invalid.push_back(i);
            else if (L % a[i] != 0) invalid.push_back(i);
        }

        if ((int) invalid.size() > 1) {
            cout << (int) invalid.size() << "\n";
        } else if (invalid.empty()) {
            if (prefG[n - 1] == G && prefL[n - 1] == L) {
                cout << "0\n";
            } else {
                bool key = false;
                for (int i = 0; i < n; i++) {
                    int g = 0;
                    if (i) g = prefG[i - 1];
                    if (i + 1 < n) g = __gcd(g, sufG[i + 1]);
                    int l = 1;
                    if (i) l = prefL[i - 1];
                    if (i + 1 < n) l = l / __gcd(l, sufL[i + 1]) * sufL[i + 1];
                    if (__gcd(g / G, L / l) == 1) {
                        key = true;
                        break;
                    }
                }

                if (key) cout << "1\n";
                else cout << "2\n";
            }
        } else {
            int i = invalid[0];
            int g = 0;
            if (i) g = prefG[i - 1];
            if (i + 1 < n) g = __gcd(g, sufG[i + 1]);
            int l = 1;
            if (i) l = prefL[i - 1];
            if (i + 1 < n) l = l / __gcd(l, sufL[i + 1]) * sufL[i + 1];
            if (__gcd(g / G, L / l) == 1) cout << "1\n";
            else cout << "2\n";
        }
    }
    return 0;
}