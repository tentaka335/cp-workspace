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
    vector<ll> A(n+1);
    
    for(ll i = 1;i<=n;i++) {
        cin >> A[i];
    }
     vector<ll> ans(n+1);
    for(ll i = n;i>=1;i--) {
        if(A[i]==i) ans[i] = i;
        else ans[i] = ans[A[i]];
    }

    for(ll i = 1;i<=n;i++) {
        cout << ans[i] << " ";
    }

    

    

    
}


/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/






/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/



