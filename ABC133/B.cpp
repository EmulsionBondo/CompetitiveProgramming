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

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const double PI = acos(-1.0);
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,d;
    cin>>n>>d;
    vector<vector<int>> x(n,vector<int>(d,0));
    REP(i,n) REP(j,d){
        cin>>x[i][j];
    }
    int cnt=0;
    REP(i,n){
        for(int j=i+1;j<n;j++){
            int ans = 0;
            REP(k,d){
                ans += abs(x[i][k]-x[j][k]) * abs(x[i][k]-x[j][k]);
            }
            if((int)sqrt(ans)==sqrt(ans)) cnt++;
        }
    }
    cout<<cnt<<endl;
}
