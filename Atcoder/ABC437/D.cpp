#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    ll p = 998244353;
    vector<ll> A(n);
    vector<ll> B(m);
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
    }
    for(ll i = 0;i<m;i++) {
        cin >> B[i];
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    ll ans = 0;
    for(ll i = 0;i<n;i++) {
        ll a = 0;
        auto it = upper_bound(B.begin(),B.end(),A[i]);
        if(it == B.end()) {
            a = m;
        }
        else {
            a = it - B.begin();
        }
        ans =(ans + (2*a-m)*A[i]+p*p)%p;
    }
    for(ll i = 0;i<m;i++) {
        ll b = 0;
        auto it = lower_bound(A.begin(),A.end(),B[i]);
        if(it == A.end()) {
            b = n;
        }
        else {
            b = it - A.begin();
        }
        ans = (ans + (2*b-n)*B[i]+p*p)%p;
    }
    cout << ans << "\n";
}