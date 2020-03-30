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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int K, N;
    cin >> K >> N;
    vector<ll> A(2*N);
    REP(i,N) cin >> A[i];
    for(int i=N;i<2*N;i++) A[i] = A[i-N] + K;

    ll ans = LINF;
    for(int i=0;i<N;i++){
        chmin(ans, A[i+N-1] - A[i]);
    }
    for(int i=2*N-1;i>=N;i--){
        chmin(ans, A[i] - A[i-N+1]);
    }
    cout << ans << endl;
}