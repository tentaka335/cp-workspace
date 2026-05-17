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
    
    double a,b,d;
    cin >> a >> b >> d;
    double pi = 3.1415926535;
    double aa = a * cos(pi/180*d) - b *sin(pi/180*d);
    double bb = a * sin(pi/180*d) + b * cos(pi/180*d);
     cout << fixed << setprecision(10);
    cout << aa << " " << bb;
        return 0;
}