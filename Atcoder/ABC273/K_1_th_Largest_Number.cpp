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
    vector<ll> A(n),B;
    set<ll> C;
    rep(i,n) {
        cin >> A[i];
        if(C.count(A[i])) continue;
        C.insert(A[i]);
        B.push_back(A[i]);
    
    }
    sort(all(B));
    vector<ll> D(n);
    rep(i,n) {
        ll pos = upper_bound(all(B),A[i]) - B.begin();
        ll len = B.size();
        D[len - pos]++;
    }

    rep(i,n) {
        cout << D[i] << "\n";
    }
    
    return 0;
}