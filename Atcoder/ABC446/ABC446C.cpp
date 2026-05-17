
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

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    for (ll ti = 0; ti < t; ti++)
    {
        ll n, d;
        cin >> n >> d;
        vector<ll> A(n + 1);
        vector<ll> B(n + 1);
        for (ll i = 1; i <= n; i++)
        {
            cin >> A[i];
        }
        for (ll i = 1; i <= n; i++)
        {
            cin >> B[i];
        }

        queue<pair<ll, ll>> Q;
        for (ll i = 1; i <= n; i++)
        {
            // asa
            Q.push({A[i], i});
        

            //昼
            ll b = B[i];
            while (b != 0)
            {
                if (Q.front().first >= b)
                {
                    Q.front().first -= b;
                    if (Q.front().first == 0)
                    {
                        Q.pop();
                    }
                    break;
                }
                else
                {
                    b -= Q.front().first;
                    Q.pop();
                }
            }
            //yoru
                while (i - Q.front().second >= d &&!Q.empty())
                {
                    Q.pop();
                }
            
        }
        ll ans = 0;
        while (!Q.empty())
        {
            ans += Q.front().first;
            Q.pop();
        }
        cout << ans << "\n";
    }

    return 0;
}