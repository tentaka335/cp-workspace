#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll, ll>;

ll pow9p7 = 1000000007;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll h, w, n;
    cin >> h >> w >> n;

    set<Pll> H;
    set<Pll> W;
    vector<Pll> HW(n + 1);
    vector<bool> used(n + 1);
    vector<Pll> ans(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        ll temph, tempw;
        cin >> temph >> tempw;
        H.insert(make_pair(temph, i));
        W.insert(make_pair(tempw, i));
        HW[i] = {temph, tempw};
    }

    ll bh = h, bw = w;
    ll nx = 1, ny = 1;
    ll leftblock = n;
    while (leftblock >= 1)
    {
        // hが同じやつを探す
        bool hfind = false;
        auto ith = H.lower_bound(make_pair(bh, 0));
        if (ith == H.end())
        {
        }
        else
        {
            while (true)
            {
                if (ith == H.end())
                {
                    break;
                }
                ll nh = ith->first;
                ll blonum = ith->second;
                if (nh != bh)
                {
                    break; // 全部使い切ってしまった。
                }

                else
                { // hがbhと同じやつを盤面において、次を探す。
                    used[blonum] = true;
                    ans[blonum] = {nx, ny};
                    bw = bw - HW[blonum].second;
                    ny = ny + HW[blonum].second;
                    hfind = true;
                    leftblock--;
                    H.erase(make_pair(HW[blonum].first, blonum));
                    W.erase(make_pair(HW[blonum].second, blonum));

                    break;
                }
            }
        }

        if (hfind == true)
            continue;

        // wが同じやつを探す

        auto itw = W.lower_bound(make_pair(bw, 0));
        if (itw == W.end())
        {
        }
        else
        {
            while (true)
            {
                if (itw == W.end())
                {
                    break;
                }
                ll nw = itw->first;
                ll blonum = itw->second;
                if (nw != bw)
                {
                    break; // 全部使い切ってしまった。
                }

                else
                { // hがbhと同じやつを盤面において、次を探す。
                    used[blonum] = true;
                    ans[blonum] = {nx, ny};
                    bh = bh - HW[blonum].first;
                    nx = nx + HW[blonum].first;
                    leftblock--;
                    H.erase(make_pair(HW[blonum].first, blonum));
                    W.erase(make_pair(HW[blonum].second, blonum));

                    break;
                }
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/

/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/
