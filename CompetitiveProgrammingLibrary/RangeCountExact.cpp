// 区間の値のカウント
// https://atcoder.jp/contests/abc166/submissions/12731897
template <typename T>
class RangeCountExact {
    map<T, int> mp;
    vector<vector<int>> idxs;
 
    int get(int r, T x) {
        if (mp.count(x) == 0) return 0;
        int a = mp[x];
        return lower_bound(idxs[a].begin(), idxs[a].end(), r) - idxs[a].begin();
    }
 
public:
    RangeCountExact(const vector<T> &as) {
        for (auto &a : as) mp[a];
        int N = 0;
        for (auto &p : mp) {
            p.second = N++;
        }
        idxs.resize(N);
        for (int i = 0; i < as.size(); i++) {
            idxs[mp[as[i]]].push_back(i);
        }
    }
 
    // [l, r)
    int get(int l, int r, T x) { return get(r, x) - get(l, x); }
};