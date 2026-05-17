#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<string> S(n);
    set<vector<string>> SS;
    for (ll i=0;i<n;i++) {
            for (ll j = 0; j<n;j++) {
                char s;
                cin >> s;
                S[i] += s;
            }
    }

    for (ll i = 0 ; i < n-m+1;i++) {
        for (ll j = 0; j < n-m+1;j++) {
            vector<string> ss(m);
            for (ll k = 0; k < m; k++) {
                ss[k] = S[i+k].substr(j,m);
            }
            SS.insert(ss);
        }
    }
            cout << SS.size() << "\n";
}
