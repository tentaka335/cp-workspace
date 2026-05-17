#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w;
    cin >> h >>w;
    
    vector<vector<char>> S(h,vector<char>(w));
    vector<vector<vector<bool>>> visited(4,vector<vector<bool>>(h,vector<bool>(w,false)));
    vector<vector<vector<ll>>> before(4,vector<vector<ll>>(h,vector<ll>(w,inf)));
    ll sx,sy,gx,gy;
    rep(i,h)rep(j,w) {
        cin >> S[i][j];
        if(S[i][j]=='S') {
            sx = i;
            sy = j;
        }
    }

    queue<tuple<ll,ll,ll>> Q;
    Q.push({0,sx,sy});
    Q.push({1,sx,sy});
    Q.push({2,sx,sy});
    Q.push({3,sx,sy});

    while(Q.empty()) {
        auto [u,x,y] = Q.front();
        Q.pop();
        rep(v,4) {
            ll nx = x +dx[v];
            ll ny = y +dy[v];
            if(0<=nx&&nx<=h-1&&0<=ny&&ny<=w-1) {
                if(visited[v][nx][ny]==false) {
                if(S[nx][ny]=='#') continue;
                if(S[x][y]=='o') {
                    if(u==v) {
                    visited[v][nx][ny] = true;
                    before[v][nx][ny] = u;
                    Q.push({v,nx,ny});
                    }
                }
                 if(S[nx][ny]=='x') {
                    if(u!=v) {
                    visited[v][nx][ny] = true;
                    before[v][nx][ny] = u;
                    Q.push({v,nx,ny});
                    }
                }
            }
            }
        }
    }
    
    return 0;
}