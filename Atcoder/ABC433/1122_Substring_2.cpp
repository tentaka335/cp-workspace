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
    
    string s;
    cin >> s;
    char nowc = s[0];
    ll cnt = 1;
    vector<pair<char,ll>> A;
    for(ll i = 1;i<s.size();i++) {
        if(nowc!=s[i]) {
            A.push_back({nowc,cnt});
            nowc = s[i];
            cnt = 1;
        }
        else {
            cnt++;
        }
        ll k = s.size();
        if(i==k-1) A.push_back({nowc,cnt});
        
    }
    ll ans = 0;
    ll n = A.size();
   for(ll i = 0;i<n-1;i++) {
     if(A[i+1].first-A[i].first==1) ans+=min(A[i].second,A[i+1].second);
   }
   cout << ans;
    
    return 0;
}