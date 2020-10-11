// 転倒数を求める
// vector<T> xを vector<T> yにするための最小隣接swap回数
// 座圧を勝手にやってくれる（少し遅い）
// xをyに出来ないときは -1 を返す
// verify: https://atcoder.jp/contests/chokudai_S001/submissions/17334405
// verify: https://codeforces.com/contest/1430/submission/95257884
// verify: https://codeforces.com/contest/1420/submission/95259709
template <class Abel> struct BIT {
    const Abel UNITY_SUM = 0;                       // to be set
    vector<Abel> dat;

    /* [1, n] */
    BIT(int n) : dat(n + 1, UNITY_SUM) { }
    void init(int n) { dat.assign(n + 1, UNITY_SUM); }

    /* a is 1-indexed */
    inline void add(int a, Abel x) {
        for (int i = a; i < (int)dat.size(); i += i & -i)
            dat[i] = dat[i] + x;
    }

    /* [1, a], a is 1-indexed */
    inline Abel sum(int a) {
        Abel res = UNITY_SUM;
        for (int i = a; i > 0; i -= i & -i)
            res = res + dat[i];
        return res;
    }

    /* [a, b), a and b are 1-indexed */
    inline Abel sum(int a, int b) {
        return sum(b - 1) - sum(a - 1);
    }

    /* debug */
    void print() {
        for (int i = 1; i < (int)dat.size(); ++i) cout << sum(i, i + 1) << ",";
        cout << endl;
    }
};

template<class T>
ll inversionNumber(vector<T> &x, vector<T> &y){
    // xをyにするために必要な隣接swapの回数（転倒数）を返す
    // 同じ値が含まれる場合、最小回数を返す
    int sz = x.size();

    assert(sz == (int)y.size());

    BIT<ll> bit(sz);

    // 座圧
    map<T, vector<int>> idx;
    for(int i=sz-1;i>=0;i--){
        idx[x[i]].emplace_back(i);
    }
    ll res = 0;
    for(int i=0;i<sz;i++){
        vector<int> &v = idx[y[i]];
        // xをyに出来ない時 -1 を返す
        if(v.empty()) return -1;

        int id = v.back(); v.pop_back();
        res += id - bit.sum(id);
        bit.add(id+1, 1);
    }
    return res;
}