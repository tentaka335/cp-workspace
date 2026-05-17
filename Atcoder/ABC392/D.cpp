#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> K(n+1);
    vector<map<ll,ll>> A(n+1);
    for(ll i = 1;i<=n;i++) {
        cin >> K[i];
        for(ll j = 0;j<K[i];j++) {
            ll a;
            cin >> a;
            if(!A[i].count(a)) A[i][a] = 1;
            else A[i][a] +=1;
        }
    }
    double ans = 0;
    for(ll i = 1;i<=n-1;i++) {
        for(ll j = i+1;j<=n;j++) {
            ll samesum = 0;
            for(auto a:A[i]) {
                if(!A[j].count(a.first)) continue;
                else samesum += A[i][a.first]*A[j][a.first];
            }
            double nowans = (double)samesum/((double)(K[i]*K[j]));
            ans = max(nowans,ans);
        }
    }
      cout << fixed << setprecision(20);
    cout << ans << "\n";
}



