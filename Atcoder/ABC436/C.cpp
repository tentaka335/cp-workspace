#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    set<pair<ll,ll>> A;
    for(ll i = 0;i<m;i++) {
        ll r,c;
        cin >> r >> c;
        if(A.count({r-1,c-1})||A.count({r,c-1})||A.count({r+1,c-1})|| 
           A.count({r-1,c})||A.count({r,c})||A.count({r+1,c})||
           A.count({r-1,c+1})||A.count({r,c+1})||A.count({r+1,c+1})
        ) {
            continue;
        }
        else {
             A.insert(make_pair(r,c));
        }
    }
    cout << A.size() << "\n";
}