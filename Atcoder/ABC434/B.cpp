#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
   ll n,m;
   cin >> n >> m;
   vector<double> W(m+1),M(m+1);
   for (ll i = 0;i<n;i++) {
    ll a,b;
    cin >> a >> b;
    M[a]+=1;
    W[a]+=b;
   }
   for(ll i = 1;i<=m;i++) {
    double ans = W[i]/M[i];
     cout << fixed << setprecision(10);
    cout <<  ans << "\n";
   }
}