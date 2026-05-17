#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
 cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> H(n);
    vector<set<ll>> A(3000);
    for(ll i = 0;i<n;i++) {
        cin >> H[i];
        A[H[i]].insert(i);
    
    }
    ll ans = 1;
    for(ll i = 1;i<=3000;i++) {
        if(A[i].size()==0) continue;
       ll nowleft = *begin(A[i]);
       ll nowdiv;
       ll beforediv;
       ll cnt = 0;
       
       for(auto s:A[i]) {
        nowdiv = s - nowleft;
        if(s!=*begin(A[i])) {
            if(nowdiv == beforediv) {
                cnt++;
                ans = max(cnt,ans);
            }
            else {
                cnt = 0;
            }
        }
        beforediv = nowdiv;
        nowleft = s;
       }
    }
    cout << ans << "\n";
}



