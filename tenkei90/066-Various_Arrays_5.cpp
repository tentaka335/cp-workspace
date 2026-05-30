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
    ll n;
    cin >> n;
    vector<ll> L(109),R(109);
    rep(i,n) {
        cin >> L[i] >> R[i];
    }
    double ans = 0;
    for(ll i = 0;i<n;i++) {
        for(ll j = i+1;j<n;j++) {
            for(ll x = L[i];x<=R[i];x++) {
                double temp = min(R[j]-L[j]+1,x - L[j]);
                ans+= max(temp,0.0)/((double)((R[i]-L[i]+1)*(R[j]-L[j]+1)));
            }
        }
    }
    cout << fixed << setprecision(12);
    cout << ans << "\n";
    
}


/*以下は転倒数ではなく、降下数をdpで求めるプログラム
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n;
    vector<ll> L(n+1),R(n+1);
    for(ll i = 1;i<=n;i++) {
        cin >> L[i] >> R[i];
    }
    vector<vector<double>> dp(109,vector<double>(109));//配るdp


    for(ll i = 1;i<=n-1;i++) {
       double wari = ((double)(R[i] - L[i] + 1));
        for(ll j = L[i];j<=R[i];j++) {
            
            for(ll k = L[i+1];k<=R[i+1];k++) {
                if(j>k) {
                    dp[i+1][k] += (dp[i][j]+(double)1)/wari;
                }
                else dp[i+1][k] += dp[i][j]/wari;
            
        }
    }
}
    double ans = 0;
    
    for(ll j = L[n];j<=R[n];j++) ans+=dp[n][j];
    cout << fixed << setprecision(10);
    cout << ans/(R[n]-L[n]+1) << "\n";
    return 0;
}
*/