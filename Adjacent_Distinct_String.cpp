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
    
    ll t;
    cin >> t;
    rep(ti,t) {




        string s;
        cin >> s;
        ll n = s.size();
        map<char,ll> A;
        set<pair<ll,char>> S;
        rep(i,n) {
            A[s[i]]++;
        }
        for(auto p : A) {
            auto [c,v] = p;
            S.insert({v,c});
        }
        if(A.size()==1&&n!=1) {
            cout << "No" << "\n";
            continue;
        }
        
        bool can = true;

        vector<char> ans(n+1);
        for(ll i = 1;i<=n;i++) {
            
            auto it = S.end();
            it--;
            auto [v,c] = *it;
            if(c!=ans[i-1]) {
                
                ans[i] = c;
                S.erase({v,c});
                S.insert({v-1,c});
            }
            else {
                it--;
                auto [vv,cc] = *it;
                if(vv<=0) {
                    can = false;
                    break;
                } else {
                    ans[i] = cc;
                    S.erase({vv,cc});
                    S.insert({vv-1,cc});
                }

            }
            
        }
        if(can==false) {
            cout << "No" << "\n";
            continue;
        } else {
            cout << "Yes" << "\n";
            for(ll i = 1;i<=n;i++) cout << ans[i];
            cout << "\n";
        }


    }
    
    return 0;
}