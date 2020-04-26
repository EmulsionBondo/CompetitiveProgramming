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
    vector<string> fi(9);
    REP(i,9) cin >> fi[i];

    if(fi[0][0] == '9') fi[0][0] = '1';
    else fi[0][0]++;
    if(fi[1][4] == '9') fi[1][4] = '1';
    else fi[1][4]++;
    if(fi[2][8] == '9') fi[2][8] = '1';
    else fi[2][8]++;
    if(fi[3][1] == '9') fi[3][1] = '1';
    else fi[3][1]++;
    if(fi[4][5]== '9') fi[4][5] = '1';
    else fi[4][5]++;
    if(fi[5][6] == '9') fi[5][6] = '1';
    else fi[5][6]++;
    if(fi[6][2] == '9') fi[6][2] = '1';
    else fi[6][2]++;
    if(fi[7][3] == '9') fi[7][3] = '1';
    else fi[7][3]++;
    if(fi[8][7] == '9') fi[8][7] = '1';
    else fi[8][7]++;

    REP(i,9){
        REP(j,9) cout << fi[i][j];
        cout << '\n';
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    REP(i,Q) solve();
} 