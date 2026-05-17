#include <bits/stdc++.h>
using namespace std;
using ll = long long;



const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h,w;
    cin >> h >> w;
    vector<vector<char>> maze(h+9,vector<char>(w+9,'#'));
    
    for(ll i = 1;i<=h;i++) {
        for(ll j = 1;j<=w;j++) {
            char s;
            cin >> s;
            maze[i][j] = s;
        }
    }
    map<char,set<pair<ll,ll>>> tp;
     map<char,bool> done;
    for(ll i = 1;i<=h;i++) {
        for(ll j =1;j<=w;j++) {
            if(maze[i][j] !='#' && maze[i][j] !='.') {
                if(!tp.count(maze[i][j])) {
                    tp[maze[i][j]] = {make_pair(i,j)};
                    done[maze[i][j]] = false;
                }
                else tp[maze[i][j]].insert(make_pair(i,j));
            }

    }
}
    queue<pair<ll,ll>> Q;
    vector<vector<ll>> dist(h+9, vector<ll>(w+9, -1));

    Q.push({1,1});
    dist[1][1] = 0;

    while(!Q.empty()) {
        pair<ll,ll> pos = Q.front();
        ll x = pos.first;
        ll y = pos.second;
        Q.pop();
        if(maze[x][y] !='#' && maze[x][y] !='.' && done[maze[x][y]] == false) {

            done[maze[x][y]] = true;
        
            for(pair<ll,ll> nex : tp[maze[x][y]]) {
               ll nx =  nex.first;
               ll ny =  nex.second;
               if(dist[nx][ny] == -1) {
               dist[nx][ny] = dist[x][y] + 1;
               Q.push(nex);
            }
            }
        }

             for (int dir = 0; dir < 4; ++dir) {
            int x2 = x + dx[dir];
            int y2 = y + dy[dir];
            
      
            
            // 新たなマスが壁の場合はダメ
            if (maze[x2][y2] == '#') continue;
            
            // 新たなマスが訪問済みの場合はスキップ
            if (dist[x2][y2] != -1) continue;
            
            // 新たなマスを訪問する
            Q.push({x2, y2});
            dist[x2][y2] = dist[x][y] + 1;
        }
        }
        cout << dist[h][w] << "\n";
    }


