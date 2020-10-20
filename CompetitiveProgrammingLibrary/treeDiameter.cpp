// 木の直径(とr直径を成すrootではない頂点）を返す
// verify：https://atcoder.jp/contests/agc033/submissions/17545191
struct treeDiameter{
    int N;
    vector<vector<int>> G;
    int v;
    int diameter;
    treeDiameter(const int& N) : N(N), G(N), v(0), diameter(0){}

    void add_edge(int u, int v){
        G[u].emplace_back(v);
    }

    pair<int, int> bfs(int root){
        int dist = 0;
        int v = root;
        queue<tuple<int, int, int>> q;
        q.emplace(0, root, -1);
        while(!q.empty()){
            auto [d, cur, par] = q.front(); q.pop();
            if(d > dist){
                dist = d;
                v = cur;
            }
            for(int nv : G[cur]){
                if(nv == par) continue;
                q.emplace(d+1, nv, cur);
            }
        }
        return make_pair(dist, v);
    }
    void build(int root){
        pair<int, int> p = bfs(root);
        pair<int, int> res = bfs(p.second);
        diameter = res.first;
        v = res.second;
    }
};