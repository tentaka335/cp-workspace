#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll x, ll y) {
    if(y<x) swap(x,y);
    while(y%x!=0) {
        ll temp = y%x;
        y = x;
        x = temp;
    }
    return x;
}

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll a,b,c;
    cin >> a >> b >> c;
    ll temp2 = gcd(b,c);
    ll cube = gcd(a,temp2);

    cout << a/cube - 1 + b/cube-1 + c/cube - 1 << "\n";
}
//ans = a+b+c/gcd(a,b,c) - 3;
//キューブを切る