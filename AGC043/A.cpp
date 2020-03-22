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

int dp[111][111];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vector<string> fi(H);
    REP(i,H) cin >> fi[i];

    queue<tuple<int, int, char>> q;
    q.emplace(0, 0, fi[0][0]);
    memset(dp, 10101010, sizeof(dp));
    if(fi[0][0] == '.') dp[0][0] = 0;
    else dp[0][0] = 1;

    while(!q.empty()){
        int h, w;
        char cur;
        tie(h, w, cur) = q.front(); q.pop();
        if(h == H-1 && w == W-1) break;
        REP(i,2){
            int nh = h + dx[i], nw = w + dy[i];
            if(nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if(cur == fi[nh][nw]){
                if(chmin(dp[nh][nw], dp[h][w])){
                    q.emplace(nh, nw, cur);
                }
            }
            else{
                if(cur == '#'){
                    if(chmin(dp[nh][nw], dp[h][w])){
                        q.emplace(nh, nw, fi[nh][nw]);
                    }
                }
                else{
                    if(chmin(dp[nh][nw], dp[h][w] + 1)){
                        q.emplace(nh, nw, fi[nh][nw]);
                    }
                }
            }
        }
    }
    cout << dp[H-1][W-1] << endl;
}
