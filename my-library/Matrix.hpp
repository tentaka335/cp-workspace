#include <bits/stdc++.h>


template<class T> 
struct Matrix {
    std::vector<std::vector<T>> A;
    Matrix() {}
    Matrix(size_t n,size_t m) : A(n,std::vector<T>(m,0)) {}
    Matrix(size_t n) :A(n,std::vector<T>(n,0)) {}//正方行列用
    
    size_t height() const {return A.size(); }
    size_t width() const {return A.empty()?0:A[0].size();}

    inline const std::vector<T>& operator[](int k ) const {return A[k];}//mat[i][j]のiでi行目にアクセスすることを可能にするためのもの。[j]はvectorの標準機能で使える。
    inline std::vector<T>& operator[](int k){return A[k];} 
    /*↑
    void printMatrix(const Matrix<int>& B) {
    // 画面に出力するだけなので、Bの中身を見る（読み取る）処理
    std::cout << B[0][0] << std::endl; 
    }
    このような処理の場合には constなアクセスも欲しいので2種類用意
    */

    static Matrix I(size_t n) {
        Matrix mat(n);
        for(size_t i = 0;i<n;i++) mat[i][i] = 1;
        return mat;
    }/*staticをつけることで、
    Matrix<int> I = Matrix::I(n)と単位行列を一気に作成できる
    これを静的メンバ関数という。
    これを利用しない場合、空のmatrixを用意して
    単位行列化関数を適用しなければならず面倒
    */
     
    Matrix& operator+=(const Matrix& B) {
        size_t n = height(),m = width();//直接Aの縦、横にアクセスできる
        assert(n==B.height()&&m == B.width());
        for(size_t i = 0;i<n;i++) 
         for(size_t j = 0;j<m;j++)
        (*this)[i][j] +=B[i][j];
    return *this;
    }
    /*
    演算子は左辺を型にし基づいて定義される。例えば
    mat*2はこの構造体の中で用意できるが
    2*matはこの構造体の中で用意できない。intに新たな演算を定義しなければならない。
    構造体の外に演算子を書けばこれを解決できる。
    */
     Matrix& operator-=(const Matrix& B) {
        size_t n = height(),m = width();//直接Aの縦、横にアクセスできる
        assert(n==B.height()&&m == B.width());
        for(size_t i = 0;i<n;i++) 
         for(size_t j = 0;j<m;j++)
        (*this)[i][j] -=B[i][j];
    return *this;
    }


    Matrix& operator *=(const Matrix&B) {
        size_t n = height(),m = B.width(),p = width();
        assert(p == B.height());
        Matrix C(n,m);
        for(size_t i = 0;i<n;i++)
        for(size_t k = 0;k<p;k++)
        for(size_t j = 0;j<m;j++) 
    C[i][j] +=(*this)[i][k]*B[k][j];

    A.swap(C.A);
    return *this;
/*
for文の回し方が行列積の定義通りではないのは、C++の仕様として、配列にアクセスしたときその付近もまとめてキャッシュメモリに持ってくる
ことを利用し、[i][k]というjループにおける定数と同じ配列のアクセスで書ける形で書くことで高速化するため
*/
    }

    Matrix pow(long long k) const {
        assert(height()==width());
       Matrix res = Matrix::I(height());
       Matrix a= *this;
       while(k > 0) {
        if(k&1) res*=a;
        a*=a;
        k>>=1;
       }
       return res;
    }

    Matrix operator+(const Matrix& B) const { return (Matrix(*this) += B); }
    Matrix operator-(const Matrix& B) const { return (Matrix(*this) -= B); }
    Matrix operator*(const Matrix& B) const { return (Matrix(*this) *= B); }
    bool operator==(const Matrix& B) const {
        size_t n = height(),m = width();
        if(!(n==B.height()&&m==B.width())) return false;

        for(size_t i = 0;i<n;i++)
        for(size_t j = 0;j<m;j++)
        if(A[i][j]!=B[i][j]) return false;


        return true;
    }
};













/*
inlineは#includeが<>の中身をそのファイルに展開する仕様により、
関数名が衝突しうるため、それを防ぐためのもの
*/