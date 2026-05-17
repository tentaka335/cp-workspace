#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<vector<ll>> A(n,vector<ll>(6));
    vector<ll> S(n);
    
    for(ll i = 0;i<n;i++) {
        for(ll j = 0;j<6;j++) {
            cin >> A[i][j];
            S[i] += A[i][j];
        }
    }

    ll ans = 1;
    for(ll i = 0;i<n;i++) {
        ans = (ans*S[i])%pow9p7;
    }

    cout << ans << "\n";
}



/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/



