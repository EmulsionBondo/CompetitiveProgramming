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



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> P(N), Q(N), idx(N);
    REP(i,N) cin >> P[i];
    REP(i,N) cin >> Q[i];
    iota(idx.begin(), idx.end(), 1);
    int a = -1, b = -1;
    int cnt = 1;
    do{
        bool okp = true;
        bool okq = true;
        REP(i,N){
            if(P[i] != idx[i]){
                okp = false;
                break;
            }
        }
        REP(i,N){
            if(Q[i] != idx[i]){
                okq = false;
                break;
            }
        }
        if(okp){
            a = cnt;
        }
        if(okq){
            b = cnt;
        }
        cnt++;
    }while(next_permutation(idx.begin(), idx.end()));
    cout << abs(a-b) << endl;
}