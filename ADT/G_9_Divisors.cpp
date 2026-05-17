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
    ll ans = 0;
    
    for(ll i = 1;i*i<=n;i++) {
        ll cnt = 0;
        ll k = i*i;
        for(ll j = 1;j*j<=k;j++) {
            if(k%j==0) {
                if(j==k/j) cnt++;
                else cnt+=2;

                //if(cnt>=10) break;
            }
        }
        if(cnt==) ans++;
    }
    cout << ans;
    return 0;
}