#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    ll len = s.size();
    double ans = 0;
    for (ll i = 0; i<len;i++) {
        for (ll j=1;j<=len-i;j++) {
            string subs = s.substr(i,j);
            if (subs.size()>=3 && subs[0] == 't' && subs[subs.size()-1] == 't') {
                ll count = 0;
                for ( ll k = 0; k <= subs.size()-1; k++) {
                    if(subs[k] == 't') count++;
                }
                double bunbo = subs.size()-2;
                double bunsi = count - 2;
                double semians = bunsi/bunbo;
                ans =max(ans,semians);
            }
        }
    }
    cout << fixed << setprecision(15);
    cout << ans << "\n";
}
