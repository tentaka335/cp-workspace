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
    
    ll h,w;
    cin >> h >> w;
    vector<string> S(h);
    rep(i,h) {
        cin >> S[i];
    }
    for(ll i = 0;i<h;i++) {
        for(ll j = 0;j<w-1;j++) {
            if(S[i][j] == 'T'&&S[i][j+1] == 'T') {
                S[i][j] = 'P';
                S[i][j+1] = 'C';
            }
        }
    }
    rep(i,h) {
        cout << S[i] << "\n";
    }
    return 0;
}