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
//typedef vector<ll>vec;
//typedef vector<vec> mat;
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


ll gcd(ll x, ll y){
  return y ? gcd(y, x%y) : x;
}

ll lcm( ll m, ll n ){
	if ( ( 0 == m ) || ( 0 == n ) ) return 0;
    return ((m / gcd(m, n)) * n);// lcm = m * n / gcd(m,n)
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N);
    set<int> pf;
    ll L = 1;
    REP(i,N){
        cin >> a[i];
        a[i] /= 2;
        L = lcm(L, a[i]);
        int cnt = 0;
        while(a[i] % 2 == 0){
            cnt++;
            a[i] /= 2;
        }
        pf.insert(cnt);
        if(L > M){
            cout << 0 << endl;
            return 0;
        }
    }
    if(pf.size() > 1){
        cout << 0 << endl;
        return 0;
    }
    cout << (M / L + 1) / 2 << endl;
}