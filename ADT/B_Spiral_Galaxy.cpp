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
    
    ll h,w;
    cin >> h >> w;
    vector<string> S(h);
    rep(i,h) cin >> S[i];
    ll ans = 0;
    for(ll h1 = 0;h1<h;h1++) {
        for(ll h2 = h1;h2<h;h2++) {
            for(ll w1 = 0;w1<w;w1++) {
                for(ll w2 = w1;w2<w;w2++) {
                    bool ok = true;
                    for(ll i = h1;i<=h2;i++) {
                        for(ll j = w1;j<=w2;j++) {
                            if(S[i][j]!=S[h1+h2 - i][w1+w2 - j]) {
                                ok = false;
                            }
                        }
                    }
                    if(ok == true) ans++;
                } 
            }
        }
    }
    cout << ans;
    return 0;
}