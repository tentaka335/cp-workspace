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
    
    
    map<ll,ll> A,B;
    
    ll q;
    cin >> q;
    rep(qi,q) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll x;
            cin >> x;
            A[x]++;
            B[inf-x]++;
        }
        if(qt==2) {
            ll x,c;
            cin >> x >> c;
            if(A[x]<=c) A.erase(x);
            else A[x]-=c;
            if(B[inf-x]<=c) B.erase(inf-x);
            else B[inf-x] -=c;
        }
        if(qt==3) {
            for(auto p : A) {
                ll minv = p.first;
                for(auto pp : B) {
                    ll maxv = inf-pp.first;
                     cout << maxv - minv << "\n";
            break;
                }
                break;
            }
           
        }
    }

    
    return 0;
}