#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<vector<char>> S(n+1,vector<char>(n+1));
    vector<vector<char>> T(m+1,vector<char>(m+1));
    for(ll i = 1;i<=n;i++) {
        for(ll j = 1;j<=n;j++) cin >> S[i][j];
    }

    for(ll i = 1;i<=m;i++) {
        for(ll j = 1;j<=m;j++) cin >> T[i][j];
    }

    for(ll a = 1;a<= n-m + 1;a++) {
        for(ll b = 1;b<=n-m+1;b++) {
            bool ok = true;
            for(ll i = 1;i<=m;i++) {
                for(ll j = 1;j<=m;j++) {
                    if(S[a+i-1][b+j-1] != T[i][j]) {
                        ok = false;
                        break;
                    }
                }
                if(ok == false) break;
            }
            if(ok == true) {
                cout << a << " " <<  b << "\n";
                return 0;
            }
        }
    }
}


