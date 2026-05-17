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
    
    ll n,h,m;
    cin >> n >> h >> m;
    vector<vector<ll>> DP(n+1,vector<ll>(m+1,-1));
    //DP[i][m] = i番目のモンスターを倒したとき持っている魔力がmのときのhの最大値
    vector<ll> A(n+1);
    vector<ll> B(n+1);
    for(ll i = 1;i<=n;i++) cin >> A[i] >> B[i];
  
    vector<vector<bool>> DP2(n+1,vector<bool>(m+1,false));
    
    DP[0][m] = h;

    
    for(ll i = 1;i<=n;i++) {
        for(ll j = 0;j<=m;j++) {
            if(0<=j+B[i]&&j+B[i]<=m) {
              
                DP[i][j] = max({-1LL,DP[i-1][j]-A[i],DP[i-1][j+B[i]]});
            }

            else DP[i][j] = max(-1LL,DP[i-1][j] - A[i]);
        }

    }
    for(ll i = n;i>=0;i--) {
        for(ll j = 0;j<=m;j++) {
            if(DP[i][j]>=0) {
                cout << i;
                return 0;
            }
        }
    }
    return 0;
}