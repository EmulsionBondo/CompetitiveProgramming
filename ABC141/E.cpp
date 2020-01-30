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
typedef vector<unsigned int>vec;
typedef vector<vec> mat;
typedef vector<vector<int>> Graph;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

vector<vector<int>> G;
bool used[101010];
ll dp[101010][2];
int root[101010];

void dfs(int v){
    for(auto nv : G[v]) if(nv != root[v]){
        root[nv] = v;
        dfs(nv);
    }
}

void solve(int i){
    if(used[i]) return;
    used[i] = true;
    dp[i][0] = 1;
    dp[i][1] = 1;
    for(auto ni : G[i]){
        if(ni == root[i]) continue;
        solve(ni);
        dp[i][0] = dp[i][0] * (dp[ni][0] + dp[ni][1]) % MOD;
        dp[i][1] = dp[i][1] * dp[ni][0] % MOD;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    G.resize(N+1);
    REP(i,N-1){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    REP(i,N+1) root[i] = -1;
    dfs(1);
    solve(1);
    ll ans = (dp[1][0] + dp[1][1]) % MOD;
    cout << ans << endl;
}
