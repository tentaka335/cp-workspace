#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using llll = __int128_t;
using namespace atcoder;
using Pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
template<class T> bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }
const ll inf = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;



int main() {

    ll n;
    cin >> n;
    //find　行
    ll x;
    ll left = 1,right = n;

    while(right - left >= 1) {
        ll mid = (right + left)/2;
        cout << "?" << " "<<left << " " << mid << " " << 1  <<" " <<n << endl;
        ll t;
        cin >> t;
        if(t>=mid - left + 1) {
            left = mid + 1;
        }
        else right = mid;
    }
    x = left;

     left = 1,right = n;

    while(right - left >= 1) {
        ll mid = (right + left)/2;
        cout << "?" << " " << 1  << " " << n << " " << left << " "<< mid << endl;
        ll t;
        cin >> t;
        if(t>=mid - left + 1) {
            left = mid + 1;
        }
        else right = mid;
    }
    ll y = left;

    cout << "!" << " " << x <<" " << y << endl;
    
    
    return 0;
}