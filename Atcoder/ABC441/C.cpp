#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k,x;
    cin >> n >> k >> x;
    vector<ll> A(n);
    for(ll i = 0;i<n;i++) cin >> A[i];
    sort(A.rbegin(),A.rend());
    ll sake = 0;
    for(ll i = n - k;i<n;i++) {
        sake += A[i];
        if(sake>=x) {
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
  
}




/*

*/



