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
    
    ll n,m,k;
    cin >> n >> m >> k;
    vector<ll> H(n);
    vector<ll> B(m);
    rep(i,n) {
        cin >> H[i];
    }
    rep(i,m) {
        cin >> B[i];
    }
    sort(all(H));
    sort(all(B));
    for(ll i = 0;i<k;i++) {
        if(H[i]>B[m-k + i]) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}