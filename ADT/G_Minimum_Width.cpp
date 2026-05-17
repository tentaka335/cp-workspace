#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

 ll n,m;

 vector<ll> L(200009);

bool isOK(ll key) {
    ll lensum = 0;
    ll gyousum = 0;
    for(ll i = 0;i<n;i++) {
        if(lensum + L[i] <=key) {
            lensum +=L[i];
            if(lensum == key) {
                gyousum += 1;
                lensum = 0;
            }
            else {
                lensum+=1;
            }
        } else {
            gyousum+=1;
            lensum = L[i];
            if(lensum>key) {
                return false;
            }
            if(lensum==key) {
                gyousum+=1;
                lensum = 0;
            }
            else {
                lensum+=1;
            }
        }
    } 
    if(lensum != 0) gyousum ++;

    if(gyousum>m) {
            return false;
        }
    return true;
}

// 汎用的な二分探索のテンプレ
ll binary_search() {
    ll ng = 0; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll ok = inf; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()
    
    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    rep(i,n) cin >> L[i];
 

  


    ll ans = binary_search();
    cout << ans;



    
    return 0;
}