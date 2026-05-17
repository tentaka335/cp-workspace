#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    double t,l,x,y;
    cin >> t;
    cin >> l >> x >> y;
    ll q;
    cin >> q;
    vector<ll> E(q);
    for(ll i = 0;i<q;i++) cin >> E[i];
    long double pi = 3.141592653589793238462643383279;
    for(ll i = 0;i<q;i++) {
        long double y1 = l/2*cos(-2*pi*E[i]/t-pi/2);
       long double z1 = l/2*sin(-2*pi*E[i]/t-pi/2)+l/2;
        if(x == 0 && y == y1) cout << 90.0000000000 << "\n";
        else {
          long double ans = (long double)atan2(z1,sqrt((y1-y)*(y1-y)+x*x));
           cout << fixed << setprecision(10);
           cout << ans*180/pi << "\n";
        }

    }
}