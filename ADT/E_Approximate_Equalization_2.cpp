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
    vector<ll> A(n);
    ll asum = 0;
    rep(i,n) {
        cin >> A[i];
        asum+=A[i];
    }
    ll k = asum/n;
    ll b = asum - k*n;
    ll ans = 0;
        sort(all(A));
        ll cnt = 0;
        rep(i,n) {
            
            if(i<n-b) cnt += llabs( k - A[i]);
            else cnt += llabs(k+1 - A[i]);
        }
        ans = cnt/2;
        cout << ans;
    
}
    