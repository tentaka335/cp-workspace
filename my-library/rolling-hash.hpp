#include <array>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <algorithm>
#include <cassert>

namespace internal {
using u64 = unsigned long long;
using u128 = __uint128_t;

template <int BASE_NUM = 2>
struct Hash : std::array<u64, BASE_NUM> {
    using std::array<u64, BASE_NUM>::operator[];
    static constexpr int n = BASE_NUM;
    static constexpr u64 md = (1ull << 61) - 1;

    Hash() : std::array<u64, BASE_NUM>() {}

    // 初期化用
    constexpr static Hash set(const long long& a) {
        Hash res;
        u64 s = a < 0 ? a + md : a;
        for (int i = 0; i < n; i++) res[i] = s;
        return res;
    }

    // 基本的な演算子
    Hash& operator+=(const Hash& r) {
        for (int i = 0; i < n; i++) if (((*this)[i] += r[i]) >= md) (*this)[i] -= md;
        return *this;
    }
    Hash& operator-=(const Hash& r) {
        for (int i = 0; i < n; i++) if (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;
        return *this;
    }
    Hash& operator*=(const Hash& r) {
        for (int i = 0; i < n; i++) (*this)[i] = modmul((*this)[i], r[i]);
        return *this;
    }
    Hash operator+(const Hash& r) const { return Hash(*this) += r; }
    Hash operator-(const Hash& r) const { return Hash(*this) -= r; }
    Hash operator*(const Hash& r) const { return Hash(*this) *= r; }

    // ローリングハッシュのコア処理: a * b + c (mod 2^61-1)
    friend Hash pfma(const Hash& a, const Hash& b, const long long& c) {
        Hash res;
        u64 s = c < 0 ? c + md : c;
        for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], s);
        return res;
    }

    // 安全な基数の生成（原始根を使用）
    static Hash get_basis() {
        static auto rand_time = std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        static std::mt19937_64 rng(rand_time);
        Hash h;
        for (int i = 0; i < n; i++) {
            while (isPrimitive(h[i] = rng() % (md - 1) + 1) == false);
        }
        return h;
    }

private:
    static u64 modpow(u64 a, u64 b) {
        u64 r = 1;
        for (a %= md; b; a = modmul(a, a), b >>= 1) r = modmul(r, a);
        return r;
    }
    static bool isPrimitive(u64 x) {
        for (auto& d : std::vector<u64>{2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321})
            if (modpow(x, (md - 1) / d) <= 1) return false;
        return true;
    }
    static inline constexpr u64 modmul(const u64& a, const u64& b) {
        u128 d = u128(a) * b;
        u64 ret = (u64(d) & md) + u64(d >> 61);
        return ret >= md ? ret - md : ret;
    }
    static inline constexpr u64 modfma(const u64& a, const u64& b, const u64& c) {
        u128 d = u128(a) * b + c;
        u64 ret = (d >> 61) + (u64(d) & md);
        return ret >= md ? ret - md : ret;
    }
};
} // namespace internal


// ========================================
// ここから RollingHash の実装
// ========================================

template <typename Str, int BASE_NUM = 2>
struct RollingHash {
    using Hash = internal::Hash<BASE_NUM>;
    Str data;
    std::vector<Hash> hs, pw;
    int s;
    static Hash basis;

    RollingHash(const Str &S = Str()) { build(S); }

    void build(const Str &S) {
        data = S;
        s = S.size();
        hs.resize(s + 1);
        pw.resize(s + 1);
        pw[0] = Hash::set(1);
        hs[0] = Hash::set(0);
        for (int i = 1; i <= s; i++) {
            pw[i] = pw[i - 1] * basis;
            hs[i] = pfma(hs[i - 1], basis, S[i - 1]);
        }
    }

    Hash get(int l, int r = -1) const {
        if (r == -1) r = s;
      
        return hs[r] - (hs[l] * pw[r - l]);
    }

    // T の hash を返す
    static Hash get_hash(const Str &T) {
        Hash ret = Hash::set(0);
        for (int i = 0; i < (int)T.size(); i++) ret = pfma(ret, basis, T[i]);
        return ret;
    }

    int find(const Str &T, int lower = 0) const {
        auto ths = get_hash(T);
        for (int i = lower; i <= s - (int)T.size(); i++)
            if (ths == get(i, i + (int)T.size())) return i;
        return -1;
    }

    static int lcp(const RollingHash &a, const RollingHash &b, int al, int bl) {
        int ok = 0, ng = std::min(a.size() - al, b.size() - bl) + 1;
        while (ok + 1 < ng) {
            int med = (ok + ng) / 2;
            (a.get(al, med + al) == b.get(bl, med + bl) ? ok : ng) = med;
        }
        return ok;
    }

    static int strcmp(const RollingHash &a, const RollingHash &b, int al, int bl, int ar = -1, int br = -1) {
        if (ar == -1) ar = a.size();
        if (br == -1) br = b.size();
        int n = std::min({lcp(a, b, al, bl), ar - al, br - bl});
        return al + n == ar ? (bl + n == br ? 0 : -1) : (bl + n == br ? 1 : (a.data[al + n] < b.data[bl + n] ? -1 : 1));
    }

    int size() const { return s; }
};

template <typename Str, int BASE_NUM>
typename RollingHash<Str, BASE_NUM>::Hash RollingHash<Str, BASE_NUM>::basis = internal::Hash<BASE_NUM>::get_basis();

using roriha = RollingHash<std::string, 2>;

// Usage:
//   rolling_hash_basic_test();
// If any assertion fails, the program aborts.
inline void rolling_hash_basic_test() {
    using RH = RollingHash<std::string, 2>;

    {
        std::string s = "abracadabra";
        RH rh(s);

        assert(rh.size() == (int)s.size());
        assert(rh.get(0, 0) == RH::get_hash(""));
        assert(rh.get(0, 3) == RH::get_hash("abr"));
        assert(rh.get(3, 7) == RH::get_hash("acad"));
        assert(rh.get(7, 11) == RH::get_hash("abra"));

        assert(rh.find("abra") == 0);
        assert(rh.find("abra", 1) == 7);
        assert(rh.find("cad") == 4);
        assert(rh.find("xyz") == -1);
    }

    {
        RH a("banana");
        RH b("bandana");

        assert(RH::lcp(a, b, 0, 0) == 3); // "ban"
        assert(RH::lcp(a, b, 2, 2) == 1); // "n"
        assert(RH::strcmp(a, b, 0, 0) < 0);
        assert(RH::strcmp(a, b, 0, 0, 3, 3) == 0); // "ban" vs "ban"
        assert(RH::strcmp(a, b, 3, 3) < 0); // "ana" vs "dana"
    }

    {
        RH e("");
        assert(e.size() == 0);
        assert(e.get(0, 0) == RH::get_hash(""));
        assert(e.find("") == 0);
        assert(e.find("a") == -1);
    }
}