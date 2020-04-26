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

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i,n) cin >> a[i];
    int minL = 0, right = 0;
    int cnt = 0;
    int ans = 0;
    for(int i=1;i<k-1;i++){
        if(a[i-1] < a[i] && a[i] > a[i+1]) cnt++;
    }
    chmax(ans, cnt);
    for(int i=k-1;i<n-1;i++){
        if(a[i-k+1] < a[i-k+2] && a[i-k+2] > a[i-k+3]) cnt--;
        if(a[i-1] < a[i] && a[i] > a[i+1]) cnt++;
        if(chmax(ans, cnt)) minL = i-k+2;
        // cerr << i << " " << cnt << endl;
    }
    cout << ans + 1 << " " << minL + 1 << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    // solve();
    int Q; cin >> Q; REP(i,Q) solve();
}