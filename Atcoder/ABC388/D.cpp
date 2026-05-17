#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> A(n+1);
    vector<ll> imos(n+1);
    vector<ll> S(n+1);

    vector<ll> ans(n+1);
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
    }
    ll k = min(A[0],n-1);
    imos[1]++;imos[k+1]--;
    ans[0] = A[0] - k;
    for(ll i = 1;i<n;i++) {
        S[i] = S[i-1] + imos[i];
        A[i] += S[i];
        ll item = min(A[i],n-1-i);
        ans[i] = A[i] - item;
        imos[i+1]++;
        imos[i+1+item]--;
    }
    for(ll i = 0;i<n;i++) {
        cout << ans[i] << " ";
    }
}


