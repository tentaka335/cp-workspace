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
    
    vector<vector<ll>> A(9,vector<ll>(9));
    
    rep(i,9)rep(j,9) cin >> A[i][j];

    rep(i,9) {
        vector<bool> check(10);
        rep(j,9) {
            if(check[A[i][j]]==true) {
                cout << "No";
                return 0;
            }
            else check[A[i][j]] = true;
        }
    }

      rep(i,9) {
        vector<bool> check(10);
        rep(j,9) {
            if(check[A[j][i]]==true) {
                cout << "No";
                return 0;
            }
            else check[A[j][i]] = true;
        }
    }
    for(ll stx = 0;stx<9;stx+=3) {
        for(ll sty = 0;sty<9;sty+=3) {

        
        vector<bool> check(10);
        rep(i,3) {
            rep(j,3) {
                 if(check[A[stx+i][sty+j]]==true) {
                cout << "No";
                return 0;
            }
            else check[A[stx+i][sty+j]] = true;
                
            }
        }
    }
    }

    cout << "Yes";
    return 0;
}