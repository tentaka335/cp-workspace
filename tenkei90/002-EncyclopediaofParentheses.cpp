#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n;
    cin >> n;
    if(n%2==1) {
        return 0;
    }
    vector<string> s;
    vector<ll> A(n);
    vector<ll> S(n);
    set<string> ans;
    for(ll i = 1;i<=n/2;i++) {
        s.push_back("(");
    }
    for(ll i = 1;i<=n/2;i++) {
         s.push_back(")");
    }
    do{
        bool isgood = true;
    for(ll i = 0;i<n;i++) {
        if(s[i] == "(") {
            A[i] = 1;
        }
        else {
            A[i] = -1;
        }
        if(i == 0) S[i] = A[i];
        else {
            S[i] = S[i-1] + A[i];
        }
       

    
         
    }
    for(ll i = 0;i<n;i++) {
            if(S[i] < 0) isgood = false;
        }
        if(A[n-1] == 1) isgood = false;
            string ss;
        if(isgood==true) {
            for(ll i = 0;i<n;i++) ss+=s[i];
            ans.insert(ss);
        }
    } while (next_permutation(s.begin(),s.end()));
    for(auto A : ans) cout << A <<"\n";
}