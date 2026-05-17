#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<string> S(n+1);
    vector<ll> score(n+1);
    for (ll i=0; i<n; i++) cin >> S[i];

    for (ll i=0; i<m; i++) {
        ll x=0, y = 0;
        for (ll j = 0; j <n; j++) {
            if (S[j][i] == '0') x +=1;
            else y+=1;
        }
        if (x<y) {
            for (ll k = 0; k<n; k++) {
                if (S[k][i] == '0') score[k] +=1;
            }
        }
        else {
                for (ll k=0; k<n;k++) {
                    if (S[k][i] == '1') score[k] +=1; 
                }
            }
        }
        ll max = *max_element(begin(score),end(score));
        for (ll i = 0; i<n;i++) {
            if (score[i] == max) cout << i+1 <<" ";
        }
    }
