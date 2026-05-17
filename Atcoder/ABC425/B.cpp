#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
   ll n;
   cin >> n;
   vector<ll> A(n),P(n);
   for (ll &i:A) cin >> i;
 iota(P.begin(),P.end(),1);
   do {
    bool ok = true;
    for (ll i=0; i<n;i++) {
        ok &= A[i] ==-1 || A[i] == P[i];
    }
    if (ok) {
        cout << "Yes" << "\n";
        for (ll i=0;i<n;i++) {
            cout << P[i] << " ";
        }
        return 0;
    }
   } while(next_permutation(P.begin(),P.end()));
   cout << "No" << endl;
   return 0;
}
