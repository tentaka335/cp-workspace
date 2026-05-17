#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
  string d;
  cin >> d;
  for(ll i = 0;i<d.size();i++) {
    if(d[i]=='S') cout << "N";
    if(d[i]=='N') cout << "S";
    if(d[i]=='E') cout << "W";
    if(d[i]=='W') cout << "E";
  }
  cout << "\n";
}


