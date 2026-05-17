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
using mint = modint998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<ll> A(n),B(n);//0-indexed

    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];

    vector<vector<mint>> DP(n,vector<mint>(3001));//DP[i][j]Cを番目までつなげたときi番目の値がj以下のものの総和
    
    for(ll i = A[0];i<=3000;i++) {
        if(i==A[0]) DP[0][i] = 1;
        else {
           if(i<=B[0]) DP[0][i] = DP[0][i-1]+1;
           else DP[0][i] = DP[0][i-1];
        }
    }
     

    for(ll i = 1;i<n;i++) {
        for(ll j = A[i];j<=3000;j++) {
            if(j<=B[i]) DP[i][j] = (DP[i-1][j] + DP[i][j-1]);
            else DP[i][j] = DP[i][j-1];
        }
    }

    
    cout << DP[n-1][B[n-1]].val();
    
    
    return 0;
}