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
    cin >> n;
    // /2忘れずに
    vector<ll> oox,ooy,eox,eoy,oex,oey,eex,eey;
    rep(i,n) {
        ll x,y;
        cin >> x >> y;
        ll X = x+y;
        ll Y = x - y;
        if(X%2==0&&Y%2==0) {eex.push_back(X);eey.push_back(Y);}
        if(X%2!=0&&Y%2==0) {oex.push_back(X);oey.push_back(Y);}
        if(X%2==0&&Y%2!=0) {eox.push_back(X);eoy.push_back(Y);}
        if(X%2!=0&&Y%2!=0) {oox.push_back(X);ooy.push_back(Y);}
    }

    

    ll ans = 0;
    auto f = [&] (vector<ll> A) {
        ll len = A.size();
        if(len<=1) return ;
        sort(all(A));
        for(ll i = 0;i<len;i++) {
           ll right =  lower_bound(all(A),A[i]) - A.begin();
           right--;
           ll left =  upper_bound(all(A),A[i]) - A.begin();
          if(left<len) ans-= (len -left)*A[i];
          if(right>=0) ans+=(right+1)*A[i];
        }
    };
    f(oox);
    f(ooy);
    f(eox);
    f(eoy);
    f(oex);
    f(oey);
    f(eex);
    f(eey);
    ans/=2;
    cout << ans;
    
    
    
    return 0;
}