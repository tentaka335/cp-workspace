#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll p,q,x,y;
    cin >> p >> q >> x >> y;
    if(p<=x&&x<=p+99&&q<=y&&y<=q+99) cout << "Yes" << "\n";
    else cout << "No" << "\n";
  
}




/*
まじでやるだけ。100×100の中はp<=x<=p+99であるということに注意。
*/



