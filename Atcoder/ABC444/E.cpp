#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

// Segment tree that returns (min, max) on [l, r) in O(log N)
struct SegTreeMinMax {
    int n;
    vector<ll> mn, mx;

    SegTreeMinMax() = default;

    explicit SegTreeMinMax(const vector<ll> &a) { build(a); }

    void build(const vector<ll> &a) {
        int sz = (int)a.size();
        n = 1;
        while (n < sz) n <<= 1;
        mn.assign(2 * n, (ll)4e18);
        mx.assign(2 * n, (ll)-4e18);
        for (int i = 0; i < sz; i++) {
            mn[n + i] = a[i];
            mx[n + i] = a[i];
        }
        for (int i = n - 1; i >= 1; i--) {
            mn[i] = std::min(mn[i << 1], mn[i << 1 | 1]);
            mx[i] = std::max(mx[i << 1], mx[i << 1 | 1]);
        }
    }

    // Query on [l, r) (0-indexed). Returns {min, max}.
    Pll query(int l, int r) const {
        ll res_min = (ll)4e18;
        ll res_max = (ll)-4e18;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res_min = std::min(res_min, mn[l]);
                res_max = std::max(res_max, mx[l]);
                l++;
            }
            if (r & 1) {
                --r;
                res_min = std::min(res_min, mn[r]);
                res_max = std::max(res_max, mx[r]);
            }
        }
        return {res_min, res_max};
    }

    // Point update: a[idx] = val
    void update(int idx, ll val) {
        int k = n + idx;
        mn[k] = mx[k] = val;
        for (k >>= 1; k >= 1; k >>= 1) {
            mn[k] = std::min(mn[k << 1], mn[k << 1 | 1]);
            mx[k] = std::max(mx[k << 1], mx[k << 1 | 1]);
        }
    }
};







int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // Input format example:
    // n q
    // a0 a1 ... a{n-1}
    // q lines of l r (0-indexed, half-open [l, r))
    ll n, d;
    if (!(cin >> n >> d)) return 0;
    vector<ll> A(n);
    for (ll i = 0; i < n; i++) cin >> A[i];

    SegTreeMinMax seg(A);

   /* while (q--) {
        int l, r;
        cin >> l >> r;
        auto [mn, mx] = seg.query(l, r);
        cout << mn << ' ' << mx << '\n';
    }
        */
    ll left = 0,right = 0;

    ll ans = 0;
    while(left<n&&right<n) {
        auto [mn,mx]= seg.query(left,right+1);
        if(mx-mn<d) {
            ans++;
            right++;
        }
        else {
        
            left++;
        }
    }
    cout << ans << "\n";
}



/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/



