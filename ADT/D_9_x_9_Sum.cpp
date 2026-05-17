#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll x;
    cin >> x;
    ll ans = 0;
    for(ll i = 1;i<=9;i++) {
        for(ll j = 1;j<=9;j++) {
            if(i*j!=x) ans+=i*j;
        }
    }
    
    cout << ans;
    return 0;
}