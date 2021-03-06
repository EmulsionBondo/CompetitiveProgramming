#include <bits/stdc++.h>
#include <sys/time.h>
#pragma GCC optimize "O3,omit-frame-pointer,inline"
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


constexpr ll CYCLES_PER_SEC = 2800000000;
constexpr double TL = 4995;
double get_ms() { struct timeval t; gettimeofday(&t, NULL); return (double)t.tv_sec * 1000 + (double)t.tv_usec / 1000; }

uint32_t XorShift(void) {
	static uint32_t x = 123456789;
	static uint32_t y = 362436069;
	static uint32_t z = 521288629;
	static uint32_t w = 88675123;
	uint32_t t;

	t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

namespace AHC001{
    int n;
    vector<int> x, y, r;
    void input(){
        cin >> n;
        x.resize(n);
        y.resize(n);
        r.resize(n);
        REP(i,n) cin >> x[i] >> y[i] >> r[i];
    }


    void output(){
        REP(i,n) cout << x[i] << " " << y[i] << " " << x[i]+1 << " " << y[i] + 1 << endl;
    }

    void main(){
        input();
        output();
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    AHC001::main();
}