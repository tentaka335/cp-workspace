#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,q;
    cin >> n >> q;
    vector<ll> A(n);


    for (ll i = 0;i<n;i++) cin >> A[i];
    sort(A.begin(),A.end());
    ll amax = A[A.size()-1];
    vector<ll> sum(amax+1,0);
    for (ll i = 1;i <= amax;i++) {
        ll pos = lower_bound(A.begin(),A.end(),i) - A.begin();
        sum[i] = sum[i-1]+A.size()-pos;//
    }
    for(ll i =0;i<q;i++) {
        ll b;
        cin >> b;
        if ( b>amax) cout << -1 << "\n";
        else cout << sum[b-1] + 1<< "\n";
    }
}