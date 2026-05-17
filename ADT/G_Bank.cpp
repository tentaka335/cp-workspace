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
    
    ll n,q;
    cin >> n >> q;
    priority_queue<ll,vector<ll>,greater<ll>> Q;
    vector<bool> visited(n+1);
    ll coolednum = 0;
    rep(qi,q) {
        ll qt;
        cin >> qt;

        if(qt==1) {
            coolednum++;
            Q.push(coolednum);
        }
        if(qt==2) {
            ll x;
            cin >> x;
            visited[x] = true;
        }
        if(qt==3) {
            while(true) {
               ll x = Q.top();
                if(visited[x] == false) {
                    cout << x << "\n";
                    break;
                }
                else {
                    Q.pop();
                }

            }
        }
    }
    
    return 0;
}