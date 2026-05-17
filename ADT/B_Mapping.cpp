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
    
    ll n,m;
    cin >> n >> m;
    vector<ll> F(m+1);
    rep(i,n) {
        ll f;
        cin >> f;
        F[f]++;
    }
    bool q1=true,q2 = true;
    for(ll i = 1;i<=m;i++) {
        if(F[i]>=2) q1 = false;
        if(F[i]==0) q2 = false;

    }

    cout << (q1?"Yes":"No") << "\n";
    cout << (q2?"Yes":"No") << "\n";
    
    return 0;
}