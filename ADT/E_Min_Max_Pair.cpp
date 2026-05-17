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
    vector<ll> used(n+1);
     ll samesum = 0;
    for(ll i = 1;i<=n;i++) {
        cin >> A[i];
        if(i == A[i]) {
             samesum++;
             used[i] = true;
        }
    }
    ll ans  = 0;
    for(ll i = 1;i<=n;i++) {
        if(used[i]==false) {
            if(i==A[A[i]]&&used[A[i]] == false) {
                ans++;
                used[i] = true;
                used[A[i]] = true;
            }
        }
    }
    ans += samesum*(samesum-1)/2;
    cout << ans;
   

    
    
    return 0;
}