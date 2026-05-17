#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll sumA = 0,sumB = 0;
    for(ll i = 0;i<9;i++) {
        ll a;
        cin >> a;
        sumA+=a;
    }
    for(ll i = 0;i<8;i++) {
        ll b;
        cin >> b;
        sumB+=b;
    }
    cout << sumA - sumB + 1 << "\n";

}




