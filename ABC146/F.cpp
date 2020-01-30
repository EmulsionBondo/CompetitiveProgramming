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
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    queue<int> q;
    vector<int> ans;
    vector<int> dist(N+1, -1);
    dist[N] = 0;
    q.push(N);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == 0) break;
        for(int i=M;i>=1;i--){
            if(cur - i < 0){
                ans.push_back(cur);
                dist[0] = dist[cur] + 1;
                break;
            }
            if(S[cur-i] == '1' || dist[cur-i] != -1) continue;
            ans.push_back(i);
            q.push(cur-i);
            dist[cur-i] = dist[cur] + 1;
            break;
        }
    }
    if(dist[0] == -1){
        cout << -1 << endl;
        return 0;
    }
    reverse(ans.begin(), ans.end());
    REP(i,ans.size()) cout << ans[i] << " ";
    cout << endl;
}