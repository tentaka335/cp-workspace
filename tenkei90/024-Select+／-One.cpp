#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    vector<ll> A(n),B(n);
    ll dif = 0;
    for(ll i = 0;i<n;i++) {
        cin >> A[i];
    }
    for(ll i = 0;i<n;i++) {
        cin >> B[i];
        dif+=llabs(A[i]-B[i]);
    }
    if(dif<=k&&(dif%2==k%2)) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}
//ans = a+b+c/gcd(a,b,c) - 3;
//キューブを切る