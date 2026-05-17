#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
ll a,b,c,d;
cin >> a >> b >> c >> d;
if (c>= a && d < b) {
    cout << "Yes" << "\n";
}
else cout << "No" << "\n";
}
