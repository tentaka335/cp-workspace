#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
vector<char> S;
string s;
cin >> s;
for(ll i = 0;i<s.size();i++) {
    S.push_back(s[i]);
    if(S.size()>=2) {
    if((S[S.size()-2]=='('&&S[S.size()-1]==')')||(S[S.size()-2]=='['&&S[S.size()-1]==']')||(S[S.size()-2]=='<'&&S[S.size()-1]=='>')) {
        S.pop_back();
        S.pop_back();
    }
}
}
cout << (S.size()==0?"Yes":"No") << "\n";
}


