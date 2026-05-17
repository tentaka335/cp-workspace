#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,a,b;
    cin >> n >> a >> b;
    vector<ll> DP(n+1,0);
    for (ll i = 0;i<a;i++) DP[i] = -1;
    for (ll i = a;i<=n;i++) {
        if (i-b>=0) {
            if(DP[i-b] == -1 || DP[i-a] == -1) DP[i] = 1;
            else DP[i] = -1;
        }
        else {
            if (DP[i-a] == -1) DP[i] = 1;
            else if ( DP[i-a] == 1) DP[i] = -1;
        }
    }
    if (DP[n] == 1) cout << "First" << "\n";
    else cout << "Second" << "\n";
}
