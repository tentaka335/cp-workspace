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
    
    ll n;
    cin >> n;
    vector<ll> A(n+1);
    vector<ll> B(n+1);
    rep(i,n) {
        cin >> A[i+1] >> B[i+1];
    }
    ll m;
    cin >> m;
    vector<vector<set<char>>> S(11,vector<set<char>>(11));
    vector<string> strings(m+1);
    for(ll i = 1;i<=m;i++) {
        cin >> strings[i];
        ll len = strings[i].size();
        rep(j,len) {
            S[len][j+1].insert(strings[i][j]);
        }
    }
    for(ll i = 1;i<=m;i++) {
        bool ok = true;
        if(strings[i].size()!=n) {
            cout <<"No"<<"\n";
            continue;
        }
        for(ll j = 1;j<=n;j++) {
            char c = strings[i][j-1];
            if(!S[A[j]][B[j]].count(c)) {
                ok = false;
            }
        }
        cout <<(ok?"Yes":"No") << "\n";
    }
    return 0;
}