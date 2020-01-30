#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VRSORT(v) sort(v.rbegin(), v.rend());//vectorの降順ソート
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

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

const int V = 100005;
vector<int> to[V*2];
bool visited[V*2];

vector<int> cnt;

void dfs(int v){
    if(visited[v]) return;
    visited[v]=true;
    cnt[v/V]++;
    for(int nv:to[v]) dfs(nv);
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    REP(i,n){
        int x,y;
        cin>>x>>y;
        y+=V;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    ll ans = 0;
    REP(i,V*2){
        if(visited[i]) continue;
        cnt = vector<int>(2);
        dfs(i);
        ans += (ll)cnt[0]*cnt[1];
    }
    ans -= n;
    cout<<ans<<endl;
}