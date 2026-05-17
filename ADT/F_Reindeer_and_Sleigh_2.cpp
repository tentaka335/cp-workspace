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
    
    ll t;
    cin >> t;
    rep(qt,t) {
        ll n;
        cin >> n;
        ll ans = 0;
        ll psum = 0;
        vector<ll> PW(n);
        rep(i,n) {
            ll p,w;
            cin >> w >> p;
            psum+=p;
            PW[i] = w + p;
        }
        sort(all(PW));
        rep(i,n) {
            if(psum - PW[i]>=0) {
                ans++;
                psum -=PW[i];
            }
            else {
                break;
            }
        }
        cout << ans << "\n";
    }
    
    return 0;
}