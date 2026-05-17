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
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    vector<ll> A(7),B(7),C(7);
  
    double ans = 0;
    for(ll i = 1;i<=6;i++) {
        ll a;
        cin >> a;
        A[a]++;
    }
    for(ll i = 1;i<=6;i++) {
        ll a;
        cin >> a;
        B[a]++;
    }
    for(ll i = 1;i<=6;i++) {
        ll a;
        cin >> a;
        C[a]++;
    }
    
    ans+=(A[4]*B[5]*C[6]);
    ans+=(A[4]*B[6]*C[5]);
    ans+=(A[5]*B[4]*C[6]);
    ans+=(A[5]*B[6]*C[4]);
    ans+=(A[6]*B[4]*C[5]);
    ans+=(A[6]*B[5]*C[4]);

    ans/=216;
    cout << fixed << setprecision(10);
    cout << ans;
    
    return 0;
}