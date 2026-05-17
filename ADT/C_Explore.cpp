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
    
    ll n,m,t;
    cin >> n >> m >> t;
    vector<ll> A(n+1);
    vector<ll> XY(n+1);

    for(ll i = 1;i<=n-1;i++) {
        cin >> A[i+1];
    }

    rep(i,m) {
        ll x,y;
        cin >> x >> y;
        XY[x] = y;
    }
    for(ll i = 2;i<=n;i++) {
        t -=A[i];
        if(t<=0) {
            cout << "No";
            return 0;
        }
        t +=XY[i];
    }

    cout << "Yes";
    
    return 0;
}