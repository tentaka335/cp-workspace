#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
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
    
    string s;
    cin >> s;
    ll n = s.size();
    ll l = 0,r = 1;
    ll ans = 0;
    
    ans+=1;

    while(l<n&&r<n) {
        if(s[r]==s[r-1]) {
            l = r;
            ans = (ans+1)%MOD2;
        }
        else {
            ans = (ans + r - l + 1)%MOD2;
        }
        r++;
        
    }
    cout << ans%MOD2;
    return 0;
}