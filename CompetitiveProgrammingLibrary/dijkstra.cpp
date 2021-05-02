//ダイクストラ
struct edge{ll to, cost;};
vector<vector<edge>> G;

vector<ll> dijkstra(ll s,ll n,vector<vector<edge>> G){
    vector<ll> d={};
    d.resize(n);
    REP(i,n) d[i]=LINF;
    // 最短距離firstが小さい順に取り出せるようにする
    priority_queue<LP, vector<LP>, greater<LP>> que;
    d[s] = 0;// スタート地点を0で初期化
    que.push(LP(0,s));// キューに初期位置のコスト、初期位置をpush

    while(que.size()){
        LP p = que.top();que.pop(); // p: 今の{最短距離、頂点番号}
        ll v = p.second;//今の頂点番号
        if(d[v] < p.first) continue;// 今見ている頂点の歴代最小距離 < 今見ている頂点の最短距離
        for(int i=0; i < G[v].size();i++){// 今の頂点に隣接する頂点を調べる
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){// 遷移先の頂点の歴代最小距離 > 今の距離 + 遷移コスト
                d[e.to] = d[v] + e.cost;// 歴代最小距離の更新
                que.push(P(d[e.to],e.to));// 更新した遷移先の頂点をキューに突っ込む
            }
        }
    }
    return d;
}
//-------------------------------------------------------------------------
// verify: https://atcoder.jp/contests/gigacode-2019/submissions/22250800
template<class T> class Dijkstra {
public:
	int N;
	T inf;
	vector<T> cost;
	vector<vector<pair<T, int>>> edge;

	Dijkstra(const int N, T inf) : N(N), inf(inf),cost(N), edge(N) {
	}

	void make_edge(int from, int to, T w) {
		edge[from].push_back({ w,to });
	}

	void solve(int start) {
		for(int i = 0; i < N; ++i) cost[i] = inf;

		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
		cost[start] = 0;
		pq.push({ 0,start });

		while (!pq.empty()) {
			T v = pq.top().first;
			int from = pq.top().second;
			pq.pop();
			if(cost[from] < v) continue;
			for (auto u : edge[from]) {
				T w = v + u.first;
				int to = u.second;
				if (w < cost[to]) {
					cost[to] = w;
					pq.push({ w,to });
				}
			}
		}
		return;
	}
};
