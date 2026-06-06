#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll, ll>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using Graph = vector<vector<ll>>;
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
const ll MOD2 = 998244353;
const ll dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
const ll dy[8] = {0, 0, 1, -1, 1, 1, -1, -1};

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll h, w;
    cin >> h >> w;
    vector<string> S(h + 9);
    rep(i, h) cin >> S[i];

    set<Pll> B, W;

    rep(i, h) rep(j, w)
    {
        if (S[i][j] == '.')
            W.insert({i, j});
        else
            B.insert({i, j});
    }

    vector<ll> bdist(1000009, inf);
    vector<ll> wdist(1000009, inf);

    auto ttoo = [&](ll i, ll j)
    {
        return w * i + j;
    };//こんな関数いらん

        priority_queue<Pll, vector<Pll>, greater<Pll>> Q;

        for (auto p : B)
        {
            bdist[ttoo(p.first, p.second)] = 0;
            Q.push({0, ttoo(p.first, p.second)});
        }

        while (!Q.empty())
        {
            auto [c, p] = Q.top();
            Q.pop();
            ll x = p / w;
            ll y = p % w;
            if (bdist[w * x + y] < c)
                continue;
            rep(u, 8)
            {
                ll nx = x + dx[u];
                ll ny = y + dy[u];
                if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1)// in(x,y)を作る
                {
                    if (c + 1 < bdist[ttoo(nx, ny)])
                    {
                        bdist[ttoo(nx, ny)] = c + 1;
                        Q.push({bdist[ttoo(nx, ny)], ttoo(nx, ny)});
                    }
                }
            }
        }



        for (auto p : W)
        {
            wdist[ttoo(p.first, p.second)] = 0;
            Q.push({0, ttoo(p.first, p.second)});
        }

        while (!Q.empty())
        {
            auto [c, p] = Q.top();
            Q.pop();
            ll x = p / w;
            ll y = p % w;
            if (wdist[w * x + y] < c)
                continue;
            rep(u, 8)
            {
                ll nx = x + dx[u];
                ll ny = y + dy[u];
                if (0 <= nx && nx <= h - 1 && 0 <= ny && ny <= w - 1)
                {
                    if (c + 1 < wdist[ttoo(nx, ny)])
                    {
                        wdist[ttoo(nx, ny)] = c + 1;
                        Q.push({wdist[ttoo(nx, ny)], ttoo(nx, ny)});
                    }
                }
            }
        }



        rep(i,h) {
            rep(j,w) {
                bool isblack;
                ll pos = i*w+j;
                if(S[i][j]=='.') {
                    if(bdist[pos]==inf) {
                        isblack = false;
                    }
                    else{
                        if(bdist[pos]%2==0) {
                            isblack = true;
                        }
                        else{
                            isblack = false;
                        }
                    }
                    
                }
                else {
                    if(wdist[pos]==inf) {
                        isblack = false;
                    }
                    else {
                        if(wdist[pos]%2==1) {
                            isblack = true;
                        }
                        else {
                            isblack = false;
                        }
                    }

                }
                cout << (isblack?'#':'.') ;
            }
            cout << "\n";
        }
        
    
        return 0;
    }