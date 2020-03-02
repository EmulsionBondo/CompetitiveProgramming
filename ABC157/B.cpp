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
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

int A[3][3];
bool ok[3][3];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i,3) REP(j,3) cin >> A[i][j];
    int N;
    cin >> N;
    REP(i,N){
        int b;
        cin >> b;
        REP(j,3) REP(k,3) if(A[j][k] == b) ok[j][k] = true;
    }
    bool bingo = false;
    REP(i,3){
        int cnt = 0;
        REP(j,3) if(ok[i][j]) cnt++;
        if(cnt >= 3) bingo = true;
    }
    REP(j,3){
        int cnt = 0;
        REP(i,3) if(ok[i][j]) cnt++;
        if(cnt >= 3) bingo = true;
    }
    int cnt = 0;
    REP(i,3) if(ok[i][i]) cnt++;
    if(cnt >= 3) bingo = true;
    cnt = 0;
    if(ok[0][2] && ok[1][1] && ok[2][0]) bingo = true;

    if(bingo) cout << "Yes" << endl;
    else cout << "No" << endl;
}