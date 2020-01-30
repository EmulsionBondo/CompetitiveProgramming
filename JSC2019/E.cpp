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

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

struct edge{
    ll from, to, cost;
    edge(ll s, ll d, ll w) : from(s), to(d), cost(w){}
    
    bool operator < (const edge& x) const {
        return cost < x.cost;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, H, W;
    cin >> N >> H >> W;
    vector<edge> e;

    UnionFind uf(H + W + 10);

    REP(i,N){
        ll R, C, A;
        cin >> R >> C >> A;
        e.emplace_back(R, C+H, -A);
    }

    sort(e.begin(), e.end());
    
    ll ans = 0;

    REP(i,N){
        if(!uf.issame(e[i].from, e[i].to)){
            ans += e[i].cost;
            uf.unite(e[i].from, e[i].to);
        }
        else{
            if(!uf.issame(e[i].from, 0)){
                ans += e[i].cost;
                uf.unite(e[i].from,0);
            }
        }
    }
    cout << ans * (-1) << endl;
}
