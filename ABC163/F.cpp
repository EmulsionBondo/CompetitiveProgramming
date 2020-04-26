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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<int> C(N);
    vector<vector<int>> G(N);
    REP(i,N) cin >> C[i], C[i]--;
    REP(i,N-1){
        int u, v;
        cin >> u >> v;
        G[--u].push_back(--v);
        G[v].push_back(u);
    }
    vector<vector<int>> res(N);
    vector<int> cnt(N);
    vector<map<int, int>> dp(N);
    auto dfs = [&](auto && self, int v, int par) -> void{
        for(auto nv : G[v]){
            if(nv == par) continue;
            self(self, nv, v);
            cnt[v] += cnt[nv];

            int tmpCnt = cnt[nv];
            if(dp[nv].count(C[nv])) tmpCnt -= dp[nv][C[v]];
            res[C[v]].push_back(tmpCnt);

            //merge technique
            if(dp[v].size() < dp[nv].size()) swap(dp[v], dp[nv]);
            for(auto &x : dp[nv]) dp[v][x.first] += x.second;
        }
        cnt[v]++;
        dp[v][C[v]] = cnt[v];
    };

    dfs(dfs, 0, -1);
    REP(i,N) res[i].push_back(N - dp[0][i]);
    vector<ll> ans(N, N * (N + 1) / 2);
    REP(i,N) for(ll c : res[i]) ans[i] -= c * (c + 1) / 2;

    REP(i,N) cout << ans[i] << endl;
}
