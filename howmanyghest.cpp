#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll N,Q;
    cin >> N >> Q;
    vector<ll> sum(N+1);
    sum[0] = 0;
    for (ll i=1; i<=N;i++) {
        ll a=0;
        cin >> a;
        sum[i] = sum[i-1] + a;
    }
    for (ll i=0; i<Q; i++) {
        ll L,R;
        cin >> L >> R;
        cout << sum[R]-sum[L-1] << endl;
    }
}