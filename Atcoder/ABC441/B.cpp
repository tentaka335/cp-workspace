#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
using Pll = pair<ll,ll>;




int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    string t;
    cin >> t;

    set<char> S,T;
    for(ll i = 0;i<n;i++) S.insert(s[i]);
    for(ll i = 0;i<m;i++) T.insert(t[i]);

    ll q;
    cin >> q;
    for(ll i = 0;i<q;i++) {
        string w;
        cin >> w;
        bool takahasi = true;
        bool aoki = true;
        for(ll j = 0;j<w.size();j++) {
            if(!S.count(w[j])) takahasi = false;
            if(!T.count(w[j])) aoki = false;
        }
        if(takahasi&&aoki) cout << "Unknown" << "\n";
        if(takahasi&&!aoki) cout << "Takahashi" << "\n";
        if(!takahasi&&aoki) cout << "Aoki" << "\n";

    }

  
}




/*
高橋、青木の文字集合S,Tを作っておくと簡潔に書ける。
wのi文字目がS、Tに含まれているかをチェックし、
*/



