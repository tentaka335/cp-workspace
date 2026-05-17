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
    
    ll n;
    cin >> n;
    vector<ll> X(n),Y(n);
    rep(i,n) cin >> X[i]>> Y[i];
    string s;
    cin >> s;

    map<pair<ll,char>,ll> YcX;

    rep(i,n) {
        ll x = X[i],y = Y[i];
        char c = s[i];
        if(c=='R') {
            if(YcX.count({y,'L'})) {
               if( YcX[{y,'L'}] > x ) {
                cout << "Yes";
                return 0;
               }
            }
        }
          if(c=='L') {
            if(YcX.count({y,'R'})) {
               if( YcX[{y,'R'}] < x ) {
                cout << "Yes";
                return 0;
               }
            }
        }
        if(!YcX.count({y,c})) YcX[{y,c}] = x;
        else {
            if(c=='L') chmax(YcX[{y,c}],x);
            else chmin(YcX[{y,c}],x);
        }

    }
  
    cout << "No";
    return 0;
}