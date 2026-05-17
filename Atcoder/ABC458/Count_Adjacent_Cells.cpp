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
    
    ll h,w;
    cin >> h >> w;
    if(h==1&&w==1) {
        cout << 0 << "\n";
        return 0;
    }
   if(h==1) {
    rep(i,h) {
        rep(j,w) {
            if(j==0||j==w-1) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << "\n";
    }
    return 0;
}
if(w==1) {
    rep(i,h) {
        rep(j,w) {
            if(i==0||i==h-1) cout << 1 << " ";
            else cout << 2 << " ";
        }
        cout << "\n";
    }
    return 0;

}


   
    rep(i,h) {
        rep(j,w) {
        if((i==0&&j==0)||(i==h-1&&j==0)||(i==0&&j==w-1)||(i==h-1&&j==w-1)) cout << 2 << " ";
        else if(i==0||i==h-1||j==0||j==w-1) cout << 3 << " ";
        else cout << 4 << " ";
    }
    cout << "\n";
}
    
    
    return 0;
}