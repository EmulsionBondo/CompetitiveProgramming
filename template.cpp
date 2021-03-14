#include <stdio.h>
#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
inline constexpr ll ceil_div(const ll a, const ll b) {return (a + b - 1) / b - !!((a + b - 1) % b < 0);}// return ceil(a/b)
inline constexpr ll floor_div(const ll a, const ll b) {return a / b - !!(a % b < 0);}// return floor(a/b)

/*  ----------------------- DEBUG FUNCTION ---------------------------- */
#define DUMPOUT cerr
void dump_function() { DUMPOUT << ' '; }
void dump_function(bool a) { DUMPOUT << a; }
void dump_function(int a) { DUMPOUT << a; }
void dump_function(long long a) { DUMPOUT << a; }
void dump_function(char a) { DUMPOUT << a; }
void dump_function(string &a) { DUMPOUT << a; }
void dump_function(double a) { DUMPOUT << a; }
template <class T> void dump_function(const vector<T> &);
template <class T, size_t size> void dump_function(const array<T, size> &);
template <class T, class L> void dump_function(const pair<T, L> &p);
template <class T, size_t size> void dump_function(const T (&)[size]);
template <class T> void dump_function(const vector<T> &a) {
    if(a.empty()) return;
    dump_function(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        DUMPOUT << " ";
        dump_function(*i);
    }
    DUMPOUT << endl;
}
template <class T> void dump_function(const deque<T> &a) {
    if(a.empty()) return;
    dump_function(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        DUMPOUT << " ";
        dump_function(*i);
    }
}
template <class T, size_t size> void dump_function(const array<T, size> &a) {
    dump_function(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        DUMPOUT << " ";
        dump_function(*i);
    }
}
template <class T, class L> void dump_function(const pair<T, L> &p) {
    DUMPOUT << '(';
    dump_function(p.first);
    DUMPOUT << ",";
    dump_function(p.second);
    DUMPOUT << ')';
}
template <class T> void dump_function(set<T> &x) {
    for(auto e : x) dump_function(e), DUMPOUT << " ";
    DUMPOUT << endl;
}
template <class T> void dump_function(multiset<T> &x) {
    for(auto e : x) dump_function(e), DUMPOUT << " ";
    DUMPOUT << endl;
}
template <class T, size_t size> void dump_function(const T (&a)[size]) {
    dump_function(a[0]);
    for(auto i = a; ++i != end(a);) {
        DUMPOUT << " ";
        dump_function(*i);
    }
}
template <class T> void dump_function(const T &a) { DUMPOUT << a; }
int dump_out() {
    DUMPOUT << '\n';
    return 0;
}
template <class T> int dump_out(const T &t) {
    dump_function(t);
    DUMPOUT << '\n';
    return 0;
}
template <class Head, class... Tail> int dump_out(const Head &head, const Tail &... tail) {
    dump_function(head);
    DUMPOUT << ' ';
    dump_out(tail...);
    return 0;
}

#ifdef DEBUG_
#define dump(x)                                                                                                                                               \
    DUMPOUT << #x << ": ";                                                                                                                                        \
    dump_function(x);                                                                                                                                                  \
    DUMPOUT << endl;
void dumps() {}
template <class T> void dumps(const T &t) {
    dump_function(t);
    DUMPOUT << " ";
}
template <class Head, class... Tail> void dumps(const Head &head, const Tail &... tail) {
    dump_function(head);
    DUMPOUT << ' ';
    dump_out(tail...);
}
#else
#define dump(x)
template <class... T> void dumps(const T &...) {}
#endif
/*  ----------------------- DEBUG FUNCTION ---------------------------- */

template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() const { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr istream& operator >> (istream& is, Fp<MOD>& x) noexcept {
        is >> x.val;
        x.val %= MOD;
        if (x.val < 0) x.val += MOD;
        return is;
    }
    friend constexpr ostream& operator << (ostream& os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD>& r, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(r, n / 2);
        t = t * t;
        if (n & 1) t = t * r;
        return t;
    }
    friend constexpr Fp<MOD> modinv(const Fp<MOD>& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        return Fp<MOD>(u);
    }
};


template<class T> struct BiCoef {
    vector<T> fact_, inv_, finv_;
    constexpr BiCoef() {}
    constexpr BiCoef(int n) noexcept : fact_(n, 1), inv_(n, 1), finv_(n, 1) {
        init(n);
    }
    constexpr void init(int n) noexcept {
        fact_.assign(n, 1), inv_.assign(n, 1), finv_.assign(n, 1);
        int MOD = fact_[0].getmod();
        for(int i = 2; i < n; i++){
            fact_[i] = fact_[i-1] * i;
            inv_[i] = -inv_[MOD%i] * (MOD/i);
            finv_[i] = finv_[i-1] * inv_[i];
        }
    }
    constexpr T com(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[k] * finv_[n-k];
    }
    constexpr T fact(int n) const noexcept {
        if (n < 0) return 0;
        return fact_[n];
    }
    constexpr T inv(int n) const noexcept {
        if (n < 0) return 0;
        return inv_[n];
    }
    constexpr T finv(int n) const noexcept {
        if (n < 0) return 0;
        return finv_[n];
    }
    constexpr T perm(int n, int k) const noexcept {
        if (n < k || n < 0 || k < 0) return 0;
        return fact_[n] * finv_[n-k];
    }
};

/* ----------------------------- MOD ----------------------------------- */
const int MOD = 1000000007;
const int MOD2 = 998244353;
using mint = Fp<MOD>;
BiCoef<mint> bc;
// using vec = vector<int>;
// using mat = vector<vec>;
/* ----------------------------- MOD ----------------------------------- */

/*  ----------------------- AtCoder Library ---------------------------- */
// #include <atcoder/all>
// using namespace atcoder;
/*  ----------------------- AtCoder Library ---------------------------- */
