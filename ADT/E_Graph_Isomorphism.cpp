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
    vector<ll> P(n);
    rep(i,n) P[i] = i;
    vector<set<ll>> G1(n);
    vector<set<ll>> G2(n);
    rep(i,m) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G1[a].insert(b);
        G1[b].insert(a);
    }
      rep(i,m) {
        ll c,d;
        cin >> c >> d;
        c--;d--;
        G2[c].insert(d);
        G2[d].insert(c);
    }
    do {
        bool ok = true;
    for(ll i = 0;i<n;i++) {
        for(ll j = i;j<n;j++) {
            
            if(G1[i].count(j)) {
                if(!G2[P[i]].count(P[j])) {
                    ok = false;
                }
            }
            else {
                 if(G2[P[i]].count(P[j])) {
                    ok = false;
                }
            }
        }
    }

    if(ok == true) {
        cout << "Yes";
        return 0;
    }

    } while(next_permutation(all(P)));


    cout << "No";
    
    return 0;
}