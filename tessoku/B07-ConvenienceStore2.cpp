#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll T,N;
    cin >> T >> N;
    vector<ll> zenzikokuhi(T+1,0);
    vector<ll> joiner(T+1,0);
    for (ll i=0; i<N; i++) {
        ll L,R;
        cin >> L >> R;
        zenzikokuhi[L] ++;
        zenzikokuhi[R] --;
    }
    for (ll i = 1; i<=T; i++) {
        joiner[i] = joiner[i-1] + zenzikokuhi[i];
        cout << joiner[i] << endl;
    }
}