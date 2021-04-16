// HL分解
// vid[v] := 行きがけ順の頂点vの番号
// 辺属性のときのセグ木の初期化はseg.set(max(hld.vid[a], hld.vid[b]), x)
// verify（部分木頂点属性） :https://atcoder.jp/contests/abc187/submissions/19367612
// verify（パス辺属性）:https://atcoder.jp/contests/past202004-open/submissions/19367728
class HLD{
    void dfs_sz(int v, int p){
        if(g[v].size() and g[v][0] == p) swap(g[v][0], g[v].back());
        for(auto &to : g[v]){
            if(to == p) continue;
            dfs_sz(to, v);
            sz[v] += sz[to];
            if(sz[to] > sz[g[v][0]]) swap(to, g[v][0]);
        }
    }

    void dfs_hld(int v, int p, int &k){
        par[v] = p; vid[v] = k++, inv[vid[v]] = v;
        for(auto to : g[v]){
            if(to == p) continue;
            head[to] = (to == g[v][0] ? head[v] : to);
            dfs_hld(to, v, k);
        }
    }
public:
    int n;
    vector<vector<int>> g;
    vector<int> vid, head, sz, par, inv;
    HLD() {}
    HLD(int sz) : n(sz), g(n), vid(n, -1), head(n), sz(n, 1), par(n), inv(n) {}

    void add_edge(int u, int v){
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    void build(vector<int> rs=vector<int>(1,0)){
        int k = 0;
        for(int r : rs){
            dfs_sz(r, -1);
            head[r] = r;
            dfs_hld(r, -1, k);
        }
    }

    // パスu-vの頂点属性クエリ　区間[l, r) を返す
    vector<pair<int, int>> for_each(int u, int v){
        vector<pair<int, int>> res;
        while(1){
            if(vid[u] > vid[v]) swap(u, v);
            res.emplace_back(max(vid[head[v]], vid[u]), vid[v] + 1);
            if(head[u] != head[v]) v = par[head[v]];
            else break;
        }
        return res;
    }

    // パスu-vの辺属性クエリ 区間[l, r）を返す
    vector<pair<int, int>> for_each_edge(int u, int v){
        vector<pair<int, int>> res;
        while(1){
            if(vid[u] > vid[v]) swap(u, v);
            if(head[u] != head[v]){
                res.emplace_back(vid[head[v]], vid[v] + 1);
                v = par[head[v]];
            }
            else{
                if(u != v) res.emplace_back(vid[u] + 1, vid[v] + 1);
                break;
            }
        }
        return res;
    }

    // 頂点uの部分木に対する頂点属性クエリ 区間[l, r) を返す
    pair<int, int> subtree(int u){
        return {vid[u], vid[u] + sz[u]};
    }

    // 頂点uの部分木に対する辺属性クエリ 区間[l, r) を返す
    pair<int, int> subtree_edge(int u){
        return {vid[u] + 1, vid[u] + sz[u]};
    }

    int lca(int u, int v){
        while(1){
            if(vid[u] > vid[v]) swap(u, v);
            if(head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
};