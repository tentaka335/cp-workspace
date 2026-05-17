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
    
    ll n;
    cin >> n;
    vector<ll> yakusuu(n+1);

    for(ll i = 1;i<=n;i++) {
        for(ll j = 1;j*j<=i;j++) {
            if(i%j==0) {
                if(j==i/j) yakusuu[i]++;
                else yakusuu[i]+=2;
            }
        }
    }
    ll ans = 0;
    for(ll i = 1;i<=n-1;i++) {
        ans +=yakusuu[i]*yakusuu[n-i];
    }
    cout << ans;
    return 0;
}