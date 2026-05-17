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
    
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n),B(n);
    rep(i,n) {
        cin >> A[i];
        B[i]= A[i];
    }
    sort(all(B));
    for(ll i = 0;i<=n-k-1;i++) {
        if(A[i]>A[i+k]) swap(A[i],A[i+k]);
    }
    rep(i,n) {
        if(A[i]!=B[i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}