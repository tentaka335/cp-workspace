#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> S(n+9);
    for(ll i = 0;i<m;i++) {
        ll a,b;
        cin >> a >> b;
        S[a].push_back(b);
        S[b].push_back(a);
    }
    for(ll i =1;i<=n;i++) {
        cout << i << ": ";
        cout << "{";
        for(int j = 0;j<S[i].size();j++) {
            if(j>=1){
                cout << ", ";
            }
            cout << S[i][j];
        }
        cout << "}" <<"\n";
        }
        return 0;
    }
