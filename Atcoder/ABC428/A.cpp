#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll s,a,b,x,ans=0;
    cin >> s >> a >> b >> x;
     ll d=x/(a+b);
    ans +=d*s*a;
    ll c=x-d*(a+b);
    if (c>=a) ans += s*a;
    else ans += c*s;

    cout << ans << endl;
    
}