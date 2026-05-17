#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n ;
    vector<ll> A(n+1);
    vector<ll> S(n+1);
    for(ll i = 1;i<=n;i++) {
        cin >> A[i];
        if(i == 1) S[i] = A[i];
        else S[i] = S[i-1] + A[i];
    }
    ll q;
    cin >> q;
    for(ll qi = 0;qi <q;qi++) {
        ll l,r;
        cin >> l >> r;
        ll atari = S[r] - S[l-1];
        ll hazure = r - (l-1) - atari;
        if(atari == hazure) cout << "draw" << "\n";
        if(atari > hazure) cout << "win" << "\n";
        if(atari < hazure) cout << "lose" << "\n";
    }
}