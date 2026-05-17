#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<ll> A(n),B(m);
    for ( ll i = 0; i<n;i++) cin >> A[i];
    for ( ll i = 0; i<m;i++) cin >> B[i];

    ll a = n;
    for (ll i = 0; i<m; i++) {
        for (ll j = 0; j<a; j++) {
            if (B[i] == A[j]) { 
                A.erase(A.begin() + j);
                a = A.size();
                break;
            }
        }
    }
    for (auto p : A) cout << p << " ";
}
