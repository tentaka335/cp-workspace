#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll abcsum = 0;
    rep(i,n-2) {
        if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') abcsum++;
    }
    rep(qi,q) {
        ll x;
        cin >> x;
        x--;
        char c;
        cin >> c;
        for(ll i = x- 2;i<=x;i++) {
            if(0<=i&&i+2<=n-1) {
                if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') abcsum--;
            }
        }
        s[x] = c;
         for(ll i = x- 2;i<=x;i++) {
            if(0<=i&&i+2<=n-1) {
                if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C') abcsum++;
            }
        }

        cout << abcsum << "\n";
        
    }
    
    return 0;
}