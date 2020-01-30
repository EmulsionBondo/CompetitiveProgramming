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
typedef vector<vec> mat;
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

int N;
vector<vector<int>> G;
map<pair<int,int>,int> mp;
int ma = 0;

void dfs(int n, int pre, int col){
    for(auto nv : G[n]){
        if(nv == pre) continue;
        col++;
        col %= ma;
        int a = n, b = nv;
        if(a > b) swap(a,b);
        mp[{a,b}] = col;
        dfs(nv, n, col);
        //cout << pre << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    G.resize(N);
    vector<int> a(N-1),b(N-1);
    REP(i,N-1){
        cin >> a[i] >> b[i];
        --a[i], --b[i];
        if(a[i] > b[i]) swap(a[i], b[i]);
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    int idx = 0;
    REP(i,N){
        if(chmax(ma, (int)G[i].size())) idx = i;
    }

    dfs(idx, -1, 0);
    cout << ma << endl;
    REP(i,N-1) cout << mp[{a[i], b[i]}] + 1 << endl;
}