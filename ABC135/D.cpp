#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 1e18
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

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-10;

string S;
ll dp[101010][13];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>S;
    int n = S.size();
    dp[0][0] = 1;
    REP(i,n){
        int c;
        if(S[i] == '?') c = -1;
        else c = S[i] - '0';
        for(int j=0;j<10;j++){
            if(c != -1 && c != j) continue;
            for(int ki=0;ki<13;ki++){
                dp[i+1][(ki*10+j)%13] += dp[i][ki];
            }
        }
        for(int j=0;j<13;j++) dp[i+1][j] %= MOD;
    }
    cout<<dp[n][5]<<endl;
}