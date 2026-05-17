#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll f(ll x) {
    string s = to_string(x);
        int sum=0;
        for(int j=0;j<s.size();++j){
            sum+=s[j]-'0';
        }
        return sum;
    }


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll ans =1;
    for (ll i=1; i<n; i++) {
        ans+=f(ans);
    }
    cout << ans << endl;
}