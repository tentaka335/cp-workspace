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
    vector<vector<ll>> X(n,vector<ll>(m));
    vector<ll> L(n);
    for(ll i = 0;i<n;i++) {
        ll l;
        cin >> l;
        L[i] = l;
        for(ll j = 0;j<l;j++) {
            cin >> X[i][j];
        }
    }
    vector<bool> used(m+1);
    for(ll i = 0;i<n;i++) {
        bool isok = false;
        for(ll j = 0;j<L[i];j++) {
            if(used[X[i][j]] == false ) {
                cout << X[i][j] << "\n";
                used[X[i][j]] = true;
                isok = true;
                break;
            }
        }
        if(isok == false) cout << 0 << "\n";
    }
    
    
    return 0;
}