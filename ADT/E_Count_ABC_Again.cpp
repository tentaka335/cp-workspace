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
    
    ll n,q;
    string s;
    cin >> n >> q;
    cin >> s;
     ll ans = 0;
    for(ll i = 0;i<n-2;i++) {
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') ans++;
    }
    s += "..";
    s = ".."  + s;
   
    

    rep(qi,q) {
        ll x;
        char c;
        cin >> x >> c;
        x++;
        ll cnt = 0;
        for(ll i = x - 2;i<=x;i++) {
            if(s[i]=='A'&& s[i+1] == 'B' && s[i+2] == 'C' ) {
                cnt++;
            }
        }
        s[x] = c;
        ll cnt1 = 0;
        for(ll i = x - 2;i<=x;i++) {
            if(s[i]=='A'&& s[i+1] == 'B' && s[i+2] == 'C' ) {
                cnt1++;
            }
        }
        ans += cnt1 -cnt;
        cout << ans << "\n";
    }
    
    return 0;
}