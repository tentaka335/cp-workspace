#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

ll n,k;


bool isOK(ll t, ll key,vector<ll> &A) {
    ll res = 0;
    rep(i,n) res+=t/A[i];
    if (res>=key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
ll binary_search(ll key,vector<ll> &A) {
    ll ng = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = 1e9 + 1; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()
    
    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid, key,A)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    vector<ll> A(n);
    rep(i,n) cin >> A[i];
    cout << binary_search(k,A) << "\n";
    return 0;
}