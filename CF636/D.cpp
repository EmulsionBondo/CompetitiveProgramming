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
    scanf("%d %d", &n, &k);
    vector<int> a(n), imos(2*k+10);
    REP(i,n) scanf("%d", &a[i]);

    REP(i,n/2){
        int x = a[i], y = a[n-i-1];
        if(x > y) swap(x, y);
        int sum = x + y;
        int lt = sum - (y - 1);
        int ut = sum + (k - x);
        imos[lt]++, imos[sum]--;
        imos[sum+1]++, imos[ut+1]--;
        if(lt != 2) imos[2] += 2, imos[lt] -= 2;
        if(ut != 2 * k) imos[ut+1] += 2, imos[2*k+1] -= 2;
    }
    REP(i,2*k) imos[i+1] += imos[i];
    int ans = INF;
    for(int i=2;i<=2*k;i++) chmin(ans, imos[i]);
    cout << ans << '\n';
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    scanf("%d", &Q);
    REP(i,Q) solve();
}