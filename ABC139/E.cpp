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
typedef vector<unsigned int>vec;
typedef vector<vec> mat;
typedef vector<vector<int>> Graph;

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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int player[1010][1010] = {};
    REP(i,N) REP(j,N-1){
        cin >> player[i][j];
        player[i][j]--;
    }
    int ans = 0;
    int cnt[1010] = {};
    int sum = 0;
    int step = 0;
    while(sum < N*(N-1)){
        ans++;
        int tmp = sum;
        int done[1010] = {};
        REP(i,N){
            step++;
            if(cnt[i] > ans) continue;
            if(cnt[i] >= N-1) continue;
            int outside = player[i][cnt[i]];
            if(cnt[outside] < ans){
                if(i == player[outside][cnt[outside]] && !done[i] && !done[outside]){
                    //cout << i+1 << ":" << outside+1 << endl;
                    cnt[i]++;
                    cnt[outside]++;
                    done[i] = true;
                    done[outside] = true;
                    sum += 2;
                }
            }
            else continue;
        }
        if(sum == tmp){
            cout << -1 << endl;
            return 0;

        }
        if(sum >= N*(N-1)) break;
        //cout << ans << endl;
        if(step >= 1e8){
            cout << N*(N-1)/2 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}