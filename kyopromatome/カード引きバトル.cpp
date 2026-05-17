#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> card(N);
    for (ll i = 0; i < N ; i++) cin >> card[i];

    sort(card.rbegin(),card.rend());
    ll devide = 0;
    for (ll i = 0; i < N; i++) if (i%2 == 0) {
        devide += card[i];
    } else {
        devide -= card[i];
    }
    cout << devide << endl;
}