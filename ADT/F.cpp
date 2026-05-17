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
    vector<ll> P(n);
    rep(i,n) cin >> P[i];
    set<ll> tani;
    set<ll> yama;
    rep(i,n-2) {
        if(P[i]<P[i+1]&&P[i+1]>P[i+2]) yama.insert(i);
        if(P[i]>P[i+1]&&P[i+1]<P[i+2]) tani.insert(i);
    }


    ll left = 0,right = 0;
    ll ans = 0;
    ll yaman = 0,tanin = 0;

    while(left<n-3&&right<n) {
        if((yaman<=1&&tanin<=1)&&!(yaman==1&&tanin==1)) {
            right++;
            if(yama.count(right-2)) yaman++;
            if(tani.count(right-2)) tanin++;
        } else {
            if(yama.count(left)) yaman--;
            if(tani.count(left)) tanin--;
            left++;
        }

        if(yaman==1&&tanin==1&&right - left >=3&&P[left]<P[left+1]) ans++;
    }
    cout << ans;
    
    return 0;

}