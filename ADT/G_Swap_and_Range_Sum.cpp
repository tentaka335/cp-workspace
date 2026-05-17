#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;




int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n ,q;
    cin >> n >> q;
    vector<ll> A(n+1);
    vector<ll> S(n+1);
    for(ll i =1;i<=n;i++) {
        cin >> A[i];
        S[i] = S[i-1] + A[i];
    }
    rep(qi,q) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll x;
            cin >>x;
            swap(A[x],A[x+1]);
            S[x] = S[x-1] + A[x];
            S[x+1] = S[x] + A[x+1];
        }
        if(qt==2) {
            ll l,r;
            cin >> l >> r;
            cout << S[r] - S[l-1] << "\n";
        }
    }
    return 0;
}