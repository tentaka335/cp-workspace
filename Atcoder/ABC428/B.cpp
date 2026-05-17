#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,k;
    string s;
    cin >> n >> k;
    cin >> s;

    map<string,ll> A;
    for (ll i = 0; i<n-k+1;i++) {
       string subs = s.substr(i,k);
       if (!A.count(subs)) A[subs] =1;
       else A[subs] +=1;
    }
    ll maxi  = 0;
    for (auto p : A) {
        ll a = p.second;
        maxi = max(a,maxi);
    }
    cout << maxi << "\n";
    for (auto p : A) {
        ll b = p.second;
        if (b == maxi) {
            string ss = p.first;
            cout << ss << " ";
        }
    }
}