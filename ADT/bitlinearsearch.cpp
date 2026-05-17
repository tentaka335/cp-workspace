#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll N,M,ans=0;
    cin >> N >> M;
    vector<vector<ll>> K(M);
    for (ll i=0; i<M; i++) {
        ll k=0;
        cin >> k ;
        for (ll j = 0; j<k; j++) {
            cin >> K[i][j];
        }
    }
    vector<ll> p(M);
    for(ll i=0; i<M; i++) cin >> p[i];

    for (ll i=0; i < (1<<N); i++) {
        for (ll j=0; j<N; j++) {
            if (i/(1<<(j)) % 2 ==1) {

            }
        }
        
    }
}