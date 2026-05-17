#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<ll> A(n+1,n-1);
    for(ll i = 0;i<m;i++) {
        ll a,b;
        cin >> a >> b;
        A[a]--;
        A[b]--;
    }
    for(ll i = 1;i<=n;i++) {
        ll ans = A[i]*(A[i]-1)*(A[i]-2);
        ans/=6;
        cout << ans << " ";
    }
}



/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/



