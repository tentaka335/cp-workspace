#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll d,f;
    cin >> d >> f;
    ll k = f;
    while (k<=d) {
        k+=7;
    }
    cout << k%d<< "\n";
}