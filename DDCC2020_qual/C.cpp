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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> fi(H);
    REP(i,H) cin >> fi[i];
    vector<vector<int>> ans(H,vector<int>(W));
    vector<int> gyou(H);
    REP(i,H) REP(j,W){
        if(fi[i][j] == '#') gyou[i]++;
    }
    int cnt = 1;
    REP(i,H){
        if(gyou[i] == 0) continue;
        int tmp = 1;
        REP(j,W){
            if(fi[i][j] == '#'){
                if(tmp == 1) tmp++;
                else{
                    cnt++;
                }
            }
            ans[i][j] = cnt;
        }
        cnt++;
    }

    REP(i,H){
        if(gyou[i] > 0) continue;
        if(i == 0) REP(j,W) ans[i][j] = ans[i+1][j];
        else REP(j,W) ans[i][j] = ans[i-1][j];
    }
    for(int i=H-1;i>=0;i--){
        if(gyou[i] > 0) continue;
        if(i == H-1) REP(j,W) ans[i][j] = ans[i-1][j];
        else REP(j,W) ans[i][j] = ans[i+1][j];
    }
    REP(i,H){
        REP(j,W) cout << ans[i][j] << " ";
        cout << endl;
    }
}
