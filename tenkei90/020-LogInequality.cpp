#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
   ll a,b,c;
   cin >> a >> b >> c;
   ll k = 1;
   for(ll i = 0;i<b;i++) {
    k *=c;
   }
   cout << (a<k?"Yes":"No") << "\n";

}