#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    for(ll qt= 0;qt<t;qt++) {
        ll n;
        cin >> n;
        vector<ll> W(n),P(n),WP(n);
        ll psum = 0;
        ll ans = 0;
        for(ll i = 0;i<n;i++) {
            cin >> W[i] >> P[i];
            WP[i] = W[i]+P[i];
            psum +=P[i];
        }
        sort(WP.begin(),WP.end());
        ll sum = 0;
        for(ll i = 0;i<n;i++) {
            if(psum >= (sum + WP[i])) {
                ans++;
                sum += WP[i];
            }
            else {
                break;
            }
        }
        cout << ans << "\n";
    }
}