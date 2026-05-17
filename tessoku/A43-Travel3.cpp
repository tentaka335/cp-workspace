#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,l;
    cin >> n >> l;
    vector<ll> A(n);
    vector<char> B(n);
    vector<ll> D(n);
    ll ans = 0;
    for(ll i = 0;i<n;i++) {
        cin >> A[i] >> B[i];
        if(B[i] == 'E') D[i] = l-A[i];
        else D[i] = A[i];
        ans = max(ans,D[i]);
    }
    cout << ans << "\n";
}