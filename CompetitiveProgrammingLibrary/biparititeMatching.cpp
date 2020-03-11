//二部最大マッチング
struct BipartiteMatching {
    vector<vector<int>> E; int n, m; vector<int> match, dist;
    void init(int _n,int _m){n=_n,m=_m;E.resize(n+m+2);match.resize(n+m+2);dist.resize(n+m+2);}
    bool bfs() {
        queue<int> que;
        for(int i=1;i<n+1;i++) {
            if (!match[i]) dist[i] = 0, que.push(i);
            else dist[i] = INF;
        }
        dist[0] = INF;
        while (!que.empty()) {
            int u = que.front(); que.pop();
            if (u) for(auto v:E[u]) if (dist[match[v]] == INF) {
                dist[match[v]] = dist[u] + 1;
                que.push(match[v]);
            }
        }
        return (dist[0] != INF);
    }
    bool dfs(int u) {
        if (u) {
            for(auto v:E[u]) if (dist[match[v]] == dist[u] + 1) if (dfs(match[v])) {
                match[v] = u; match[u] = v;
                return true;
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }
    void add(int a, int b) { b += n; E[a + 1].push_back(b + 1); E[b + 1].push_back(a + 1); }
    int whois(int x) { return match[x + 1] - 1; }
    int solve() {
        for(int i=0;i<n+m+1;i++) match[i] = 0;
        int res = 0;
        while (bfs()) for(int i=1;i<n+1;i++) if (!match[i] && dfs(i)) res++;
        return res;
    }
};
//使い方
BipartiteMatching bm;
bm.init(N, N);
rep(i, 0, N) rep(j, 0, N) {
    if (A[i] < C[j] and B[i] < D[j]) bm.add(i, j);//条件を満たすとき追加する(iとjを結ぶ辺をグラフに追加)
}
cout << bm.solve() << endl;