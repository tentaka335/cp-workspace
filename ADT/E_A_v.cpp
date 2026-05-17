#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m;
    cin >> n >> m;
    vector<ll> A(n);
    vector<pair<ll,ll>> B;
    vector<ll> invA(m+1);
    ll maxe = 0;
    rep(i,n) {
        cin >> A[i];
        invA[A[i]]++;
        chmax(maxe,invA[A[i]]);
    }
    for(ll i = 1;i<=m;i++) {
        B.push_back({invA[i],i});
    }
    sort(all(B));
    vector<ll> C;
    C.push_back(1);
    ll nowlen = 1,nowb = 1;
    for(ll i = 1;i<m;i++) {
        if(B[i].first!=B[i-1].first) {
            C.push_back(i*(B[i].first-B[i-1].first) + 1);
        }
    }
    ll q;
    cin >> q;
    rep(qi,q) {
        ll x;
        cin >> x;
        x--;
        if(x<=n-1) {
            cout << A[x] << "\n";
        }
        else if (x+1>=m*maxe) {
            if ((x+1 - m*maxe)% m == 0) cout << m << "\n";
            else  cout << (x+1 - m*maxe)% m << "\n" ;
        }
        else {
            ll y = x+1-n;
            ll pos = lower_bound(all(C),y) - C.begin();
            if(C[pos]==y) cout << B[0].second-1 << "\n";
            else {
                pos--;
                cout << B[y - C[pos] + 1].second-1 << "\n";
            }
        }

    }
    return 0;
}