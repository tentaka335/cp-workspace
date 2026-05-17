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
    
    ll t;
    cin >> t;
    rep(ti,t) {
        ll n,d;
        cin >> n >> d;
        vector<ll> A(n);
        vector<ll> B(n);
        rep(i,n) cin >> A[i];
        rep(i,n) cin >> B[i];
        queue<ll> Q;
        rep(i,n) {
            rep(a,A[i]) Q.push(i);
            rep(b,B[i]) Q.pop();
            while(!Q.empty()) {
            if(i - Q.front() >=d) Q.pop();
            else break;
            }
        }
        
        
        ll ans = Q.size();
      
        cout << ans << "\n";
    }
    
    return 0;

}