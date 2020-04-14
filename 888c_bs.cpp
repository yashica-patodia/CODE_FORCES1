#include <bits/stdc++.h>
 
using namespace std;
 
string s;
map<char, int> freq;
set<char> se;
 
bool check(int k) {
    freq.clear();
    se.clear();
    for (int i = 0; i < k; ++i) {
        se.insert(s[i]);
        freq[s[i]]++;
    }
    for (int i = k; i < (int) s.length(); ++i) {
        freq[s[i - k]]--;
        freq[s[i]]++;
        if (freq[s[i - k]] == 0)se.erase(s[i - k]);
    }
    return (int) se.size() != 0;
}
 
int main() {
    cin >> s;
    int mid, lo = 1, hi = (int) s.length();
    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (check(mid))hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
}

