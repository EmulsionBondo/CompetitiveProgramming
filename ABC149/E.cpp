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

//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<ll> cum(N+1);
    REP(i,N) cin >> A[i];
    sort(A.begin(), A.end());
    REP(i,N) cum[i+1] = cum[i] + A[i];

    auto check = [&](ll m){
        ll cnt = 0;
        REP(i,N) cnt += A.end() - lower_bound(A.begin(), A.end(), m - A[i]);
        return cnt >= M;
    };

    ll l = 0, r = LINF;
    while(r - l > 1){
        ll m = (l + r) >> 1;
        if(check(m)) l = m;
        else r = m;
    }

    ll ans = 0, cnt = 0;
    REP(i,N){
        int cur = lower_bound(A.begin(), A.end(), r - A[i]) - A.begin();
        ans += cum[N] - cum[cur] + A[i] * (N - cur);
        cnt += N - cur;
    }
    if(cnt < M) ans += (M - cnt) * l;
    cout << ans << endl;
}
