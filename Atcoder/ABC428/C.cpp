#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll q;
    cin >> q;
    vector<string> S;
    vector<ll> Sum,Min;
    for(ll i = 0;i<q;i++) {
        ll qt;
        cin >> qt;
        if(qt == 1) {
            string c;
            cin >> c;
            S.push_back(c);
            if(c == "(") {
                if(Sum.size()==0) {
                    Sum.push_back(1);
                    Min.push_back(1);
                }
                else {
                    Sum.push_back(Sum[Sum.size()-1]+1);
           
                    Min.push_back(Min[Min.size()-1]);
            }
        }
            if(c == ")") {
                if(Sum.size()==0) {
                    Sum.push_back(-1);
                    Min.push_back(-1);
                }
                else {
                    Sum.push_back(Sum[Sum.size()-1]-1);
                    Min.push_back(min(Min[Min.size()-1],Sum[Sum.size()-1]));
            }
            }
        }
    else if(qt==2) {
        S.pop_back();
        Sum.pop_back();
        Min.pop_back();
    }
    if(Sum.size() == 0) { 
        cout << "Yes" << "\n";
        continue;
    }
    else if (Sum[Sum.size()-1]== 0 && Min[Min.size()-1]==0) {
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }
}
}