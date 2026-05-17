#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,t;
    cin >> n >> t;
    vector<ll> A(n);
    ll ans = 0;
    
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
    }

    if(n==0) {
        cout << t << "\n";
        return 0;
    }

    
    ll nxwt = A[0]+100;
    ans += A[0];
    while(nxwt<=t) {
       auto it = lower_bound(A.begin(),A.end(),nxwt);
       if(it==A.end()) {
        ans +=t - nxwt;
        break;
       }
       ll pos = it - A.begin();
       ans +=A[pos] - nxwt;
       nxwt = A[pos] + 100;
        }
        cout << ans << "\n";
        return 0;
}



/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/



