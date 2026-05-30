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
    ll n,q;
    cin >> n >> q;
    vector<ll> masu(600009);
    vector<ll> gyou(600009);//i行目が何個埋まっているか。
    vector<ll> up(600009);//i個以上積まれているマスの数

    ll vanished = 0;
    rep(qi,q) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll x;
            cin >> x;
            masu[x]++;
            gyou[masu[x]]++;
            up[masu[x]]++;
            if(gyou[masu[x]]==n) {
                vanished++;
            }
        }
        else {
            ll y;
            cin >> y;
            cout << up[y+vanished] << "\n";
        }
    }

    
    
    return 0;
}