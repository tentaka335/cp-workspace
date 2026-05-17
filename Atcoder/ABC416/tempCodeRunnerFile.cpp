#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
   string s;
   cin >> s ;
   string t;
   bool circable = true;
   for (ll i = 0;i<s.size();i++) {
    if (s[i] == '#') {
        t+='#';
        circable = true;
    }
    else {
        if (circable) {
            t+= 'o';
            circable = false;
        }
        else t+= '.';
    }
   }
   cout << t << "\n";
}
