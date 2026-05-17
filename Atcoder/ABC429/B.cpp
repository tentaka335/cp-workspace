#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;
    vector<ll> A(n),B(n);
    
    
    ll sum = 0;
    for (ll i =0; i<n;i++) {
        cin >> A[i];
        sum += A[i];
    }

    for (ll i =0; i<n;i++) {
        if (m == sum - A[i]) {
            cout << "Yes" << "\n";
            return 0;
        }
    }

    cout << "No" << "\n"; 
    return 0;

}