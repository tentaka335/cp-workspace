#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,q;
    cin >> n >> q;

    ll ans = n;
    using P = pair<ll,ll>;
    set<P> S;
    for(ll qi = 0;qi<q;qi++) {
        ll l,r;
        cin >> l >> r;
        l--;

        auto it = S.lower_bound(P(l,-1));//[l,r)に統合されるもののうち、2番目のもの
        if(it != S.begin() && prev(it)->second>=l) it--;
        while(it !=S.end() && it->first<=r) {
            ans+=it->second-it->first;
             l =min(l,it->first);
            r = max(r,it->second);
            S.erase(it++);//後ろからインクリメントするとitを消して、itは次のものを見つけることができる。
        }

        S.emplace(l,r);
        ans-=r-l;
        cout << ans << "\n";
    }

}