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

    ll t;
    cin >>t;
    rep(qt,t) {
        string a,b;
        cin >> a >> b;
        vector<char> A,B;
        bool ok = true;
        for(ll i = 0;i<a.size();i++) {
            A.push_back(a[i]);
            if(A.size()>=4) {
                ll Alen = A.size();
                if(A[Alen-4]=='('&&A[Alen-3]=='x'&&A[Alen-2]=='x'&&A[Alen-1]==')') {
                    A.pop_back();
                    A.pop_back();
                    A.pop_back();
                    A.pop_back();
                    A.push_back('x');                    
                    A.push_back('x');                    
                }
            }
        }
        for(ll i = 0;i<b.size();i++) {
            B.push_back(b[i]);
            if(B.size()>=4) {
                ll Blen = B.size();
                if(B[Blen-4]=='('&&B[Blen-3]=='x'&&B[Blen-2]=='x'&&B[Blen-1]==')') {
                    B.pop_back();
                    B.pop_back();
                    B.pop_back();
                    B.pop_back();
                    B.push_back('x');                    
                    B.push_back('x');                    
                }
            }
        }
        if(A.size()!=B.size()) {
            cout << "No" << "\n";
            continue;
        }
        else {
            ll len = A.size();
            rep(i,len) {
                if(A[i]!=B[i]) {
                    ok = false;
                    break; 
                }
            }
            cout << (ok?"Yes":"No") << "\n";
        }
    }
    
    return 0;
}