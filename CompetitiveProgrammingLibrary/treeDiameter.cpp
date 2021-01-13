// 木の直径(とr直径を成すrootではない頂点）を返す
// verify：https://atcoder.jp/contests/agc033/submissions/19410044
// verify（木の中心）:https://codeforces.com/contest/1092/submission/104167127
struct treeDiameter{
    int N;
    vector<int> dist;
    vector<vector<int>> G;
    int v, w; // 直径のパスのv, w
    int diameter; // パスv, wの直径の長さ
    treeDiameter(const int& N) : N(N), dist(N, INF), G(N), v(0), diameter(0){}

    void add_edge(int u, int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    pair<int, int> bfs(int root, vector<int>& dist){
        int v = root;
        int ma = 0;
        queue<tuple<int, int, int>> q;
        q.emplace(0, root, -1);
        while(!q.empty()){
            auto [d, cur, par] = q.front(); q.pop();
            dist[cur] = d;
            if(dist[cur] > ma){
                ma = dist[cur];
                v = cur;
            }
            for(int nv : G[cur]){
                if(nv == par) continue;
                q.emplace(d+1, nv, cur);
            }
        }
        return make_pair(ma, v);
    }

    void build(int root){
        dist.assign(N, INF);
        pair<int, int> p = bfs(root, dist);
        w = p.second;
        dist.assign(N, INF);
        pair<int, int> res = bfs(p.second, dist);
        diameter = res.first;
        v = res.second;
    }

    // 木の中心を求める（最遠距離を最小にする点、高々2個）
    vector<int> get_center(int root){
        vector<int> res;
        vector<int> dist_v(N, INF);
        vector<int> dist_w(N, INF);
        auto res_v = bfs(v, dist_v);
        auto res_w = bfs(w, dist_w);
        for(int i=0;i<N;i++){
            if(dist_v[i] == diameter / 2 and dist_w[i] == diameter - diameter / 2){
                res.emplace_back(i);
            }
        }
        return res;
    }
};