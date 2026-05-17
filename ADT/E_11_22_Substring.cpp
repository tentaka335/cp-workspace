#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n;
    cin >> n ;
    string s;
    cin >> s;
    ll ans = 1;
    vector<pair<char,ll>> A;
    char now = s[0];
    ll cnt = 1;


    if(n==1) A.push_back({s[0],1});
    for(ll i = 1;i<n;i++) {
        if(now==s[i]) {
            cnt++;
            
        }
        else {
            A.push_back({now,cnt});
            now = s[i];
            cnt = 1;
        }
        if(i==n-1) {
            A.push_back({now,cnt});
        }
    }
    
    for(ll i = 1;i<A.size()-1;i++) {
        if(A[i].first == '/'&&A[i].second==1) {
        if(A[i-1].first=='1'&&A[i+1].first=='2') {
            chmax(ans,2*min(A[i-1].second,A[i+1].second) + 1);
        }
    }
    }

    cout << ans;
    
    return 0;
}