#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n+1,1);
    if(n < k) {
        cout << 1 << "\n";
        return 0;
    }
    A[k] = k;

    for(ll i = 0;(k+i+1)<=n;i++) {
        A[k+i+1] = (2*A[k+i] - A[i])%1000000000;
    }
    cout << (A[n]+1000000000)%1000000000 << "\n";
}

