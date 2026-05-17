#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    ll n ; 
    cin >> n;
    vector<ll> R(n),C(n);
    for (ll i = 0; i<n; i++) {
        cin >> R[i] >> C[i];
    }
    sort(R.begin(),R.end());
    sort(C.begin(),C.end());
    ll rmin = R[0],rmax = R[n-1],cmin=C[0],cmax=C[n-1];
    ll distancemax = max(rmax-rmin,cmax-cmin);
    if (distancemax%2 == 0) cout << distancemax/2 << "\n";
    else cout << (distancemax+1)/2 << "\n";
}  
