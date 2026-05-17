#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> key(N);
    for (ll i=0; i<N; i++) {
        cin >> key[i];
    }
    ll left, right;
    left =1;
    right =1;
    for (ll i=0; i<N; i++) {
        if (key[i] == 0) {
            left++;
        } else {
            break;
        }
    }
    reverse(key.begin(),key.end());
    for (ll i=0; i<N;i++) {
        if (key[i] == 0) {
            right++;
        } else {
            break;
        }
    }

    if (N+1 <= left + right) {
        cout << 0 << endl;
    } else {
        cout << N+1 -left -right << endl;
    }


}