#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> H(n+1);
    vector<ll> DP(n+1);
    vector<ll> ans;
    for(ll i=1; i<=n; i++) {
        cin >> H[i];
    }
    DP[1] = 0;
    DP[2] = abs(H[2]-H[1]);
    for (ll i=3; i<=n; i++) {
        DP[i] = min(DP[i-1]+abs(H[i-1]-H[i]),DP[i-2]+abs(H[i-2]-H[i]));
    } 
    ans.push_back(n);
    ll load = n;
    while(true) {
        if (load == 1) break;
        if (DP[load] == DP[load-1]+abs(H[load-1]-H[load])) {
            ans.push_back(load-1);
            load = load - 1;
        }
        else {
            ans.push_back(load-2);
            load = load -2;
    }
}
    reverse(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for (auto a : ans) {
        cout << a << " ";
    }
}