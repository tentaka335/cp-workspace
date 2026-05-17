#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;

ll pow9p7 = 1000000007;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<string> S(n);
    ll maxlen = 0;
    for(ll i = 0;i<n;i++) {
        cin >> S[i];
        ll len = S[i].size();
        maxlen = max(maxlen,len);
    }

    for(ll i = 0;i<n;i++) {
        ll leni = S[i].size();
        ll k = (maxlen-leni)/2;
        for(ll j = 0;j<k;j++) cout << ".";
        cout << S[i];
        for(ll j = 0;j<k;j++) cout << ".";
        cout << "\n";
    }
    
}


/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/






/*
答えはサイコロiの出目の累積和の総積となる。
因数分解すると分かる。
*/



