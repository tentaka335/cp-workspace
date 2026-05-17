#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    map<ll,ll> num;
    vector<ll> ans;
    for(ll y = 2;y*y<=n-1;y++) {
        for(ll x = 1;x*x<=n-4;x++) {
            if(x>=y) break;
            if(x*x+y*y<=n&&x<y) {
                if(!num.count(x*x+y*y)) num[x*x+y*y] = 1;
                else num[x*x+y*y] +=1;
            }
        }
    }
    for(auto p : num) {
        if(p.second==1) ans.push_back(p.first);
    }
    cout << ans.size() << "\n";
    for(ll i = 0;i<ans.size();i++) cout << ans[i] << " ";
}