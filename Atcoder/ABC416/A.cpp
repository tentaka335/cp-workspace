#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,l,r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    for (ll i = l-1;i<=r-1;i++) {
      if(s[i] !='o') {
        cout << "No" << "\n";
        return 0;
      }
    }
   cout << "Yes"<< "\n";
}