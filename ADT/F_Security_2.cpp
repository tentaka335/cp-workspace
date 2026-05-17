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
    
    string s;
    cin >> s;
    ll n = s.size();
    ll cnt = 0;
    ll ans = 0;
    for(ll i = n-1;i>=0;i--) {
        ll num = ((s[i]-'0') - cnt + 10) %10;
        ans += num % 10;
        cnt  =  (cnt + num % 10) % 10;
        ans++;
    }
    cout << ans;
    return 0;
}