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
const auto inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll q;
    cin >> q;
    queue<Pll> Q;
  

    rep(qi,q) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll c,x;
            cin >> c >> x;
            Q.push({c,x});
        }
        else {
            ll k;
            cin >> k;
            ll sum = 0;
            while(true) {
                auto [c,x] = Q.front();
                if(c>k) {
                    sum+=k*x;
                    Q.front() = make_pair(c-k,x);
                    break;
                }
                else if(c==k) {
                    sum+=c*x;
                    Q.pop();
                    break;
                }
                else {
                    sum+=c*x;
                    Q.pop();
                    k-=c;
                }
            }
            cout << sum << "\n";
        }
    }
    
    return 0;
}