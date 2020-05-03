//最小共通祖先
//構築(VlogV),　クエリ(logV)
//verify(root) : https://atcoder.jp/contests/past201912-open/submissions/9203097
//verify(dist) : https://atcoder.jp/contests/abc148/submissions/9096709
template< typename G >
struct LCA{
    const int LOG;
    vector< int > depth;
    const G &g;
    vector< vector< int > > table;
    const int root;
    LCA(const G &g, int root = 0) : g(g), depth(g.size()), LOG(32 - __builtin_clz(g.size())), root(root) {
        table.assign(LOG, vector< int >(g.size(), -1));
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        depth[idx] = d;
        for(auto &to : g[idx]) {
            if(to != par) dfs(to, idx, d + 1);
        }
    }

    void build() {
        dfs(root, -1, 0);
        for(int k = 0; k + 1 < LOG; k++) {
            for(int i = 0; i < table[k].size(); i++) {
                if(table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int lca(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        for(int i = LOG - 1; i >= 0; i--) {
            if(((depth[v] - depth[u]) >> i) & 1) v = table[i][v];
        }
        if(u == v) return u;
        for(int i = LOG - 1; i >= 0; i--) {
            if(table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        return table[0][u];
    }

    int dist(int u, int v) {
		int lca_ = lca(u, v);
		return depth[u] + depth[v] - 2 * depth[lca_];
	}
};

// LCAでダブリングしながら辺の最大コストを管理する
// 上記のものだと-1になる場合がある（普通に使う分には問題なさそう？）
// verify:https://github.com/EmulsionBondo/CompetitiveProgramming/wiki/past202004_o
template< typename G >
struct LCA{
    const int LOG;
    vector< int > depth;
    const G &g;
    vector< vector< int > > table;
    vector<vector<int>> ma;
    const int root;
    LCA(const G &g, int root = 0) : g(g), depth(g.size()), LOG(32 - __builtin_clz(g.size())), root(root) {
        table.assign(LOG, vector< int >(g.size(), -1));
        ma.assign(LOG, vector<int>(g.size(), 0));
    }
 
    void dfs(int idx, int par, int d, int c) {
        table[0][idx] = par;
        depth[idx] = d;
        ma[0][idx] = c;
        for(auto &to : g[idx]) {
            if(to.first != par) dfs(to.first, idx, d + 1, to.second);
        }
    }
 
    void build() {
        dfs(root, -1, 0, 0);
        for(int k = 0; k + 1 < LOG; k++) {
            for(int i = 0; i < table[k].size(); i++) {
                if(table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
                int next = table[k][i];
                if(next == -1) next = 0;
                chmax(ma[k+1][i], max(ma[k][i], ma[k][next]));
            }
        }
    }
 
    // int lca(int u, int v) {
    //     if(depth[u] > depth[v]) swap(u, v);
    //     for(int i = LOG - 1; i >= 0; i--) {
    //         if(((depth[v] - depth[u]) >> i) & 1) v = table[i][v];
    //     }
    //     if(u == v) return u;
    //     for(int i = LOG - 1; i >= 0; i--) {
    //         if(table[i][u] != table[i][v]) {
    //             u = table[i][u];
    //             v = table[i][v];
    //         }
    //     }
    //     return table[0][u];
    // }
 
    pair<int, int> lca(int u, int v) {
        int res = 0;
        if(depth[u] > depth[v]) swap(u, v);
        for(int i = LOG - 1; i >= 0; i--) {
            if(((depth[v] - depth[u]) >> i) & 1){
                chmax(res, ma[i][v]);
                v = table[i][v];
            }
        }
        if(u == v) return {u, res};
        for(int i = LOG - 1; i >= 0; i--) {
            if(table[i][u] != table[i][v]) {
                chmax(res, ma[i][u]);
                chmax(res, ma[i][v]);
                u = table[i][u];
                v = table[i][v];
            }
        }
        return {table[0][u], max({res, ma[0][u], ma[0][v]})};
    }
 
    int dist(int u, int v) {
		int lca_ = lca(u, v);
		return depth[u] + depth[v] - 2 * depth[lca_];
	}
};