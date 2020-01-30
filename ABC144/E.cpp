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

ll N, K;
vector<ll> A;
vector<ll> F;

bool check(ll m){
    ll cnt = 0;

    REP(i,N){
        if(A[i] * F[i] <= m) continue;
        else{
            cnt += A[i] - (m / F[i]);
        }
    }
    return (cnt <= K);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    REP(i,N){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    REP(i,N){
        ll a;
        cin >> a;
        F.push_back(a);
    }
    sort(A.begin(), A.end());
    sort(F.rbegin(), F.rend());

    ll l = -1, r = 2*LINF;
    while(r - l > 1){
        ll m = (l + r) / 2;
        if(check(m))  r = m;
        else l = m;
    }
    cout << r << endl;
}