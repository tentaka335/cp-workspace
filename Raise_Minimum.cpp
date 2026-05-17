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

ll n,k;
vector<ll> A(200009);

bool isOK(ll key) {

    ll cnt = 0;

    for(ll i = 0;i<n;i++) {
        if(A[i]<key) {
            ll div = key - A[i];
           cnt  += (div + (i+1) - 1) / (i+1)  ;
           if(cnt>k) return false;
        }
    }
    if (cnt<=k) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search() {
    ll ok = 1; 
    ll ng = 2000000000000000001LL; 
    
    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (llabs(ng - ok) > 1) {
        llll mid = ok + (ng - ok) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    rep(i,n) {
        cin >> A[i];
    }
    cout << binary_search();
    
    
    return 0;
}