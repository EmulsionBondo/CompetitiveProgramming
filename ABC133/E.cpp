#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
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

int N,K;

ll dfs(int now, int from){
    int color;
    if(from == -1){
        color = K-1;
    }
    else color = K-2;
    if(K<G[now].size()) return 0;
    else{
        ll res = 1;
        for(auto e:G[now]){
            if(e==from) continue;
            res *= color;
            color--;
            res %= MOD;
        }
        for(auto e:G[now]){
            if(e==from) continue;
            res *= dfs(e,now);
            res %= MOD;
        }
        return res;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>K;
    G.resize(N);
    REP(i,N-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ll ans = K*dfs(0,-1);
    ans %= MOD;
    cout<<ans<<endl;
}
