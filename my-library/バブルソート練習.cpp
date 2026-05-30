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
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    /*for(ll i = 0;i<n-1;i++) {
        for(ll j = 0;j<n-1;j++) {
            if(A[j]>A[j+1]) swap(A[j],A[j+1]);
        }

    }*/
   //選択ソート
   for(ll i = 0;i<n;i++) {
    ll minele = A[i],idx = i;
    for(ll j = i+1;j<n;j++) {
        if(minele>A[j]) {
            minele = A[j];
            idx = j;
        }
    }
    swap(A[i],A[idx]);
   }

    rep(i,n) cout << A[i] << " ";
    
    return 0;
}