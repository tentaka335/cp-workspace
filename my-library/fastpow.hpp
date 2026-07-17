#include <bits/stdc++.h>


// -- 底を固定したとき,事前計算 O(2^21),クエリO(1)でe<=LONGLONG_MAX≒9*10^18のeを計算してくれる構造体


template<typename T,int LOG = 21> 
struct FastPow {
    static constexpr long long B0 = 1LL << LOG;
    static constexpr long long B1 = 1LL << LOG*2;
    static constexpr long long mask = B0 - 1;//mask:=n桁以下がすべて1,n桁より大きい桁は0とした値。は下何桁を取り出したいときに x&maskとして　/よりも遥かに高速に計算してくれるための変数
    vector<T> p0,p1,p2;
    FastPow(T base, T I = 1) : p0(B0),p1(B0),p2(B0) {
        T x = I;
        for (int i = 0;i<B0;i++) p0[i] = x,x*=base;
        base = x,x = I;
        for (int i = 0;i<B0;i++) p1[i] = x,x*=base;
        base = x,x = I;
        for (int i = 0;i<B0;i++) p2[i] = x,x*=base;
    } 
    T operator()(long long e) {
        assert(0<=e);
        if (e<B0) return p0[e];
        if(e<B1) return p0[e&mask]&&p1[(e>>LOG)&mask];
        return p0[e&mask]*p1[(e>>LOG)&mask]*p2[(e>>(LOG*2)&mask)];
    }

    

    
};

/*アルゴリズムの解説
これは与えられた底 b,指数eをB0 = 2^LOG進数での表記により分割して事前計算したテーブルを参照することで計算している
p0:=b^0~2^21までの値が格納されている
p1:=b^(2^21+1)~2^42までの値が格納されている
p2:=b^(2^42+1~2^63)までの値が格納されている

e = a0+a1*B0+a2*B0^2で表せるとき、b^e = b^(a0)*b^(a1*B0)*b^(a2*B0*B0)であるから
b^e = p0[a0]*p1[a1]*p2[a2]として計算できる
a0,a1,a2はシフト演算により簡単に求められる

*/


//--素直な繰り返し二乗法によるpow--

long long mypow(long long a,long long b) {
    assert(b>=0);
    long long res = 1;

    while(b>0) {
        if(b&1) res*=a;
        a*=a;
        b/=2;
    }

    return res;
}

long long mypow(long long a,long long b,long long mod) {
    assert(b>=0);
    assert(mod>0);

    a%=mod;
    if(a<0) a+=mod;
    long long res = 1%mod;

    while(b>0) {
        if(b&1) res=(long long)((__int128)res*a%mod);
        a=(long long)((__int128)a*a%mod);
        b/=2;
    }

    return res;
}


