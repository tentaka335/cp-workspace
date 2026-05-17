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
    
    ll n,d;
    cin >> n >> d;
    vector<string> S(n);
    rep(i,n) cin >>S[i];
    ll ans = 0;
    ll nowlen = 0;
    rep(i,d) {
        bool ok = true;
        rep(j,n) {
            if(S[j][i]=='x') {
                nowlen = 0;
                ok = false;
            }
        }
        if(ok==true) nowlen++;
        chmax(ans,nowlen);
    }
    
    cout << ans;
    return 0;
}