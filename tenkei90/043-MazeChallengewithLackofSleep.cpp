#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll dx[] = {1,0,-1,0};
ll dy[] = {0,1,0,-1};


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h,w;
    cin >> h >> w;
    ll rs,cs,rt,ct;
    cin >> rs >> cs >> rt >> ct;
    ll inf = 99999999999999;
    vector<vector<char>> S(h+1,vector<char>(w+1));
    vector<vector<vector<ll>>> turn(h+1,vector<vector<ll>>(w+1,vector<ll>(4,inf)));
     vector<vector<vector<bool>>> visited(h+1,vector<vector<bool>>(w+1,vector<bool>(4)));
    for(ll i = 1;i<=h;i++) {
        for(ll j = 1;j<=w;j++) {
            cin >> S[i][j];
        }
    }

    queue <tuple<ll,ll,ll>> Q;
    //bfs 
    for(ll v = 0;v<4;v++) visited[rs][cs][v] = true;
    for(ll v = 0;v<4;v++) {
        ll nx = rs + dx[v];
        ll ny = cs + dy[v];
        if(1<=nx&&nx<=h&&1<=ny&&ny<=w) {
            if(S[nx][ny] =='.') {
                visited[nx][ny][v] = true;
                Q.push({nx,ny,v});
                turn[nx][ny][v] = 0;
            }
        }
    }

    while (!Q.empty()) {
        auto [x,y,v] = Q.front();
        Q.pop();

         for(ll u = 0;u<4;u++) {
        ll nx = x + dx[u];
        ll ny = y + dy[u];
        if(1<=nx&&nx<=h&&1<=ny&&ny<=w) {
            if(S[nx][ny] =='.'&&visited[nx][ny][u] == false) {
                visited[nx][ny][u] = true;
                if(u!=v) turn[nx][ny][u] = turn[x][y][v] + 1;
                else turn[nx][ny][u] = turn[x][y][v];
                Q.push({nx,ny,u});
            }
        }
    }
        
        
    }

   /* for(ll i = 1;i<=h;i++) {
        for(ll j = 1;j<=w;j++) {
            cout << turn[i][j];
        }
        cout << "\n";
} */
    
    cout << min({turn[rt][ct][0],turn[rt][ct][1],turn[rt][ct][2],turn[rt][ct][3]}) << "\n";
}




/*
状態数を増やすということがキー
*/



