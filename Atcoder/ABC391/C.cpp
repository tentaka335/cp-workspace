#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,q;
    cin >> n >> q;
    vector<ll> nest(n+1,1);
    vector<ll> pigion(n+1);
    for(ll i = 1;i<=n;i++) pigion[i] = i;
    ll ans = 0;
    for(ll qi = 0;qi<q;qi++) {
        ll qt;
        cin >> qt;
        if(qt == 1) {
            ll p,h;
            cin >> p >> h;
            nest[pigion[p]]--;
            if(nest[pigion[p]]==1) ans--;
            nest[h]++;
            if(nest[h]==2) ans++;
            pigion[p] = h;
            
        }
        else {
            cout << ans << "\n";
        }
    }
}


