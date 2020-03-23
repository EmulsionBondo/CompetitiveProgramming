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
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    REP(i,H) cin >> S[i];
    vector<vector<int>> cum(H+1, vector<int>(W+1));
    REP(i,H) REP(j,W){
        cum[i+1][j+1] = cum[i][j+1] + cum[i+1][j] - cum[i][j] + (S[i][j] == '1');
    }
    int ans = INF;
    REP(i, 1<<(H-1)){
        vector<int> h;
        REP(j,H-1) if((i >> j) & 1) h.push_back(j+1);
        h.push_back(H);
        int cnt = (int)h.size() - 1;
        int preW = 0;
        bool ok = true;
        for(int j=1;j<=W;j++){
            int preH = 0;
            int tmp = 0;
            for(auto x : h){
                chmax(tmp, cum[x][j] - cum[preH][j] - cum[x][preW] + cum[preH][preW]);
                preH = x;
            }
            if(tmp > K){
                if(j == 1){
                    ok = false;
                    break;
                }
                if(preW == W-1 && j == W){
                    ok = false;
                    break;
                }
                preW = j - 1;
                j--;
                cnt++;
            }
        }
        int tmp = 0;
        int preH = 0;
        for(auto x : h){
            chmax(tmp, cum[x][W] - cum[preH][W] - cum[x][preW] + cum[preH][preW]);
            preH = x;
        }
        if(tmp > K) ok = false;

        if(ok){
            chmin(ans, cnt);
        }
    }
    cout << ans << endl;
}