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
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i,n){
        cin >> a[i];
        --a[i];
    }
    vector<vector<int>> idx(200);
    vector<vector<int>> cum(200, vector<int>(n+1));
    REP(i,n){
        REP(j,200) cum[j][i+1] = cum[j][i];
        cum[a[i]][i+1]++;
        idx[a[i]].emplace_back(i);
    }
    int ans = 0;
    REP(i,200){
        int sz = idx[i].size();
        chmax(ans, sz);
        if(sz <= 1) continue;

        REP(j,sz){
            if(idx[i][j] >= idx[i][sz-j-1]) break;
            int len = 0;
            REP(k, 200){
                chmax(len, cum[k][idx[i][sz-j-1]] - cum[k][idx[i][j]+1]);
            }
            chmax(ans, (j+1) * 2 + len);
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
   REP(i,Q) solve();
}