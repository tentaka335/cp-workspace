#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    ll n,q;
    cin >> n >> q;
    vector<ll> A(n+1);
    for(ll i = 1;i<=n;i++) {
        cin >> A[i];
    }
    vector<vector<ll>> doubling(30,vector<ll>(n+1));
    for(ll i = 0;i<=29;i++) {
        for(ll j = 1;j<=n;j++) {
            if(i == 0) {
                doubling[i][j] = A[j];
            }
            else {
                doubling[i][j] = doubling[i-1][doubling[i-1][j]];
            }
        }
    }
    for(ll i = 1;i<=q;i++) {
        ll x,y;
        cin >> x >> y;
        ll currentplace = x;
        for(ll d = 29;d>=0;d--) {
            if (((y >> d) & 1 )== 1) currentplace = doubling[d][currentplace];
        }
        cout << currentplace << "\n";
    }
 }