#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    ll n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    ll k = 100,m=2147483647;//ハッシュ用
    vector<ll> B(n+1,1);
    vector<ll> Hash(n+1,0);
   
    for(ll i = 1;i<=n;i++) {
        B[i] =(B[i-1]*k)%m;
    }

   
    for(ll i = 1;i<=n;i++) {
        Hash[i] = (k*Hash[i-1]+(s[i-1]-'a')+1)%m;
    }
    for(ll i = 0;i<q;i++) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll hashab = (Hash[b]-(B[b-a+1]*Hash[a-1])%m+m)%m;
        ll hashcd = (Hash[d]-(B[d-c+1]*Hash[c-1])%m+m)%m;

        if(hashab == hashcd) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
 }