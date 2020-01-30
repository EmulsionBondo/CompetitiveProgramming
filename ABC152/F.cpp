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
//typedef vector<ll>vec;
//typedef vector<vec> mat;
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

vector<vector<pair<int, int>>> G;
vector<int> es;

bool dfs(int v, int tv, int par = -1){
    if(v == tv) return true;
    for(auto nv : G[v]){
        if(nv.first == par) continue;
        if(dfs(nv.first, tv, v)){
            es.push_back(nv.second);
            return true;
        }
    }
    return false;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N;
    G.resize(N);
    REP(i,N-1){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].emplace_back(b, i);
        G[b].emplace_back(a, i);
    }
    cin >> M;
    vector<ll> st(M);
    REP(i,M){
        int a, b;
        cin >> a >> b;
        --a, --b;
        es = vector<int>();
        dfs(a, b);
        for(auto e : es) st[i] |= (1LL << e);
    }
    ll ans = 0;
    REP(i, 1<<M){
        ll bits = 0;
        REP(j, M) if((i >> j) & 1) bits |= st[j];
        ll white = __builtin_popcountll(bits);
        if(__builtin_popcountll(i) % 2 == 0) ans += 1LL << (N - 1 - white);
        else ans -= 1LL << (N - 1 - white);
    }
    cout << ans << endl;
}