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

int dp[1010101][2];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int ans = 0;
    reverse(S.begin(), S.end());
    int N = S.size();
    REP(i,1010101) dp[i][0] = dp[i][1] = INF;
    dp[0][0] = 0;
    REP(i,N){
        int a = S[i] - '0';
        chmin(dp[i+1][0], min(dp[i][0], dp[i][1]) + a);
        chmin(dp[i+1][1], min(dp[i][0] + 11 - a, dp[i][1] + 9 - a));
    }
    cout << min(dp[N][0], dp[N][1]) << endl;
}