#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string s;


    cin >> s;
    ll num = s[0]-'0';
    ll count = 1;
    vector<pair<ll,ll>> lanlength;
    for(ll i = 1;i<s.size();i++) {
        if(num==s[i]-'0') count++;
        else {
            lanlength.push_back(make_pair(num,count));
            num = s[i]-'0';
            count = 1;
        }
    }
     lanlength.push_back(make_pair(num,count));
    ll ans = 0;
    for(ll i = 0;i<lanlength.size()-1;i++) {
        if(lanlength[i].first+1==lanlength[i+1].first) {
            ans +=min(lanlength[i].second,lanlength[i+1].second);
        }
    }
    cout << ans << "\n";
}