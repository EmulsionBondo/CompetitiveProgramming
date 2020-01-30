#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;

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

ll dp[22222];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, N;
    cin >> H >> N;
    vector<int> A(N), B(N);
    REP(i,N) cin >> A[i] >> B[i];
    REP(i,22222) dp[i] = LINF;
    dp[0] = 0;
    for(int i=1;i<22222;i++){
        REP(j,N){
            if(i - A[j] >= 0) chmin(dp[i], dp[i-A[j]] + B[j]);
        }
    }
    ll ans = LINF;
    for(int i=H;i<22222;i++) chmin(ans, dp[i]);
    cout << ans << endl;
}