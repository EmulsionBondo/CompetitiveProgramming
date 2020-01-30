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

ll dist[333][333];
ll hokyu[333][333];
ll A[101010], B[101010], C[101010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, L, Q;
    cin >> N >> M >> L;
    REP(i,N){
        REP(j,N){
            dist[i][j] = LINF;
            hokyu[i][j] = LINF;
        }
        dist[i][i] = 0;
        hokyu[i][i] = 0;
    }
    REP(i,M){
        cin >> A[i] >> B[i] >> C[i];
        --A[i], --B[i];
        chmin(dist[A[i]][B[i]], C[i]);
        chmin(dist[B[i]][A[i]], C[i]);
    }
    cin >> Q;
    REP(k,N) REP(i,N) REP(j,N) chmin(dist[i][j], dist[i][k] + dist[k][j]);
    REP(i,N) REP(j,N){
        if(i == j) continue;
        if(dist[i][j] <= L) chmin(hokyu[i][j], 1LL);
    }
    REP(k,N) REP(i,N) REP(j,N) chmin(hokyu[i][j], hokyu[i][k] + hokyu[k][j]);

    REP(i,Q){
        ll t, s;
        cin >> t >> s;
        --t, --s;
        if(hokyu[t][s] < LINF) cout << hokyu[t][s] - 1 << endl;
        else cout << -1 << endl;
    }
}
