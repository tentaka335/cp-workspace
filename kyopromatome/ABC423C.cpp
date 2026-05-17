#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll N,R;
    cin >> N >> R;
    vector<ll> key(N);
    for(ll i=0; i<N; i++) {
        cin >> key[i];
    }
    ll ans = 0;
    ll firstopen = -1;
    for (ll i = 0; i<R; i++) {
        if (key[i] == 0 ) {
            firstopen = i;
            break;
        }
    }
if (firstopen >= 0) {
    for (ll i = firstopen; i<R; i++) {
        if (key[i] == 0) {
            ans++;
        } else {
            ans+=2;
        }
    }
}
reverse(key.begin(),key.end());
firstopen = -1;
    for (ll i = 0; i<N-R; i++) {
        if (key[i] == 0 ) {
            firstopen = i;
            break;
        }
    }
if (firstopen >= 0) {
    for (ll i = firstopen; i<N-R; i++) {
        if (key[i] == 0) {
            ans++;
        } else {
            ans+=2;
        }
    }
}

cout << ans << endl;
}