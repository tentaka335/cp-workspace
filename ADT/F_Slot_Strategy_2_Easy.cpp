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
    ll m;
    cin >> m;
    vector<string> S(3);
    vector<vector<ll>> A(3,vector<ll>(10,inf));
    cin >> S[0] >> S[1] >> S[2];
    S[0] = S[0] + S[0] + S[0];
    S[1] = S[1] + S[1] + S[1];
    S[2] = S[2] + S[2] + S[2];

    rep(i,3*m)  { 
        ll a,b,c;
        a = S[0][i] - '0';
        b = S[1][i] - '0';
        c = S[2][i] - '0';
        A[0][a] = min(A[0][a],i);
        if(A[0][b]!=i&&A[2][b]!=i) {
             A[1][b] = min(A[1][b],i);
             if(A[0][c]!=i&&A[1][c] !=i) {
                A[2][c] = min(A[2][c],i);
             }
        }
    }
    
    ll ans = inf;
    rep(i,10) {
        ans = min(ans,max({A[0][i],A[1][i],A[2][i]}));
    }
    if(ans==inf) cout << -1;
    else cout << ans;
    return 0;
}