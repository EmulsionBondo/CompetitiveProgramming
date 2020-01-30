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

char fi[22][22];
int H, W;
int ans = 0;

int check(int sh, int sw){
    int memo[22][22];
    REP(i,22) REP(j,22) memo[i][j] = INF;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.emplace(0, sh, sw);
    memo[sh][sw] = 0;
    while(!q.empty()){
        ll c;
        int h, w;
        tie(c, h, w) = q.top(); q.pop();
        REP(i,4){
            int nh = h + dy[i];
            int nw = w + dx[i];
            if(!(0 <= nh && nh < H && 0 <= nw && nw < W)) continue;
            if(fi[nh][nw] == '#') continue;
            if(memo[nh][nw] > c + 1){
                memo[nh][nw] = c + 1;
                q.emplace(c + 1, nh, nw);
            }
        }
    }
    int res = 0;
    REP(i,H) REP(j,W){
        if(memo[i][j] != INF) chmax(res, memo[i][j]);
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    REP(i,H) REP(j,W) cin >> fi[i][j];
    REP(i,H) REP(j,W){
        if(fi[i][j] == '#') continue;
        int tmp = check(i,j);
        chmax(ans, tmp);
    }
    cout << ans << endl;
}
