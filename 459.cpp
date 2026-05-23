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
    
    ll n;
    cin >> n;
    vector<string> S(n);
    for(ll i = 0;i<n;i++) cin >> S[i];
    vector<ll> ans(n);
    for(ll i = 0;i<n;i++) {
        char c = S[i][0];
        if(c=='a'||c=='b'||c=='c') ans[i] = 2;
        if(c=='d'||c=='e'||c=='f') ans[i] = 3;
        if(c=='g'||c=='h'||c=='i') ans[i] = 4;
        if(c=='j'||c=='k'||c=='l') ans[i] = 5;
        if(c=='m'||c=='n'||c=='o') ans[i] = 6;
        if(c=='p'||c=='q'||c=='r'||c=='s') ans[i] = 7;
        if(c=='t'||c=='u'||c=='v') ans[i] = 8;
        if(c=='w'||c=='x'||c=='y'||c=='z') ans[i] = 9;
        
    }
    for(ll i = 0;i<n;i++) cout << ans[i];
    
    return 0;
}