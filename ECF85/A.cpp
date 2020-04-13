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
    int Q;
    cin >> Q;
    while(Q--){
        int n;
        cin >> n;
        vector<int> p(n), c(n);
        REP(i,n) cin >> p[i] >> c[i];
        int clear = 0;
        int play = 0;
        bool ok = true;
        REP(i,n){
            if(clear > c[i]) ok = false;
            if(p[i] < c[i]) ok = false;
            if(play > p[i]) ok = false;
            if(p[i] - play < c[i] - clear) ok = false;
            clear = c[i];
            play = p[i];
        }
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}