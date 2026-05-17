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
    
    ll n,m,sx,sy;
    cin >> n >> m >> sx >> sy;
    ll ans = 0;
    unordered_map<ll,set<ll>> xtoy;
    unordered_map<ll,set<ll>> ytox;

    

    rep(i,n) {
        ll x,y;
        cin >> x >> y;
       
        xtoy[x].insert(y);
        ytox[y].insert(x);
    }
  

    rep(i,m) {
        char c;
        ll x;
        cin >> c >> x;

        if(c=='L'||c=='R') {
            ll l ,r;
            if(c == 'L') {
                l = sx - x;
                r = sx;
                sx -= x;
            }
            else {
                l = sx;
                r = sx + x;
                sx +=x;
            }
            auto left = ytox[sy].lower_bound(l);
          if(left==ytox[sy].end()) continue;
        
          while(true) {

            if(left==ytox[sy].end()) break;
            if(*left>r) break;


            ll pos = *left ;
           
            ans++;
            xtoy[pos].erase(sy);
            left = ytox[sy].erase(left);

          }

        }
        if(c=='D'||c=='U') {

              ll l ,r;
            if(c == 'D') {
                l = sy - x;
                r = sy;
                sy -= x;
            }
            else {
                l = sy;
                r = sy + x;
                sy +=x;
            }

            auto left = xtoy[sx].lower_bound(l);
          if(left==xtoy[sx].end()) continue;
        
          while(true) {

            if(left==xtoy[sx].end()) break;
            if(*left>r) break;


            ll pos = *left ;
         
            ans++;
         
            ytox[pos].erase(sx);
            left = xtoy[sx].erase(left);

          }

        }
        
    }

    
    cout << sx << " " << sy << " " <<ans;
    
    
    
    return 0;
}