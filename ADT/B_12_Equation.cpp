#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

bool isOK(double x, ll key) {
    if (x*x*x + x >=key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
double binary_search(ll key) {
    double ng = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
    double ok = key; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()
     
    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 0.001) {
        double mid = (ok + ng) / 2;

        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    cout << fixed << setprecision(10);
    cout << binary_search(n);
    
    return 0;
}