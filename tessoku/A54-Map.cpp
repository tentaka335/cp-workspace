#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll q;
    cin >> q;
    map<string,ll> score;
    for(ll i = 0;i<q;i++) {
        ll qt;
        cin >> qt;
        if(qt == 1) {
            string x;
            ll y;
            cin >> x >> y;
            score[x] = y;
        }
        else {
            string x;
            cin >> x;
            cout << score[x] << "\n";
        }
    }
}