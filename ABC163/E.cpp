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

ll dp[2020][2020];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<ll, ll>> A(N);
    REP(i,N){
        cin >> A[i].first;
        A[i].second = i + 1;
    }
    sort(A.rbegin(), A.rend());
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    REP(i,N){
        for(int l=0;l<=i;l++){
            int r = (i - l);
            if(l + 1 <= N && ~dp[l][r]) chmax(dp[l+1][r], dp[l][r] + A[i].first * abs(A[i].second - l - 1));
            if(r + 1 <= N && ~dp[l][r]) chmax(dp[l][r+1], dp[l][r] + A[i].first * abs(A[i].second - (N - r)));
        }
    }
    ll ans = 0;
    REP(i,N+1) chmax(ans, dp[i][N-i]);
    cout << ans << endl;
}
