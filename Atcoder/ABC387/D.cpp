#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pll = pair<ll, ll>;

const ll dx[] = {1, -1, 0, 0};
const ll dy[] = {0, 0, 1, -1};

ll inf = 1000000000000;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll h, w;
    cin >> h >> w;
    vector<vector<char>> S(h, vector<char>(w));
    vector<vector<ll>> dist1(h, vector<ll>(w, inf));
    vector<vector<ll>> dist2(h, vector<ll>(w, inf));
    vector<vector<bool>> visited1(h, vector<bool>(w));
    vector<vector<bool>> visited2(h, vector<bool>(w));

    queue<tuple<ll, ll, char>> Q1;
    queue<tuple<ll, ll, char>> Q2;

    Pll goal;

    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            cin >> S[i][j];
        }
    }
    for (ll i = 0; i < h; i++)
    {
        for (ll j = 0; j < w; j++)
        {
            if (S[i][j] == 'G')
            {
                goal = {i, j};
            }
            if (S[i][j] == 'S')
            {
                visited1[i][j] = true;
                visited2[i][j] = true;
                // 横スタート
                for (ll v = 0; v <= 1; v++)
                {
                    ll nx = i + dx[v];
                    ll ny = j + dy[v];
                    if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1)
                    {
                        if (S[nx][ny] == '.' || S[nx][ny] == 'G')
                        {
                            visited1[nx][ny] = true;
                            dist1[nx][ny] = 1;
                            Q1.push({nx, ny, 'x'});
                        }
                    }
                }

                for (ll v = 2; v <= 3; v++)
                {
                    ll nx = i + dx[v];
                    ll ny = j + dy[v];
                    if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1)
                    {
                        if (S[nx][ny] == '.' || S[nx][ny] == 'G')
                        {
                            visited2[nx][ny] = true;
                            dist2[nx][ny] = 1;
                            Q2.push({nx, ny, 'y'});
                        }
                    }
                }
            }
        }
    }

    // xスタート

    while (!Q1.empty())
    {
        auto [x, y, c] = Q1.front();
        Q1.pop();
        if (c == 'x')
        {
            for (ll v = 2; v <= 3; v++)
            {
                ll nx = x + dx[v];
                ll ny = y + dy[v];
                if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1)
                {
                    if (visited1[nx][ny] == true)
                        continue;
                    if (S[nx][ny] == '.' || S[nx][ny] == 'G')
                    {
                        visited1[nx][ny] = true;
                        dist1[nx][ny] = dist1[x][y] + 1;
                        Q1.push({nx, ny, 'y'});
                    }
                }
            }
        }
        if (c == 'y')
        {
            for (ll v = 0; v <= 1; v++)
            {
                ll nx = x + dx[v];
                ll ny = y + dy[v];

                if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1)
                {
                    if (visited1[nx][ny] == true)
                        continue;
                    if (S[nx][ny] == '.' || S[nx][ny] == 'G')
                    {
                        visited1[nx][ny] = true;
                        dist1[nx][ny] = dist1[x][y] + 1;
                        Q1.push({nx, ny, 'x'});
                    }
                }
            }
        }
    }

    while (!Q2.empty())
    {
        auto [x, y, c] = Q2.front();
        Q2.pop();
        if (c == 'x')
        {
            for (ll v = 2; v <= 3; v++)
            {
                ll nx = x + dx[v];
                ll ny = y + dy[v];

                if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1)
                {
                    if (visited2[nx][ny] == true)
                        continue;
                    if (S[nx][ny] == '.' || S[nx][ny] == 'G')
                    {
                        visited2[nx][ny] = true;
                        dist2[nx][ny] = dist2[x][y] + 1;
                        Q2.push({nx, ny, 'y'});
                    }
                }
            }
        }
        if (c == 'y')
        {
            for (ll v = 0; v <= 1; v++)
            {
                ll nx = x + dx[v];
                ll ny = y + dy[v];

                if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1)
                {
                    if (visited2[nx][ny] == true)
                        continue;
                    if (S[nx][ny] == '.' || S[nx][ny] == 'G')
                    {
                        visited2[nx][ny] = true;
                        dist2[nx][ny] = dist2[x][y] + 1;
                        Q2.push({nx, ny, 'x'});
                    }
                }
            }
        }
    }
    auto [x, y] = goal;
    if (dist1[x][y] == inf && dist2[x][y] == inf)
        cout << -1;
    else
        cout << min(dist1[x][y], dist2[x][y]);
}
