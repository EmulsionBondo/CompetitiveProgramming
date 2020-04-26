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
    REP(i,m) cin >> p[i];
    vector<vector<pair<int, int>>> G(n);
    REP(i,m){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }
    vector<pair<int, int>> prev(n, {-1, -1});
    vector<bool> used(n);
    queue<pair<int, int>> q;
    q.emplace(a, -1);
    while(!q.empty()){
        auto[cur, pre] = q.front();
        q.pop();
        if(used[cur]) continue;
        used[cur] = true;

        if(cur == b) break;
        for(auto [to, Edge] : G[cur]){
            if(to == pre) continue;
            if(used[to]) continue;
            prev[to] = {cur, Edge};
            q.emplace(to, cur);
        }
    }
    vector<int> cnt(m);//どの辺を何回通ったか

    auto cur = prev[b];
    while(cur.first != -1){
        cnt[cur.second]++;
        cur = prev[cur.first];
        // cout << cur.first << endl;
    }

    used = vector<bool>(n);
    prev = vector<pair<int, int>>(n, {-1, -1});
    q = queue<pair<int, int>>();
    q.emplace(b, -1);
    while(!q.empty()){
        auto[cur, pre] = q.front();
        q.pop();
        if(used[cur]) continue;
        used[cur] = true;
        if(cur == c) break;

        for(auto [to, Edge] : G[cur]){
            if(to == pre) continue;
            if(used[to]) continue;
            cerr << "from : " << cur << ", to : " << to << endl;
            prev[to] = {cur, Edge};
            q.emplace(to, cur);
        }
    }

    cur = prev[c];

    while(cur.first != -1){
        cout << cur.first << " " << cur.second << endl;
        cnt[cur.second]++;
        cur = prev[cur.first];
    }

    sort(cnt.rbegin(), cnt.rend());
    sort(p.begin(), p.end());
    ll ans = 0;
    REP(i,m){
        if(cnt[i] == 0) break;
        // cout << cnt[i] << " " << p[i] << endl;
        ans += cnt[i] * p[i];
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