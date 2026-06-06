#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll dx[8] = {1,-1,0,0,1,-1,1,-1};
const ll dy[8] = {0,0,1,-1,-1,1,-1,1};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m;
    cin >> n >> m;
    vector<ll> A(n),B(m);
    rep(i,n) cin >> A[i];
    rep(i,m) cin >> B[i];
    sort(all(A));
    sort(all(B));
    
    ll ans = 0;
    ll b = 0;
    vector<bool> used(m);
    rep(i,m) {
        ll pos = lower_bound(A.begin()+b,A.end(),(B[i]+1)/2) - A.begin();
        if(pos>=n) {
            break;
        }
        
        else {
            ans++;
            b = pos+1;
        }
    }
    cout << ans << "\n";
    
    return 0;
}