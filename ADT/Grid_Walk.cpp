#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;

ll dx[4] = {1,0,-1,0};
ll dy[4] = {0,1,0,-1};
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w;
    cin >> h >> w;
    ll sx,sy;
    cin >> sx >> sy;
    sx--;sy--;
    vector<vector<char>> C(h+9,vector<char>(w+9));    
    rep(i,h) rep(j,w) cin >> C[i][j];

    string x;
    cin >> x;
    ll  n = x.size();
    
    rep(i,n) {
        ll nx,ny;
        if(x[i]=='R') {
            nx = sx + dx[1];
            ny = sy + dy[1];
        }
        if(x[i]=='L') {
            nx = sx + dx[3];
            ny = sy + dy[3];
        }
        if(x[i]=='U') {
            nx = sx + dx[2];
            ny = sy + dy[2];
        }
        if(x[i]=='D') {
            nx = sx + dx[0];
            ny = sy + dy[0];
        }

        if(0<=nx&&nx<=h-1&&0<=ny&&ny<=w-1) {
            if(C[nx][ny] == '.') {
                sx = nx;
                sy = ny;
            }
        }

    }

    cout << sx+1 << " " << sy + 1;
        return 0;
}