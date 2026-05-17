#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n ;
    cin >> n;
    vector<vector<char>> A(109,vector<char>(109));
    vector<vector<char>> B(109,vector<char>(109));
    for(ll i = 1;i<=n;i++) {
        for(ll j = 1;j<=n;j++) {
            cin >> A[i][j];
        }
    }
    for(ll i = 1;i<=n;i++) {
        for(ll j = 1;j<=n;j++) {
            cin >> B[i][j];
        }
    }
     for(ll i = 1;i<=n;i++) {
        for(ll j = 1;j<=n;j++) {
            if(A[i][j]!=B[i][j]) {
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }

    
}


