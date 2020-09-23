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
// AtCoderLibrary
template<class Cap> struct Dinic{
private:
    int _n;
    struct _edge{
        int to, rev;
        Cap cap;
    };
    vector<pair<int, int>> pos;
    vector<vector<_edge>> g;
public:
    Dinic() : _n(0) {}
    Dinic(int n): _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap){
        assert(0 <= from and from < _n);
        assert(0 <= to and to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if(from == to) to_id++;
        g[from].emplace_back(_edge{to, to_id, cap});
        g[to].emplace_back(_edge{from, from_id, 0});
        return m;
    }

    struct edge{
        int from, to;
        Cap cap, flow;
    };

    template <class T> struct simple_queue {
        std::vector<T> payload;
        int pos = 0;
        void reserve(int n) { payload.reserve(n); }
        int size() const { return int(payload.size()) - pos; }
        bool empty() const { return pos == int(payload.size()); }
        void push(const T& t) { payload.push_back(t); }
        T& front() { return payload[pos]; }
        void clear() {
            payload.clear();
            pos = 0;
        }
        void pop() { pos++; }
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }

    vector<edge> edges(){
        int m = int(pos.size());
        vector<edge> result;
        for(int i=0;i<m;i++){
            result.emplace_back(get_edge(i));
        }
        return result;
    }
     void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }
    Cap flow(int s, int t) {
        return flow(s, t, numeric_limits<Cap>::max());
    }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        vector<int> level(_n), iter(_n);
        simple_queue<int> que;

        auto bfs = [&]() {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d =
                    self(self, e.to, min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) break;
            }
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                Cap f = dfs(dfs, t, flow_limit - flow);
                if (!f) break;
                flow += f;
            }
        }
        return flow;
    }

    vector<bool> min_cut(int s) {
        vector<bool> visited(_n);
        simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }
};