#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll dx[8] = {1,-1,0,0,1,-1,1,-1};
const ll dy[8] = {0,0,1,-1,-1,1,-1,1};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s,t;
    cin >> s >> t;

    ll nn = t.size();

    unordered_map<char,vector<ll>> A;
    ll n = s.size();

    rep(i,n) {
        A[s[i]].push_back(i);
    }

    ll ans = 0;
    rep(i,n) {
        ll b = i;//次はここから探してね
        bool ok = true;//tとの共通が作れるか

        rep(j,nn) {
            char c = t[j];
             ll pos = lower_bound(all(A[c]),b) - A[c].begin();
             if(pos>=A[c].size()) {//
                ok = false;
                break;
             }
             b = A[c][pos] + 1;
        }

        if(ok == true) {
            ans+= b - 1 - i;
        }
        else {
            ans+= n - i;
        }
    }
        
    cout << ans << "\n";
    
    return 0;
}