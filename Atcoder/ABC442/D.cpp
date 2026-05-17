#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,q;
    cin >> n >> q;
    vector<ll> A(n+1);
    vector<ll> S(n+1);
    for(ll i = 1;i<=n;i++) {
        cin >> A[i];
        S[i] = S[i-1] + A[i];
    }
    for(ll qi = 0;qi<q;qi++) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll x;
            cin >> x;
            swap(A[x],A[x+1]);
            S[x] = S[x-1] + A[x];
            S[x+1] = S[x] + A[x+1];
        }
        if(qt==2) {
            ll l,r;
            cin >> l >> r;
            cout << S[r]-S[l-1] << "\n";
        }
    }
}



/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/



