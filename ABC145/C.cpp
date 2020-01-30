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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<double> x(N), y(N);
    REP(i,N) cin >> x[i] >> y[i];

    vector<int> a(N);
    iota(a.begin(), a.end(), 0);
    double sum = 0.0;
    do{
        for(int i=1;i<N;i++){
            sum += sqrt((x[a[i]] - x[a[i-1]])*(x[a[i]] - x[a[i-1]]) + (y[a[i]] - y[a[i-1]]) * (y[a[i]] - y[a[i-1]]));
        }
    }while(next_permutation(a.begin(), a.end()));
    for(int i=1;i<=N;i++) sum /= (double)i;
    printf("%.12lf\n",sum);
}