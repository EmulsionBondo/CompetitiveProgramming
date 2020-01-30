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

int dist[101010][3];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    REP(i,m){
        int a, b;
        cin >> a >> b;
        --a, --b;
        to[a].push_back(b);
    }
    int sv, tv;
    cin >> sv >> tv;
    --sv, --tv;
    REP(i,n) REP(j,3) dist[i][j] = INF;
    queue<P> q;
    q.push(P(sv,0));
    dist[sv][0] = 0;
    while(!q.empty()){
        int v = q.front().first;
        int l = q.front().second;
        q.pop();
        for(int u : to[v]){
            int nl = (l+1) % 3;
            if(dist[u][nl] != INF) continue;
            dist[u][nl] = dist[v][l] + 1;
            q.push(P(u,nl));
        }
    }
    int ans = dist[tv][0];
    if(ans == INF) ans = -1;
    else ans /= 3;
    cout << ans << endl;
}