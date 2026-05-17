#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll a,b;
    cin >> a >> b;
    cout << "and" << (a & b) << endl;
    cout << "or" << (a|b) << endl;
    cout << "xor" << (a^b) << endl;
}