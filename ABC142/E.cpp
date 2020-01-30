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
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

ll a[1010], b[1010];
ll C[1010][20];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    REP(i,M){
        cin >> a[i] >> b[i];
        REP(j,b[i]){
            cin >> C[i][j];
            C[i][j]--;
        }
    }
    vector<ll> dp((1<<N), LINF);
    dp[0] = 0;
    REP(i,(1<<N)){
        REP(j,M){
            int tmp = i;
            REP(k, b[j]){
                tmp |= (1 << C[j][k]);
            }
            chmin(dp[tmp], dp[i] + a[j]);
        }
    }
    ll ans = dp[(1<<N)-1];
    if(ans == LINF) cout << -1 << endl;
    else cout << ans << endl;
}
