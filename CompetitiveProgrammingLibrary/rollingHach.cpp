//Rolling-hash 事前準備計算量O(N) 文字列比較O(1)
//ハッシュ値(3つ)
struct HashData {
	int h1, h2, h3;
	bool operator==(const HashData& rhs) const {
		return h1 == rhs.h1 && h2 == rhs.h2 && h3 == rhs.h3;
	}
	bool operator!=(const HashData& rhs) const { return !(*this == rhs); }
};
class RollingHash {
	template<int B, int M>
	class RollingHashPart {
	private:
		size_t len;
		std::vector<int> pow_b, hash;
	public:
		RollingHashPart() {}
		template<typename T>
		RollingHashPart(const T& s) : len(s.size()), pow_b(s.size() + 1), hash(s.size() + 1) {
			pow_b[0] = 1;
			hash[0] = 0;
			for (int i = 0; i < len; i++) {
				pow_b[i + 1] = (ll)pow_b[i] * B % M;
				hash[i + 1] = ((ll)hash[i] * B + s[i]) % M;
			}
		}
		template<typename T>
		void add(const T & s) {
			int sz = pow_b.size();
			pow_b.resize(sz + s.size());
			hash.resize(sz + s.size());
			REP(i, s.size()) {
				pow_b[sz + i] = (ll)pow_b[sz + i - 1] * B % M;
				hash[sz + i] = ((ll)hash[sz + i - 1] * B + s[i]) % M;
			}
		}
		int size() const {
			return hash.size() - 1;
		}
		// [l, r)
		int get(int l, int r) const {
			if (l == r) return 0LL;
			int res = (hash[r] - (ll)hash[l] * pow_b[r - l]) % M;
			if (res < 0) res += M;
			return res;
		}
	};
public:
	RollingHashPart<1033, 1000000007> rh1;
	RollingHashPart<6037, 999999937> rh2;
	RollingHashPart<1009, 1000000009> rh3;

	RollingHash() {}
	template<typename T> RollingHash(const T & s) : rh1(s), rh2(s), rh3(s) {}
	// [l, r)
	HashData get(int l, int r) const {
		return HashData{ rh1.get(l, r), rh2.get(l, r), rh3.get(l, r) };
	}
	template<typename T> void add(const T& s) { rh1.add(s); rh2.add(s); rh3.add(s); }
};
//宣言　sは文字列
RollingHash rh(s);
//-------------------------------------------------------------------------
//ハッシュ2つ
struct RollingHash {
    static const int base1 = 1007, base2 = 2009;
    static const int mod1 = 1000000007, mod2 = 1000000009;
    vector<long long> hash1, hash2, power1, power2;

    // construct
    RollingHash(const string &S) {
        int n = (int)S.size();
        hash1.assign(n+1, 0);
        hash2.assign(n+1, 0);
        power1.assign(n+1, 1);
        power2.assign(n+1, 1);
        for (int i = 0; i < n; ++i) {
            hash1[i+1] = (hash1[i] * base1 + S[i]) % mod1;
            hash2[i+1] = (hash2[i] * base2 + S[i]) % mod2;
            power1[i+1] = (power1[i] * base1) % mod1;
            power2[i+1] = (power2[i] * base2) % mod2;
        }
    }
    
    // get hash of S[left:right]
    inline pair<long long, long long> get(int l, int r) const {
        long long res1 = hash1[r] - hash1[l] * power1[r-l] % mod1;
        if (res1 < 0) res1 += mod1;
        long long res2 = hash2[r] - hash2[l] * power2[r-l] % mod2;
        if (res2 < 0) res2 += mod2;
        return {res1, res2};
    }

    // get lcp of S[a:] and T[b:]
    inline int getLCP(int a, int b) const {
        int len = min((int)hash1.size()-a, (int)hash1.size()-b);
        int low = 0, high = len;
        while (high - low > 1) {
            int mid = (low + high) >> 1;
            if (get(a, a+mid) != get(b, b+mid)) high = mid;
            else low = mid;
        }
        return low;
    }
};