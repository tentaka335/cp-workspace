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
    
    ll n,x;
    cin >> n >> x;
    vector<ll> A(n+1);
    vector<ll> B(n+1);
    for(ll i = 1;i<=n;i++) cin >> A[i] >> B[i];

    vector<vector<bool>> DP(n+2,vector<bool>(10009));//i回目のジャンプをした後に入れる座標j;
    DP[0][0] = true;

    for(ll i = 0;i<n;i++) {
        for(ll j = 0;j<=x;j++) {
            if(DP[i][j]==true) {
                DP[i+1][j+A[i+1]] = true;
                DP[i+1][j+B[i+1]] = true;
            }
        }
    }
   
    cout << (DP[n][x] == true?"Yes":"No");
    
    return 0;
}