#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll happy(ll x) {
    string s = to_string(x);
    ll ans = 0;
    for(ll i = 0;i<s.size();i++) {
        ll y = (s[i] - '0')*(s[i]-'0');
        ans +=y;
    }
    return ans;
}

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    vector<bool> visited(325);
    ll n;
    cin >> n;
    bool ishappy = true;
    while(n!=1) {
        n = happy(n);
        if(visited[n]==false) {
            visited[n] = true;
        }
        else {
            ishappy = false;
            break;
        }
    }
    if(ishappy) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}