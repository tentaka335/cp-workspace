#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> P(n+1),Q(n+1),inverseQ(n+1);
    for(ll i = 1;i<=n;i++) cin >> P[i] ;
    for(ll i = 1;i<=n;i++) {
        cin >> Q[i];
        inverseQ[Q[i]] = i;
     }

    for(ll i = 1;i<=n;i++) {
        cout << Q[P[inverseQ[i]]] << " ";
    }
}



