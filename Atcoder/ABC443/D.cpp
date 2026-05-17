#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    for(ll ti = 0;ti<t;ti++) {
        ll n;
        cin >> n;
        vector<ll> R(n+1);
        vector<set<ll>> invR(n+1);
        for(ll i = 1;i<=n;i++) {
            cin >> R[i];
            invR[R[i]].insert(i);
        }

        ll ans = 0;

        for(ll i = 1;i<=n;i++) {
            for(auto pos : invR[i]) {
                if(1<=pos+1&&pos+1<=n) {
                    if(llabs(R[pos]-R[pos+1])>1) {
                        ans += R[pos+1] - R[pos] - 1;
                        invR[R[pos+1]].erase(pos+1);
                        R[pos+1] = R[pos] + 1;
                        invR[R[pos+1]].insert(pos+1);
                    }
                }
                   if(1<=pos-1&&pos-1<=n) {
                    if(llabs(R[pos]-R[pos-1])>1) {
                        ans += R[pos-1] - R[pos] - 1;
                        invR[R[pos-1]].erase(pos-1);
                        R[pos-1] = R[pos] + 1;
                        invR[R[pos-1]].insert(pos-1);
                    }
                }
            }
        }
           cout << ans << "\n";
    }
}



/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/



