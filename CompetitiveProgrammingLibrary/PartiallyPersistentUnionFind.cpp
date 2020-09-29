struct PartiallyPersistentUnionFind {
    vector<int> par, last;
    vector<vector<pair<int, int>>> history;

    PartiallyPersistentUnionFind(int n) : par(n, -1), last(n, -1), history(n) {
        for (auto &vec : history) vec.emplace_back(-1, -1);
    }
    void init(int n) {
        par.assign(n, -1); last.assign(n, -1); history.assign(n, vector<pair<int, int>>());
        for (auto &vec : history) vec.emplace_back(-1, -1);
    }

    int root(int t, int x) {
        if (last[x] == -1 || t < last[x]) return x;
        return root(t, par[x]);
    }

    bool issame(int t, int x, int y) {
        return root(t, x) == root(t, y);
    }

    bool unite(int t, int x, int y) {
        x = root(t, x); y = root(t, y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        last[y] = t;
        history[x].emplace_back(t, par[x]);
        return true;
    }

    int size(int t, int x) {
        x = root(t, x);
        return -prev(lower_bound(history[x].begin(), history[x].end(), make_pair(t, 0)))->second;
    }
};