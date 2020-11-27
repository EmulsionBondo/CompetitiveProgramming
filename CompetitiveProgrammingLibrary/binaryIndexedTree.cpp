// 0-indexed verify : https://codeforces.com/contest/1005/submission/99709096
template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0;                       // to be set
    vector<Abel> dat;

    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }

    /* a is 1-indexed */
    inline void add1(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum1(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum1(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }

    /* a is 0-indexed */
    inline void add(int a, Abel x){
        add1(a + 1, x);
    }

    /* [0, a), a is 0-indexed */
    inline Abel sum(int a){
        return sum1(a);
    }

    /* [a, b), a is 0-indexed */
    inline Abel sum(int a, int b){
        return sum1(b) - sum1(a);
    }

    /* get k-th element (k is 0-indexed) */
    int kth_element(long long k) {
        ++k;
        int res = 0;
        int N = 1; while (N < (int)dat.size()) N *= 2;
        for (int i = N / 2; i > 0; i /= 2) {
            if (res + i < (int)dat.size() && dat[res + i] < k) {
                k = k - dat[res + i];
                res = res + i;
            }
        }
        return res + 1;
    }

    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum1(i, i + 1) << ",";
        cout << endl;
    }
};