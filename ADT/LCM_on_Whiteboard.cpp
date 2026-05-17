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
    if(n==1) {
        cout << 1;
        return 0;
    }
    set<ll> no1;
    unordered_map<ll,bool> douritu;
    unordered_map<ll,Pll> P;
    rep(i,n) {
        ll m;
        cin >> m;
        rep(j,m) {
            ll p,e;
            cin >> p >> e;
            
            if(P[p].first == e) {
                douritu[p] = true;
            }
            if(P[p].first<e) {
                douritu[p] = false;
                P[p] = {e,i};
            }
       
        }
    }

    for(auto a : P) {
      
        if(douritu[a.first] == false) {
            no1.insert(a.second.second);
        }
    }

    
  
    
    if(no1.size()==n) cout << n;
    else if(no1.size()==0) cout << 1;
    else cout << no1.size() + 1;
   
    return 0;
}