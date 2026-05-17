#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,q;
    cin >> n >> q;
    vector <ll> A(n+1),B(n+1);
    for (ll i = 1; i<=n;i++) cin >> A[i];
    for (ll i = 1; i<=n;i++) cin >> B[i];
    ll minsum = 0;
    for (ll i = 1; i<=n; i++) minsum +=min(A[i],B[i]);

    for (ll i = 0; i<q; i++) {
        string c;
        ll x, v ;
        cin >> c >> x >> v;
        ll befmin = min(A[x],B[x]);
        if (c=="A"){
            A[x] = v;
        }
        else B[x] = v;
        
        minsum = minsum - befmin + min(A[x],B[x]);

        cout << minsum << "\n";
    }
    }
