#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pll = pair<ll,ll>;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    set<ll> S;
    map<ll,ll> D;
    S.insert(0);
    D[0] = 1000000000;
    ll sum = 0;
    for(ll i = 1;i<=n;i++) {
        ll x;
        cin >> x;
        auto it = S.lower_bound(x);
        if(it == S.end()) {//右端に来た
            auto left = --it;//前置デクリメントに注意。
            ll bef = *left;
            ll nowd = D[bef];
            D[bef] = min(nowd,abs(x-bef));
            if(i == 1) sum = sum + D[bef];
            else sum = sum -nowd + D[bef];
            D[x] = abs(x-bef);
            sum = sum + D[x];
        }
        else {
            auto right = it;
            auto left = --it;
             ll bef = *left;
            ll nowbefd = D[bef];
            D[bef] = min(nowbefd,abs(x-bef));
            sum = sum -nowbefd + D[bef];
              ll af = *right;
            ll nowafd = D[af];
            D[af] = min(nowafd,abs(x-af));
            sum = sum -nowafd + D[af];
            D[x] =min(abs(x-af),abs(x-bef));
            sum = sum + D[x];
        }
        S.insert(x);
        cout << sum << "\n";
    }

}
