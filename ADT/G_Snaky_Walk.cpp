#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

const ll dx[] =  {1,-1,0,0};
const ll dy[] = {0,0,1,-1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h,w;
    cin >> h >> w;
    vector<string> S(h);
    vector<vector<bool>> visited(h,vector<bool>(w));
    vector<vector<ll>> dist(h,vector<ll>(w,inf));
    rep(i,h) {
        cin >> S[i];
    }
    ll gx,gy;
    queue<tuple<ll,ll,ll,ll>> Q;
    rep(i,h) rep(j,w) {
        if(S[i][j] == 'S') {
            Q.push({i,j,0,0});
            visited[i][j] = true;
            dist[i][j] = 0;
        }
         if(S[i][j] == 'G') {
            gx = i;
            gy = j;
        }
    }

    while(!Q.empty()) {
        auto [x,y,d,v] = Q.front();
        Q.pop();
        if(v==0) {
            for(ll u = 0;u<=1;u++) {
                ll nx = x + dx[u];
                ll ny = y + dy[u];
                if(0<=nx&&nx<=h-1&&0<=ny&&ny<=w-1) {
                    if(S[nx][ny] == '#') continue;
                    if(visited[nx][ny] == false) {
                        dist[nx][ny] = d + 1;
                        visited[nx][ny] = true;
                        Q.push({nx,ny,d+1,1});
                    }
                }
            }
        }
        if(v==1) {
            for(ll u = 2;u<=3;u++) {
                ll nx = x + dx[u];
                ll ny = y + dy[u];
                if(0<=nx&&nx<=h-1&&0<=ny&&ny<=w-1) {
                       if(S[nx][ny] == '#') continue;
                    if(visited[nx][ny] == false) {
                        dist[nx][ny] = d + 1;
                        visited[nx][ny] = true;
                        Q.push({nx,ny,d+1,0});
                    }
                }
            }
        }
    }

    vector<vector<bool>> visited1(h,vector<bool>(w));
    vector<vector<ll>> dist1(h,vector<ll>(w,inf));
  
   
    queue<tuple<ll,ll,ll,ll>> Q1;
    rep(i,h) rep(j,w) {
        if(S[i][j] == 'S') {
         
            Q1.push({i,j,0,1});
            visited1[i][j] = true;
            dist1[i][j] = 0;
        }
         if(S[i][j] == 'G') {
            gx = i;
            gy = j;
        }
    }

    while(!Q1.empty()) {
        auto [x,y,d,v] = Q1.front();
        Q1.pop();
        if(v==0) {
            for(ll u = 0;u<=1;u++) {
                ll nx = x + dx[u];
                ll ny = y + dy[u];
                if(0<=nx&&nx<=h-1&&0<=ny&&ny<=w-1) {
                    if(S[nx][ny] == '#') continue;
                    if(visited1[nx][ny] == false) {
                        dist1[nx][ny] = d + 1;
                        visited1[nx][ny] = true;
                        Q1.push({nx,ny,d+1,1});
                    }
                }
            }
        }
        if(v==1) {
            for(ll u = 2;u<=3;u++) {
                ll nx = x + dx[u];
                ll ny = y + dy[u];
                if(0<=nx&&nx<=h-1&&0<=ny&&ny<=w-1) {
                       if(S[nx][ny] == '#') continue;
                    if(visited1[nx][ny] == false) {
                        dist1[nx][ny] = d + 1;
                        visited1[nx][ny] = true;
                        Q1.push({nx,ny,d+1,0});
                    }
                }
            }
        }
    }
    
    if(dist[gx][gy]==inf&&dist1[gx][gy]==inf) { cout << - 1; return 0;}
    else (cout << min(dist[gx][gy],dist1[gx][gy]));
    return 0;
}