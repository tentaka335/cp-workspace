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
    
    ll n, q;
    cin >> n >> q;
    vector<ll> A(n+1);
    vector<ll> B(n+1);
    
    for(ll i = 1;i<=n;i++) {
        A[i] = i;
        B[i] = i;
    }
    rep(qi,q) {
        ll x;
        cin >> x;
        if(B[x]==n) {
            swap(A[B[x]],A[B[x]-1]);
           B[A[B[x]]]++;
           B[x]--;
        }
        else {
            swap(A[B[x]],A[B[x]+1]);
           B[A[B[x]]]--;
           B[x]++;
        }
    }
    for(ll i = 1;i<=n;i++) cout << A[i] << " ";
    return 0;
}