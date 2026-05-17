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
        data = vector<T>(2 * n, e);
    }
    void set(ll i, T val)
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
/*
区間取得において、演算の交換可能性を仮定した実装になっていることに注意
*/

//geminiによる実装

template <typename T> struct SegmentTree {
    using F = function<T(T, T)>;
    F op;
    T e;
    ll n;
    vector<T> data;

    SegmentTree(ll N, F op, T e) : op(op), e(e) {
        n = 1;
        while (n < N) n *= 2;
        data.assign(2 * n, e);
    }

    void set(int i, T val) {
        i += n;
        data[i] = val;
        while (i > 1) {
            i >>= 1;
            data[i] = op(data[2 * i], data[2 * i + 1]);
        }
    }

    T query(int l, int r) {
        T resL = e, resR = e;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resL = op(resL, data[l++]);
            if (r & 1) resR = op(data[--r], resR);
        }
        return op(resL, resR);
    }
};
