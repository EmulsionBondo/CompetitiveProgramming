#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())//vectorの降順ソート
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


int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

struct edge{ll to, cost;};
vector<edge> tree[202020];
bool visit[101010];
int top[202020];
vector<int> d;
int cnt;

void dfs(int v){
    if(visit[v]==true) return;
    visit[v]=true;
    top[v]=d[cnt];
    cnt++;
    for(auto x:tree[v]){
        dfs(x.to);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    REP(i,n-1){
        int a,b;
        cin>>a>>b;
        --a,--b;
        edge e;
        e.to = b,e.cost=0;
        tree[a].push_back(e);
        e.to = a,e.cost=0;
        tree[b].push_back(e);
    }
    
    REP(i,n){
        int tmp;cin>>tmp;
        d.push_back(tmp);
    }
    VRSORT(d);
    //top[0]=d[0];
    dfs(0);
    int ans=0;
    for(int i=1;i<n;i++) ans+=d[i];
    cout<<ans<<endl;
    REP(i,n) cout<<top[i]<<" ";
    cout<<endl;
}