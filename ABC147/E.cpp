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

bool dp[88][88][2*80*88];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W)), b(H, vector<int>(W));
    REP(i,H) REP(j,W) cin >> a[i][j];
    REP(i,H) REP(j,W) cin >> b[i][j];
    dp[0][0][abs(a[0][0] - b[0][0])] = true;

    REP(i,H) REP(j,W){
        REP(k,2*80*88){
            if(i>0){
                if(dp[i-1][j][k]){
                    dp[i][j][k+abs(a[i][j]-b[i][j])] = true;
                    dp[i][j][abs(k-abs(a[i][j]-b[i][j]))] = true;
                }
            }
            if(j>0){
                if(dp[i][j-1][k]){
                    dp[i][j][k+abs(a[i][j]-b[i][j])] = true;
                    dp[i][j][abs(k-abs(a[i][j]-b[i][j]))] = true;
                }
            }
        }
    }

    REP(i,2*80*88){
        if(dp[H-1][W-1][i]){
            cout << i << endl;
            return 0;
        }
    }
}