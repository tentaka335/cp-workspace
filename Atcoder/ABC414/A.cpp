#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
        auto iskaibun = [=] (string s) {
        ll len ;
        if(s.size()%2==0) len = s.size()/2;
        else len = s.size()/2+1;
        for(ll i = 0;i<len;i++) {
            if(s[i] != s[s.size()-1-i]) return false;
        }
        return true;
};
cout << iskaibun("aaa") ;
}
