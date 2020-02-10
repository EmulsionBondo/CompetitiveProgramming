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

ll dp[111][2][4];
string N;
int K;

ll rec(int k=0, bool tight=true, int non_zero = 0){
    if(non_zero > K) return 0;
    if(k == N.size()){
        return non_zero == K;
    }
    int x = N[k] - '0';
    int r = (tight ? x : 9);
    ll &res = dp[k][tight][non_zero];
    if(!tight && ~res) return res;
    res = 0;
    REP(i,r+1){
        res += rec(k+1, tight && i == r, (i != 0 ? non_zero + 1 : non_zero));
    }
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    memset(dp, -1, sizeof(dp));
    cout << rec() << endl;
}
