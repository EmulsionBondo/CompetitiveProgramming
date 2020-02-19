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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i,N) cin >> A[i];
    sort(A.begin(), A.end());
    auto f = [&](ll tar, ll a) -> ll{
        ll l = -1, r = N;
        while(r - l > 1){
            ll m = (r + l) >> 1;
            if(a * A[m] <= tar){
                if(a < 0) r = m;
                else l = m;
            }
            else{
                if(a < 0) l = m;
                else r = m;
            }
        }
        if(a < 0) return N - r;
        else return r;
    };

    ll l = -LINF, r = LINF;
    while(r - l > 1){
        ll m = (l + r) >> 1;
        ll cnt = 0;
        REP(i,N){
            cnt += f(m, A[i]);
            if(A[i] * A[i] <= m) cnt--;
        }
        cnt /= 2;
        if(cnt >= K) r = m;
        else l = m;
    }
    cout << r << endl;
}
