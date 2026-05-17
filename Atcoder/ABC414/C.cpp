#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll a,n;    cin >> a >> n;
    vector<ll> kaibun;
       for(ll j = 0;j<=9;j++) if(j<=n) kaibun.push_back(j);
    for(ll i = 1;i< 1000000;i++) {
        string s,s2;
        s = to_string(i);
        s2 = s;
        reverse(s2.begin(),s2.end());
        ll res = stol(s+s2);
        if(res>n) break;
        kaibun.push_back(res);
        for(ll j = 0;j<=9;j++) {
           ll res = stol(s+to_string(j)+s2);
             if(res<=n) kaibun.push_back(res);
        }
    }
    auto asinsuu = [] (ll i,ll j) {
        string res = "";
        while(i!=0) {
            res = to_string(i%j) + res;
            i /=j;
        }
        return res;
    };
    auto iskaibun = [] (string s) {
        ll len ;
        if(s.size()%2==0) len = s.size()/2;
        else len = s.size()/2+1;
        for(ll i = 0;i<len;i++) {
            if(s[i] != s[s.size()-1-i]) return false;
        }
        return true;
    };
    ll ans = 0;
    for(ll j = 0;j<kaibun.size();j++) {
        string s = asinsuu(kaibun[j],a);
        /*cout << s << ":";*/
        if(iskaibun(s)) {
            ans+=kaibun[j];
            //cout << kaibun[j] << " ";
        }
    }
    cout << ans << "\n";
    return 0;
 }
