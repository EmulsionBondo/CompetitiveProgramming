//最大流(Dinic法)
//O(|E||V|^2)だけどグラフのサイズがある程度大きくても大丈夫な場合が多い
const int MAX_V = 2000005;
const int INF = 1 << 32;
// 辺を表す構造体 (行き先、　容量、　逆辺) 逆辺はインデックスでもつ
struct edge { int to, cap, rev; };
 
vector<edge> G[MAX_V]; // グラフの隣接リスト
int level[MAX_V]; // sからの距離(bfsで使う)
int iter[MAX_V]; // どこまで調べ終わったか(dfsで使う)
 
// from -> toへの容量capの辺をグラフに追加
void add_edge(int from, int to, int cap){
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)(G[from].size()-1)});
}
 
// sからの最短距離をBFSで計算
void bfs(int s){
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front(); que.pop();
        for(int i=0; i<(int)G[v].size(); i++){
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}
 
// 増加パスをDFSで探す
int dfs(int v, int t, int f){
    if(v == t) return f;
    for(int &i=iter[v]; i<(int)G[v].size(); i++){
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
// s -> tへの最大流を求める
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while((f=dfs(s, t, INF)) > 0){
            flow += f;
        }
    }
}