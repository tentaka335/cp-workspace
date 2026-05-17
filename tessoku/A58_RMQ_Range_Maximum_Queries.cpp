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

/*
struct SegmentTree
{
    function<ll(ll, ll)> op;
    ll e;
    ll n;
    vector<ll> data;
    SegmentTree(int N, function<ll(ll, ll)> op, ll e) : op(op), e(e)
    {
        // TODO
        n = 1;
        while (n < N)
            n *= 2;
        data = vector<ll>(2 * n, e);
    }
    void set(ll i, ll val)
    {
        i += n;
        data[i] = val;
        while (i > 1)
        {
            i /= 2;
            data[i] = op(data[2 * i], data[2 * i + 1]);
        }
    }
    ll query(ll l, ll r)
    {
        l += n;
        r += n;
        ll res = e;
        while (l<r)
        {
            if (l % 2 == 0)
            {
                l /= 2;
            }
            else
            {
                res = op(res, data[l]);
                l = l / 2 + 1;
            }
            if (r % 2 == 0)
            {
                r /= 2;
            }
            else
            {
                res = op(res, data[r - 1]);
                r = r / 2;
            }
        }

        return res;
    }
};
*/
template <typename T > struct SegmentTree
{
    function<T(T, T)> op;
    T e;
    ll n;
    vector<T> data;
    SegmentTree(ll N, function<T(T, T)> op, T e) : op(op), e(e)
    {
        // TODO
        n = 1;
        while (n < N)
            n *= 2;
        data = vector<ll>(2 * n, e);
    }
    void set(T i, T val)
    {
        i += n;
        data[i] = val;
        while (i > 1)
        {
            i /= 2;
            data[i] = op(data[2 * i], data[2 * i + 1]);
        }
    }
    T query(ll l, ll r)
    {
        l += n;
        r += n;
        T res = e;
        while (l<r)
        {
            if (l % 2 == 0)
            {
                l /= 2;
            }
            else
            {
                res = op(res, data[l]);
                l = l / 2 + 1;
            }
            if (r % 2 == 0)
            {
                r /= 2;
            }
            else
            {
                res = op(res, data[r - 1]);
                r = r / 2;
            }
        }

        return res;
    }
};



int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    SegmentTree<ll> ST(n,[](ll a,ll b){return max(a,b);},0); 
    rep (i,q) {
        ll qt,x,y;
        cin >> qt >> x >> y;

        if(qt == 1) {
            x--;
            ST.set(x,y);
        }
        if(qt == 2) {
            x--;
            y--;
            cout << ST.query(x,y) << "\n";
        }
    }
}