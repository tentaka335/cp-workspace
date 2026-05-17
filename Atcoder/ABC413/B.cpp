#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<string> S(n);
    for (ll i = 0;i<n;i++) cin >> S[i];
    set<string> ss;
    for(ll i = 0; i<n-1;i++) {
        for (ll j = i+1; j<n;j++) {
            string s = S[i] + S[j];
            string s2 = S[j] + S[i];
            ss.insert(s);
            ss.insert(s2);
        }
    }
    cout << ss.size() << "\n";
}
