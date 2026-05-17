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


ll n , m , k;

ll binary_search(ll key) {

}



bool isOK(ll index, ll key,vector<ll> &B) {
    ll pos = upper_bound(all(B),index) - B.begin();
    
    if (true/*条件式*/) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key) {
    ll ng = -1; 
    ll ok = 1000000000; 
    
    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}



int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n , m , k;
    cin >> n >> m >>k;
    vector<Pll> A(n);
    vector<ll> S(n);
    rep(i,n) {
        ll a;
        cin >> a;
        A[i] = {a,i};
    }
    sort(all(A));
    rep(i,n) {
        if(i==0) S[i] = A[i].first;
        else S[i] = S[i-1] + A[i].first;
    }
    ll sum = S[n-1];
    vector<ll> B(n);
    rep(i,n) B[i] = A[i].first;

    vector<ll> C(n+1,-1);

    rep(i,n) {
        ll a = A[i].first;
        ll ans = binary_search(a);
    }


    
    
    return 0;
}