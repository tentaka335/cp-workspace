#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD =  998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    string s = to_string(n);

    vector<ll> ten(19,1);

    for(ll i = 1;i<=18;i++) {
        ten[i] = (ten[i-1]*10);
    }
    
    
    ll digit = s.size();
    ll ans = 0;
    for(ll i = 1;i<=digit-1;i++) {
        ll temp = (ten[i] - ten[i-1])%MOD;
        ans = (ans + temp*(temp+1)/2)%MOD;
    }
    ll temp2 = (n - ten[digit-1] + 1) % MOD;
    ans = (ans + temp2*(temp2+1)/2)%MOD;

    cout << ans;
    return 0;
}