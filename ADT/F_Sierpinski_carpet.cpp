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
    vector<ll> pow3(n+1,1); 
    for(ll i = 1;i<=n;i++) {
        pow3[i] = pow3[i-1]*3;
    }

    vector<vector<vector<char>>> A(7,vector<vector<char>>(pow3[n],vector<char>(pow3[n],'.')));
    A[0][0][0] = '#';
    for(ll l = 1;l <=n;l++) {
        for(ll sx = 0;sx<pow3[l];sx+=pow3[l-1]) {
            for(ll sy = 0;sy<pow3[l];sy+=pow3[l-1]) {
                if(sx==pow3[l-1]&&sy==pow3[l-1]) continue;
                for(ll i = 0;i<pow3[l-1];i++) {
                    for(ll j = 0;j<pow3[l-1];j++) {
                        A[l][sx+i][sy+j] = A[l-1][i][j];
                    }
                }
            }
        }
    }

    rep(i,pow3[n]) {
        rep(j,pow3[n]) {
            cout << A[n][i][j];
        }
        cout << "\n";
    }
    return 0;
}