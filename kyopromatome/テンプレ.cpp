#include <bits/stdc++.h>
using namespace std;
#define rep (i,a,b) for (ll i = a;i<b;i++)
using ll = long long;



int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
  vector<ll> A={1,2,3,5,4};
   for (ll i = 0 ; i<5;i++) cout << A[i] << " ";
   cout << "\n";
  sort(A.begin(),A.end());
  for (ll i = 0 ; i<5;i++) cout << A[i] << " ";
}
