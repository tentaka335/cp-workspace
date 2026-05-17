#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    ll l = s.size();
    s.erase(s.begin()+(l-1)/2);
    cout << s << endl;
}