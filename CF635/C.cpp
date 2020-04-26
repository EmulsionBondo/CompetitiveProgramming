#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

vector<int> sz;
vector<vector<int>> G;

void dfs(int v, int par){
    for(auto nv : G[v]){
        if(nv == par) continue;
        dfs(nv, v);
        sz[v] += sz[nv];
    }
    sz[v]++;
}

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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    sz.resize(n);
    G.resize(n);
    vector<int> deg(n);
    REP(i,n-1){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[v]++, deg[u]++;
    }
    LCA<vector<vector<int>>> lca(G);
    lca.build();
    priority_queue<tuple<int,int,int>> pq;
    ll ans = 0;
    dfs(0, -1);
    // REP(i,n) cout << sz[i] << " ";
    // cout << endl;
    vector<bool> used(n);
    for(int i=1;i<n;i++) if(deg[i] == 1) pq.emplace(lca.dist(0,i)-(sz[i] - 1), i, -1);
    while(k > 0 && !pq.empty()){
        auto [dist, cur, par] = pq.top(); pq.pop();
        if(used[cur]) continue;
        ans += dist;
        k--;
        used[cur] = true;
        for(auto nv : G[cur]){
            if(nv == par) continue;
            pq.emplace(lca.dist(0, nv)-(sz[nv] - 1), nv, cur);
        }
    }
    cout << endl;
    cout << ans << endl;
}