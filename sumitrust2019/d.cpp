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

vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(10, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 10; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'0'] = i;
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    vector<vector<int>> next = calcNext(S);
    vector<vector<ll>> dp(N+1, vector<ll>(4));
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for(int k = 0;k <= 2; k++){
            for (int j = 0; j < 10; ++j) {
                if (next[i][j] >= N) continue;
                add(dp[next[i][j] + 1][k+1], dp[i][k]);
            }
        }
    }
    ll res = 0;
    REP(i, N+1){
        add(res, dp[i][3]);
    }
    cout << res << endl;
}
