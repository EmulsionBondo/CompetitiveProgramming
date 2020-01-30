#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int n,m;
ll dp[2020][2020];
ll sum[2020][2020];
int S[2020],T[2020];


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    REP(i,n) cin>>S[i];
    REP(i,m) cin>>T[i];
    REP(i,2020) sum[i][0]=sum[0][i]=1;
    ll ret = 1;
    REP(x,n) REP(y,m){
        if(S[x]==T[y]){
            dp[x+1][y+1]=(sum[x][y])%MOD;
            ret += dp[x+1][y+1];
        }
        sum[x+1][y+1] = (sum[x][y+1]+sum[x+1][y]+MOD-sum[x][y]+dp[x+1][y+1])%MOD;
    }
    cout<<ret%MOD<<endl;
}