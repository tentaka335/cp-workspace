#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<string> C(n);
    vector<ll> L(n);

for(ll i = 0;i<n;i++) cin >> C[i] >> L[i];
    string s;
    ll len = 0;
    for (ll i = 0; i<n;i++) {
        len += L[i];
        if (len > 100) {
            cout << "Too Long" << "\n";
            return 0;
        }
        for (ll j = 0;j<L[i]; j++) s+=C[i];
    }
    cout << s << "\n";
}
