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
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;
    //set<int> st[101010];
    UnionFind uf(N);
    vector<int> ans(N);
    vector<int> friends(N);
    REP(i,M){
        int A, B;
        cin >> A >> B;
        A--, B--;
        uf.unite(A, B);
        friends[A]++;
        friends[B]++;
    }

    REP(i,N) ans[i] = uf.size(i) - 1 - friends[i];

    REP(i,K){
        int A, B;
        cin >> A >> B;
        A--, B--;
        if(uf.issame(A, B)) ans[A]--, ans[B]--;
    }

    REP(i,N) cout << ans[i] << " ";
    cout << endl;
}