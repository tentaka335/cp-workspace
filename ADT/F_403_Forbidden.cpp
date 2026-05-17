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
    
    ll n , m ,q;
    cin >> n >> m >> q;
    vector<set<ll>> S(n);
    vector<bool> ismaster(n);
    
    rep(qi,q) {
        ll qt;
        cin >> qt;
        if(qt==1) {
            ll x,y;
            cin >> x >> y;
            x--;
            S[x].insert(y);
        }
        else if(qt==2) {
            ll x;
            cin >> x;
            x--;
            ismaster[x] = true;
        }
        else {
            ll x,y;
            cin >> x >> y;
            x--;
            if(S[x].count(y)||ismaster[x]) {
                cout << "Yes" <<"\n";
            }
            else cout << "No" << "\n";
        }
    }
    
    return 0;
}