#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k,x;
    cin >> n >> k >> x;
    vector<string> S(n);
    vector<string> ans;
    for (ll i = 0; i<n;i++) cin >> S[i];
    vector<ll> pw(k+1);
    pw[0] = 1;
    for(ll i = 0;i<k;i++) pw[i+1] = pw[i]*n;
    for(ll i = 0;i<pw[k];i++) {
        string ns;
        for(ll j = 0;j<k;j++) {
            ns+=S[i/pw[j]%n];
        }
        ans.push_back(ns);
    }
    sort(ans.begin(),ans.end());
    cout << ans[x-1] << "\n";
}
