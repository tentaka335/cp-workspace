#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n ;
    cin >> n;
    ll b=0;
    for (ll i = 0;i<n;i++) {
        string t;
        ll a;
        cin >> t >> a;

        if (t == "+") b += a;
        else if(t == "-") b-=a;
        else if (t == "*") b = b*a;
        if (b<0) b += 10000;
       b = b%10000;
       cout << b << "\n";
    }
}