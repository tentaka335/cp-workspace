#include <bits/stdc++.h>

struct MillerRabin {
	using u64 = std::uint64_t;
	using u128 = unsigned __int128;

	static u64 mod_mul(u64 a, u64 b, u64 mod) {
		return static_cast<u64>(static_cast<u128>(a) * b % mod);
	}

	static u64 mod_pow(u64 a, u64 e, u64 mod) {
		u64 r = 1;
		while (e > 0) {
			if (e & 1) r = mod_mul(r, a, mod);
			a = mod_mul(a, a, mod);
			e >>= 1;
		}
		return r;
	}

	static bool is_prime(u64 n) {
		if (n < 2) return false;
		for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL}) {
			if (n % p == 0) return n == p;
		}

		u64 d = n - 1;
		int s = 0;
		while ((d & 1) == 0) {
			d >>= 1;
			++s;
		}

		// Deterministic for 64-bit unsigned integers.
		static constexpr u64 kWitnesses[] = {
			2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL
		};

		for (u64 a : kWitnesses) {
			if (a >= n) continue;
			u64 x = mod_pow(a, d, n);
			if (x == 1 || x == n - 1) continue;

			bool composite = true;
			for (int r = 1; r < s; ++r) {
				x = mod_mul(x, x, n);
				if (x == n - 1) {
					composite = false;
					break;
				}
			}
			if (composite) return false;
		}
		return true;
	}
};

