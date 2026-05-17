#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string X,Y;
    ll x,y;
    cin >> X >> Y;
    if(X =="Ocelot") x=0;
    if(X =="Serval") x=1;
    if(X =="Lynx") x=2;
    if(Y =="Ocelot") y=0;
    if(Y =="Serval") y=1;
    if(Y =="Lynx") y=2;

    if (x>=y) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    
    

}