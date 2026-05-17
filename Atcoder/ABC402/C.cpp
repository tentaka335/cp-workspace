#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n,m;
    cin >> n >> m;
    vector<set<ll>> S(m);
    vector<set<ll>> num(n+1);
    for(ll i = 0;i<m;i++) {
        ll k;
        cin >> k;
        for(ll j = 0;j<k;j++) {
            ll a;
            cin >> a;
            S[i].insert(a);
            num[a].insert(i);
        }
    }

    ll ans = 0;
    for(ll i = 0;i<n;i++) {
        ll b;
        cin >> b;
        for(auto &s:num[b]) {
            if(S[s].size() == 1) ans++;

            S[s].erase(b);
        }
        num[b].clear();
        cout << ans << "\n";
    }
}

//克服した食材Biが含まれる料理のみ食べられるようになる可能性がある。その料理に含まれる食材の集合にアクセスして、その食材を消去する。その集合の要素数が0なら答えを1加算する。