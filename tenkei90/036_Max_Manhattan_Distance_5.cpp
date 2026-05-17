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
    ll n, q;
    cin >> n >> q;
    vector<ll> X(n);
    vector<ll> Y(n);
    vector<ll> Q(n);
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        X[i] = x + y;
        Y[i] = x - y;
    }
    for (ll i = 0; i < q; i++)
    {
        cin >> Q[i];
        Q[i]--;
    }
    ll maxX = *max_element(all(X));
    ll maxY = *max_element(all(Y));
    ll minX = *min_element(all(X));
    ll minY = *min_element(all(Y));
    vector<ll> ans(q);
    for (ll i = 0; i < q; i++)
    {

        ans[i] = max(ans[i], llabs(X[Q[i]] - maxX));
        ans[i] = max(ans[i], llabs(X[Q[i]] - minX));
        ans[i] = max(ans[i], llabs(Y[Q[i]] - maxY));
        ans[i] = max(ans[i], llabs(Y[Q[i]] - minY));
    }

    rep(i, q)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}