
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> Grit(h);
    for (int i = 0; i < h; i++) cin >> Grit[i];

    // 1. 磁石の隣のマスを 'x' に変える
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (Grit[i][j] == '#') {
                for (int k = 0; k < 4; k++) {
                    int nex = i + dx[k];
                    int ney = j + dy[k];
                    if (0 <= nex && nex < h && 0 <= ney && ney < w) {
                        if (Grit[nex][ney] == '.') Grit[nex][ney] = 'x';
                    }
                }
            }
        }
    }

    vector<vector<int>> visited(h, vector<int>(w, 0));
    ll ans = 1;

    // 2. BFS で探索
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            // '.' (自由に動けるマス) から探索開始
            if (visited[i][j] == 0 && Grit[i][j] == '.') {
                queue<pair<int, int>> Q;
                vector<pair<int, int>> touched_x; // 今回の探索で触れた 'x' マスを記録
                
                Q.push({i, j});
                visited[i][j] = 1;
                ll current_component_size = 0;

                while (!Q.empty()) {
                    auto [x, y] = Q.front();
                    Q.pop();
                    current_component_size++;

                    for (int k = 0; k < 4; k++) {
                        int nex = x + dx[k];
                        int ney = y + dy[k];

                        if (0 <= nex && nex < h && 0 <= ney && ney < w) {
                            if (Grit[nex][ney] == '.' && visited[nex][ney] == 0) {
                                visited[nex][ney] = 1; // ここで訪問済みにする！
                                Q.push({nex, ney});
                            } 
                            else if (Grit[nex][ney] == 'x' && visited[nex][ney] == 0) {
                                // 'x' は今の BFS 中は二度と数えないが、別の BFS では使いたい
                                visited[nex][ney] = 1; 
                                touched_x.push_back({nex, ney});
                                current_component_size++;
                            }
                        }
                    }
                }

                // 今回の BFS で使った 'x' マスだけ、visited を 0 に戻す
                for (auto p : touched_x) {
                    visited[p.first][p.second] = 0;
                }
                
                ans = max(ans, current_component_size);
            }
        }
    }

    // 最後に 1 回だけ出力！
    cout << ans << endl;

    return 0;
} 



