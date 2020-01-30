#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 3e18+7
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-10;

vector<vector<int>> G;
vector<ll> sum(202020);

void dfs(int v, int p, ll s){
    sum[v] += s;
    for(auto nv : G[v]){
        if(nv == p) continue;
        dfs(nv,v,sum[v]);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q;
    cin >> N >> Q;
    G.resize(N);
    REP(i,N-1){
        int a,b;
        cin >> a >> b;
        --a,--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    REP(i,Q){
        int p,x;
        cin >> p >> x;
        --p;
        sum[p] += x;
    }
    
    dfs(0,-1,0);
    REP(i,N) cout << sum[i] << " ";
    cout << endl;
}
