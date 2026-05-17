#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k;
    cin >> n >> k;
    if ((2*n-2)%2 == k%2 && 2*n-2<= k)  cout << "Yes" << "\n";
    else cout << "No" << "\n";
}