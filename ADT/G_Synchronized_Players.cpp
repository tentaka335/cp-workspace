#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template <class T>
bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

ll dx[] = {1, 0, -1, 0};
ll dy[] = {0, 1, 0, -1};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<string> S(n);
    rep(i, n) cin >> S[i];
    vector<pair<ll, ll>> start;
    rep(i, n) rep(j, n)
    {
        if (S[i][j] == 'P')
        {
            start.push_back({i, j});
        }
    }
    ll ans = inf;
    vector<vector<bool>> visited0(n, vector<bool>(n));
    vector<vector<bool>> visited1(n, vector<bool>(n));
    vector<vector<ll>> dist0(n, vector<ll>(n, inf));
    vector<vector<ll>> dist1(n, vector<ll>(n, inf));
    queue<pair<ll, ll>> Q0;
    queue<pair<ll, ll>> Q1;

    ll x0 = start[0].first, y0 = start[0].second;
    Q0.push({x0, y0});
    visited0[x0][y0] = true;
    dist0[x0][y0] = 0;
    while (!Q0.empty())
    {
        auto [x, y] = Q0.front();
        Q0.pop();
        rep(v, 4)
        {
            ll nx = x + dx[v];
            ll ny = y + dy[v];
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (S[nx][ny] != '#' && visited0[nx][ny] == false)
                {
                    dist0[nx][ny] = dist0[x][y] + 1;
                    visited0[nx][ny] = true;
                    Q0.push({nx, ny});
                }
            }
        }
    }

        ll x1 = start[1].first, y1 = start[1].second;
        Q1.push({x1, y1});
        visited1[x1][y1] = true;
        dist1[x1][y1] = 0;
        while (!Q1.empty())
        {
            auto [x, y] = Q1.front();
            Q1.pop();
            rep(v, 4)
            {
                ll nx = x + dx[v];
                ll ny = y + dy[v];
                if (0 <= nx && nx < n && 0 <= ny && ny < n)
                {
                    if (S[nx][ny] != '#' && visited1[nx][ny] == false)
                    {
                        dist1[nx][ny] = dist1[x][y] + 1;
                        visited1[nx][ny] = true;
                        Q1.push({nx, ny});
                    }
                }
            }
        }

            for (ll gx = 0; gx < n; gx++)
            {
                for (ll gy = 0; gy < n; gy++)
                {
                    if (S[gx][gy] != '#')
                    {
                        if (dist0[gx][gy] % 2 == dist1[gx][gy] % 2)
                        {
                            chmin(ans, max(dist0[gx][gy], dist1[gx][gy]));
                        }
                    }
                }
            }
        
    
    if (ans == inf)
        cout << -1;
    else
        cout << ans;
    return 0;
}