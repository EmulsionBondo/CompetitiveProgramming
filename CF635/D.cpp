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
    int nr, ng, nb;
    cin >> nr >> ng >> nb;
    vector<ll> R(nr), G(ng), B(nb);
    REP(i,nr) cin >> R[i];
    REP(i,ng) cin >> G[i];
    REP(i,nb) cin >> B[i];
    sort(R.begin(), R.end());
    sort(G.begin(), G.end());
    sort(B.begin(), B.end());
    ll ans = 3 * LINF;
    auto f = [&](ll a, vector<ll> &b, vector<ll> & c) -> void{
        auto itr1 = upper_bound(b.begin(), b.end(), a);
        auto itr2 = lower_bound(c.begin(), c.end(), a);
        if(itr1 == b.begin() || itr2 == c.end()) return;
        itr1--;
        ll tmp = (a - *itr1) * (a - *itr1) + (a - *itr2) * (a - *itr2) + (*itr1 - *itr2) * (*itr1 - *itr2);
        chmin(ans, tmp);
    };
    
    REP(i,nr){
        f(R[i], G, B);
        f(R[i], B, G);
    }
    REP(i,ng){
        f(G[i], R, B);
        f(G[i], B, R);
    }
    REP(i,nb){
        f(B[i], R, G);
        f(B[i], G, R);
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    REP(i,Q) solve();
}