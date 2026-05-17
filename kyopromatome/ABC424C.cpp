#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll H, W;
    cin >> H >> W;
    vector<string> masu(H+2);
    string s(W+2,'.');
    masu[0] = s;
    masu[H+1] = s;
    for (ll i = 1; i<=H; i++) {
    string ss;
    cin >> ss;
    masu[i] = "."+ss+".";
    }
}