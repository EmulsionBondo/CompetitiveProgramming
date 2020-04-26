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

void solve(){
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    --a, --b, --c;
    vector<int> p(m);
    vector<ll> cum(m+1);
    REP(i,m) cin >> p[i];
    sort(p.begin(), p.end());
    REP(i,m) cum[i+1] = cum[i] + p[i];
    
    vector<vector<int>> G(n);
    REP(i,m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> da(n, INF), db(n, INF), dc(n,INF);
    da[a] = db[b] = dc[c] = 0;
    auto bfs = [&](int s, vector<int> &d) -> void{
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto nv : G[cur]){
                if(d[nv] != INF) continue;
                d[nv] = d[cur] + 1;
                q.push(nv);
            }
        }
    };

    bfs(a, da);
    bfs(b, db);
    bfs(c, dc);

    ll ans = LINF;
    REP(i,n){
        if(da[i] + db[i] + dc[i] > m) continue;
        chmin(ans, cum[db[i]] + cum[da[i] + db[i] + dc[i]]);
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    REP(i,Q) solve();
}