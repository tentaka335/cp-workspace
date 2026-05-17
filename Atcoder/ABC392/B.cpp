#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n>>m;
    vector<ll> A(m);
    vector<ll> ANS;
    for(ll i = 0;i<m;i++) cin >> A[i];
    for(ll i = 1 ;i<=n;i++) {
        bool notin = true;
        for(ll j = 0;j<m;j++) {
            if(i==A[j]) {
                notin = false;
                break;
            }
        }
        if (notin) ANS.push_back(i);
    }
    cout << ANS.size() << "\n";
    for(ll i = 0;i<ANS.size();i++) cout << ANS[i] << " ";
}


