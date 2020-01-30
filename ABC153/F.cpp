#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;

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
    ll N, D, A;
    cin >> N >> D >> A;
    vector<tuple<ll, ll, int, int>> X;
    vector<ll> cnt(N);
    REP(i,N){
        ll x, H;
        cin >> x >> H;
        X.emplace_back(2*x, H, -1, i);
        X.emplace_back(2*x+4*D+1, H, 1, i);
    }
    sort(X.begin(), X.end());
    ll ans = 0;
    ll now = 0;
    for(auto t : X){
        ll x, h;
        int flg, idx;
        tie(x, h, flg, idx) = t;
        if(flg == 1)　now -= cnt[idx];
        else{
            ll need = (h - now*A + A - 1) / A;
            if(need > 0){
                ans += need;
                cnt[idx] = need;
                now += need;
            }
        }
    }
    cout << ans << endl;
}
