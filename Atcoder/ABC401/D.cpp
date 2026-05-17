#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n,k;
    cin >> n >> k;
    string smoto;
    cin >> smoto;
    ll maru = 0;//〇の数
    string s = '.' + smoto + '.';
    vector<char> t(n+2,'?');
    for(ll i = 1;i<=n;i++) {
        if(s[i] != '?') t[i] = s[i];
        if(s[i] == 'o') {
            maru++;
             t[i-1] = '.';
             t[i+1] = '.';
        }
    }
    //ランレングス圧縮
    vector<ll> hatena;
     vector<ll> hatenahead;
    vector<ll> ukeiremaru;
    ll count = 0;
    ll capa = 0;
    ll head = 1;
    for(ll i = 1;i<=n;i++) {
        if(t[i] == '?') {
            if(count == 0) {
                head = i;
            }
            count ++;
            if(i==n) {
                 if(count>=1) {
                hatena.push_back(count);
                hatenahead.push_back(head);
                if (count%2== 0) {
                    ukeiremaru.push_back((count/2));
                capa+=(count/2);
                }
                else {
                       ukeiremaru.push_back((count/2)+1);
                capa+=(count/2)+1;
                }
                count = 0;
            }
            }
        }
        
        else {
            if(count>=1) {
                hatena.push_back(count);
                hatenahead.push_back(head);
                if (count%2== 0) {
                    ukeiremaru.push_back((count/2));
                capa+=(count/2);
                }
                else {
                       ukeiremaru.push_back((count/2)+1);
                capa+=(count/2)+1;
                }
                count = 0;
            }
        }
    }
    if(k==maru) {
        for(ll i = 1;i<=n;i++) {
            if(t[i]=='o') cout << 'o';
            else cout << ".";
        }
        return 0;
    }
    if(capa>k-maru) {
        for(ll i = 1;i<=n;i++) cout << t[i];
        return 0;
    }
    //ギリギリの時偶数列はそのまま、奇数だけ〇.  ；

    //ランレングスそれぞれにアクセス
    for(ll i = 0;i<hatena.size();i++) {
        if(hatena[i]%2==0) continue;
        ll head = hatenahead[i];
        for(ll j = head;j<hatena[i]+head;j++) {
            if((j-head)%2==0) t[j] = 'o';
            else t[j] = '.';
        }
    }

    for(ll i = 1;i<=n;i++) cout << t[i] ;

}

