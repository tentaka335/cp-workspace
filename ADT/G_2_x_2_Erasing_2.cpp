#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

const ll dx[] = {0,-1,-1,0};
const ll dy[] = {0,-1,0,-1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll t;
    cin >> t;
    rep(qt,t) {
        ll h,w;
        cin >>h >> w;
        vector<string> S(h);
        vector<vector<ll>> A(h,vector<ll>(w));
        vector<vector<ll>> B(h,vector<ll>(w));
        rep(i,h) cin >> S[i];
        for(ll i = 0;i<h-1;i++) {
            for(ll j = 0;j<w-1;j++) {
                if(S[i][j]=='#'&&S[i+1][j]=='#'&&S[i][j+1]=='#'&&S[i+1][j+1]=='#') {
                    A[i][j]++;
                    A[i+1][j]++;
                    A[i][j+1]++;
                    A[i+1][j+1]++;
                    B[i][j]++;
                }
            }
        }

        
        ll cnt = 0;
        for(ll c = 4;c>=1;c--) {
            for(ll i = 0;i<h-1;i++) {
                for(ll j = 0;j<w-1;j++) {
                    if(A[i][j] == c) {
                        cnt++;
                        rep(v,4) {
                            ll ni = i + dx[v];
                            ll nj = j + dy[v];
                            if(0<=ni&&ni<=h-1&&0<=nj&&nj<=w-1) {
                                if(B[ni][nj]==1) {
                                    A[ni][nj]--;
                                    A[ni+1][nj]--;
                                    A[ni][nj+1]--;
                                    A[ni+1][nj+1]--;
                                    B[ni][nj] = 0;
                            }
                            
                            }
                            
                        }
                      
                    }
                }
            }
        }

        cout << cnt << "\n";
    }
    
    return 0;
}