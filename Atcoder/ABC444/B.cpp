#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

     ll n,k;
    cin >> n >> k;

    
    ll ans = 0;
    for(ll j = 1;j<=n;j++) {
        string s = to_string(j);
        ll temp = 0;
    for(ll i = 0;i<s.size();i++) {
        temp += s[i] - '0';
    }
    if(temp==k)  ans++;
 
}
    cout << ans <<"\n";
}



/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/



