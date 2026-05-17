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
    
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n);
    map<ll,ll> B;
    ll ans = 0;
    vector<ll> C;
    rep(i,n) {
        cin >> A[i];
        ans+= A[i];
        B[A[i]]++;
    }
    for(auto p:B) {
        auto [key,v] = p;
        C.push_back(key*v);
    }
    sort(C.rbegin(),C.rend());
    for(ll i = 0;i<k&&i<C.size();i++) {
        ans-=C[i];
    }
    cout << ans;
    return 0;
}