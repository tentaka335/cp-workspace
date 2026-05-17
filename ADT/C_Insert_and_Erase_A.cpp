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
    
    string s,t;
    cin >> s >> t;
    ll n = s.size();
    ll k = t.size();
    vector<pair<char,ll>> ss,tt;
    ll cntsA = 0,cnttA = 0;
    rep(i,n) {
        if(s[i]!='A') {
            ss.push_back({s[i],cntsA});
            cntsA = 0;
        }
        else {
            cntsA++;
        }
    }

        
      rep(i,k) {   
        if(t[i]!='A') {
            tt.push_back({t[i],cnttA});
            cnttA = 0;
        }
        else {
            cnttA++;
        }
    }

    ss.push_back({'A',cntsA});
    tt.push_back({'A',cnttA});


    

    if(ss.size()!=tt.size()) {
        cout << -1;
        return 0;
    }
    rep(i,ss.size()) {
        if(ss[i].first!=tt[i].first) {
            cout << -1;
            return 0;
        }
    }



     ll nn = ss.size();
     ll ans = 0;
     for(ll i = 0;i<nn;i++) {
        ans += llabs(ss[i].second - tt[i].second);
     }
     cout << ans ;

  

    cntsA = 0;cnttA = 0;
    



    
    
    
    return 0;
}