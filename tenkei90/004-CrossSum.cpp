#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h,w;
    cin >> h >> w;
    vector<vector<ll>> grit(h+2,vector<ll>(w+2));
    vector<ll> sumh(h+1),sumw(w+1);
    for(ll i = 1;i<=h;i++) {
        for(ll j = 1;j<=w;j++) {
            cin >> grit[i][j];
            sumh[i]+=grit[i][j];
            sumw[j]+=grit[i][j];
        }
    }
    for(ll i = 1;i<=h;i++) {
        for(ll j = 1;j<=w;j++) {
            cout << sumh[i] + sumw[j] - grit[i][j] << " ";
        }
        cout << "\n";
    }
}