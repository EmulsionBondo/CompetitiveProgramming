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
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B);
    vector<int> x(M), y(M), c(M);
    int mi_a = INF, mi_b = INF;
    REP(i,A){
        cin >> a[i];
        chmin(mi_a, a[i]);
    }
    REP(i,B){
        cin >> b[i];
        chmin(mi_b, b[i]);
    }
    REP(i,M){
        cin >> x[i] >> y[i] >> c[i];
        --x[i], --y[i];
    }
    int ans = mi_a + mi_b;
    REP(i,M){
        int tmp = a[x[i]] + b[y[i]] - c[i];
        chmin(ans, tmp);
    }
    cout << ans << endl;
}