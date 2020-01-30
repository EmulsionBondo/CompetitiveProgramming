#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
//typedef vector<unsigned int>vec;
typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef vector<vector<int>> Graph;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
//const ll MOD = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

template< typename G >
struct LCA{
    const int LOG;
    vector< int > depth;
    const G &g;
    vector< vector< int > > table;

   LCA(const G &g) : g(g), depth(g.size()), LOG(32 - __builtin_clz(g.size())) {
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
        dfs(0, -1, 0);
        for(int k = 0; k + 1 < LOG; k++) {
            for(int i = 0; i < table[k].size(); i++) {
                if(table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    int get(int u, int v) {
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
		int lca_ = get(u, v);
		return depth[u] + depth[v] - 2 * depth[lca_];
	}
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, u, v;
    cin >> N >> u >> v;
    --u, --v;
    vector<vector<int>> G(N);
    REP(i,N-1){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    LCA<vector<vector<int>>> lca(G);
    lca.build();

    int ans = 0;
    REP(i,N){
        int t = lca.get(i, u);
        if(lca.dist(t, u) < lca.dist(t, v)) chmax(ans, lca.dist(i, v) - 1);
    }
    cout << ans << endl;
}