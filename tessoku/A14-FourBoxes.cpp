#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n),B(n),C(n),D(n);
    for (ll i=0; i<n;i++) cin >> A[i];
    for (ll i=0; i<n;i++) cin >> B[i];
    for (ll i=0; i<n;i++) cin >> C[i];
    for (ll i=0; i<n;i++) cin >> D[i];
    vector<ll> AB,CD;

    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n;j++) {
            AB.push_back(A[i]+B[j]);
            CD.push_back(C[i]+D[j]);
        }
    }
    sort(AB.begin(),AB.end());
    sort(CD.begin(),CD.end());

    for(ll i=0; i<n*n; i++) {
        ll target = k - AB[i];
        if (target>=0) {
            auto it = lower_bound(CD.begin(),CD.end(),target);
            if ((it !=CD.end() && *it == target)) {
                cout << "Yes" << "\n" ;
                return 0;
            }
        }
    }
    
    
    /*for(ll i=0; i<n*n; i++) {
        for (ll j=0; j<n*n; j++) {
            if(AB[i]+CD[j] == k) {
                cout << "Yes" << "\n";
                return 0;
            }
        }
    }*/
    cout << "No" << "\n";
}