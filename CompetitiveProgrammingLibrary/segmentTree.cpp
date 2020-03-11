// セグメントツリー
// 区間[l,r)の和をO(log N)で求めることができる
template<class Monoid> struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    const Func F;
    const Monoid UNITY;
    int SIZE_R;
    vector<Monoid> dat;
    
    SegTree(int n, const Func f, const Monoid &unity): F(f), UNITY(unity) { init(n); }
    void init(int n) {
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, UNITY);
    }
    
    /* set, a is 0-indexed */
    void set(int a, const Monoid &v) { dat[a + SIZE_R] = v; }
    void build() {
        for (int k = SIZE_R - 1; k > 0; --k)
            dat[k] = F(dat[k*2], dat[k*2+1]);
    }
    
    /* update a, a is 0-indexed */
    void update(int a, const Monoid &v) {
        int k = a + SIZE_R;
        dat[k] = v;
        while (k >>= 1) dat[k] = F(dat[k*2], dat[k*2+1]);
    }
    
    /* get [a, b), a and b are 0-indexed */
    Monoid get(int a, int b) {
        Monoid vleft = UNITY, vright = UNITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
            if (left & 1) vleft = F(vleft, dat[left++]);
            if (right & 1) vright = F(dat[--right], vright);
        }
        return F(vleft, vright);
    }
    inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

    /* debug */
    void print() {
        for (int i = 0; i < SIZE_R; ++i) {
            cout << (*this)[i];
            if (i != SIZE_R-1) cout << ",";
        }
        cout << endl;
    }
};

//使うとき
// セグツリーの構築
SegTree<long long> seg(N, [](long long a, long long b) {
        return gcd(a, b);
    },
    0);
vector<long long> A(N);
for (int i = 0; i < N; ++i) {
    cin >> A[i];
    seg.set(i, A[i]);
}
seg.build();
//-------------------------------------------------------------------------
// Lazy Segment Tree(抽象化)
template<class Monoid, class Action> struct LazySegTree {
    using FuncMonoid = function< Monoid(Monoid, Monoid) >;
    using FuncAction = function< void(Monoid&, Action) >;
    using FuncLazy = function< void(Action&, Action) >;
    FuncMonoid FM;
    FuncAction FA;
    FuncLazy FL;
    Monoid UNITY_MONOID;
    Action UNITY_LAZY;
    int SIZE, HEIGHT;
    vector<Monoid> dat;
    vector<Action> lazy;
    
    LazySegTree() { }
    LazySegTree(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
            const Monoid &unity_monoid, const Action &unity_lazy)
    : FM(fm), FA(fa), FL(fl), UNITY_MONOID(unity_monoid), UNITY_LAZY(unity_lazy) {
        SIZE = 1; HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }
    void init(int n, const FuncMonoid fm, const FuncAction fa, const FuncLazy fl,
              const Monoid &unity_monoid, const Action &unity_lazy) {
        FM = fm; FA = fa; FL = fl;
        UNITY_MONOID = unity_monoid; UNITY_LAZY = unity_lazy;
        SIZE = 1; HEIGHT = 0;
        while (SIZE < n) SIZE <<= 1, ++HEIGHT;
        dat.assign(SIZE * 2, UNITY_MONOID);
        lazy.assign(SIZE * 2, UNITY_LAZY);
    }
    
    /* set, a is 0-indexed */
    void set(int a, const Monoid &v) { dat[a + SIZE] = v; }
    void build() {
        for (int k = SIZE - 1; k > 0; --k)
            dat[k] = FM(dat[k*2], dat[k*2+1]);
    }
    
    /* update [a, b) */
    inline void evaluate(int k) {
        if (lazy[k] == UNITY_LAZY) return;
        if (k < SIZE) FL(lazy[k*2], lazy[k]), FL(lazy[k*2+1], lazy[k]);
        FA(dat[k], lazy[k]);
        lazy[k] = UNITY_LAZY;
    }
    inline void update(int a, int b, const Action &v, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)  FL(lazy[k], v), evaluate(k);
        else if (a < r && l < b) {
            update(a, b, v, k*2, l, (l+r)>>1), update(a, b, v, k*2+1, (l+r)>>1, r);
            dat[k] = FM(dat[k*2], dat[k*2+1]);
        }
    }
    inline void update(int a, int b, const Action &v) { update(a, b, v, 1, 0, SIZE); }
    
    /* get [a, b) */
    inline Monoid get(int a, int b, int k, int l, int r) {
        evaluate(k);
        if (a <= l && r <= b)
            return dat[k];
        else if (a < r && l < b)
            return FM(get(a, b, k*2, l, (l+r)>>1), get(a, b, k*2+1, (l+r)>>1, r));
        else
            return UNITY_MONOID;
    }
    inline Monoid get(int a, int b) { return get(a, b, 1, 0, SIZE); }
    inline Monoid operator [] (int a) { return get(a, a+1); }
    
    /* debug */
    void print() {
        for (int i = 0; i < SIZE; ++i) { cout << (*this)[i]; if (i != SIZE) cout << ","; }
        cout << endl;
    }
};

//モノイド同士の演算 fm
//モノイドへの作用 fa
//作用の合成 fl
auto fm = [](long long a, long long b) { return max(a, b); };
auto fa = [](long long &a, long long d) { a = max(a, d); };
auto fl = [](long long &d, long long e) { d = max(d, e); };
LazySegTree<long long, long long> seg(N+1, fm, fa, fl, 0, 0);
//-------------------------------------------------------------------------
//遅延評価セグ木（区間加算・区間和）
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
};