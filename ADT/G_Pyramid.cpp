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
    vector<ll> A(n+2);
    for(ll i = 1;i<=n;i++) cin >> A[i];
    vector<ll> left(n+2),right(n+2);
    ll ans = 1;
    for(ll i = 1;i<=n;i++) {
        left[i] = min(A[i],left[i-1]+1);
        right[n+1-i] = min(A[n+1-i],right[n+1-i+1]+1);
    }
    for(ll i = 1;i<=n;i++) chmax(ans,min(left[i],right[i]));
    
    cout << ans;
    return 0;
}