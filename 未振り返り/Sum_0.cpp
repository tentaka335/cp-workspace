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
    
    ll n;
    cin >> n;
    vector<ll> L(n+1),R(n+1);
    vector<ll> SL(n+2),SR(n+2);
    for(ll i = 1;i<=n;i++) {
        cin >> L[i] >> R[i];
        SL[i] = SL[i-1] + L[i];
        SR[i] = SR[i-1] + R[i];
    }

    if(!(SL[n]<=0&&0<=SR[n])) {
        cout << "No" << "\n";
        return 0;
    }
    
    cout << "Yes" << "\n";
    ll asum = 0;
    for(ll i = 1;i<=n;i++) {
       ll a;
       a = -L[n] + L[i] - asum;
       cout << a << " ";
       asum += a;
    }
    return 0;
}