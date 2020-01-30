#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct Edge{int to,weight; Edge(int t, int w) : to(t), weight(w) {}};
using DirectedGraph = vector<vector<Edge>>;
using UndirectedGraph = vector<vector<int>>;

ll gcd(ll x, ll y){
  return y ? gcd(y, x%y) : x;
}
ll lcm( int m, int n )
{
	// 引数に０がある場合は０を返す
	if ( ( 0 == m ) || ( 0 == n ) )
		return 0;

	return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}//lcm

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll cd = lcm(c,d);
    ll num_a=(a-1)/c+ (a-1)/d - (a-1)/cd;
    ll num_b = b/c + b/d - b/cd;
    cout<<b - a + 1 - (num_b - num_a)<<endl;
    //cout<<num_a<<":"<<num_b<<endl;
}