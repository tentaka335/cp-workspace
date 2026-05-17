#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    string s1,s2;
    cin >> s1 >> s2;
    if(s1=="sick"&&s2=="sick") cout << 1 << "\n";
    if(s1!="sick"&&s2=="sick") cout << 3 << "\n";
    if(s1=="sick"&&s2!="sick") cout << 2 << "\n";
    if(s1!="sick"&&s2!="sick") cout << 4 << "\n";
}


