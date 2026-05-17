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
    vector<ll> A(n+1);
    vector<ll> ans(n+1);
    for(ll i = 1;i<=n;i++) {
        cin >> A[i];
    }
    for(ll i = n;i>=1;i--) {
        if(A[i] == i) {
            ans[i] = i;
        }
        else {
            ans[i] = ans[A[i]];
        }
    }

    for(ll i = 1;i<=n;i++) {
        cout << ans[i] << " ";
    }
    
    
    return 0;
}