#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<vector<ll>> A(200,vector<ll>(200,99999));
    A[0][(n-1)/2] = 1;
    ll r = 0;
    ll k = 1;
    ll c = (n-1)/2;
    for(ll i = 1;i<n*n;i++) {
        if(A[(r-1+n)%n][(c+1)%n] == 99999) {
            A[(r-1+n)%n][(c+1)%n] = k+1;
            r = (r-1+n)%n;
            c = (c+1)%n;
            k = k+1;
        }
        else {
            A[(r+1)%n][c] = k + 1;
            r = (r+1)%n;
            k = k+1;
        }
    }
    for(ll i = 0;i<n;i++) {
        for(ll j = 0;j<n;j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}