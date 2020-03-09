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

int color[202020];
vector<vector<int>> G;
int even = 0, odd = 0;
void dfs(int v, int par, int d){
    if(color[v] == -1){
        color[v] = d;
        if(d & 1) odd++;
        else even++;
    }
    for(auto nv : G[v]){
        if(nv == par) continue;
        dfs(nv, v, d^1);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    G.resize(N);
    REP(i,N-1){
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    memset(color, -1, sizeof(color));

    color[0] = 0;
    dfs(0, -1, 0);
    vector<int> num[3];
    for(int i=1;i<=N;i++){
        num[i%3].push_back(i);
    }
    vector<int> ans(N);
    if(N/3 < odd && N/3 < even){
        REP(i,N){
            if(!num[color[i]+1].empty()){
                ans[i] = num[color[i]+1].back();
                num[color[i]+1].pop_back();
            }
            else{
                ans[i] = num[0].back();
                num[0].pop_back();
            }
        }
    }
    else if(N / 3 >= odd){
        REP(i,N){
            if(color[i]){
                ans[i] = num[0].back();
                num[0].pop_back();
                color[i] = -1;
            }
        }
        REP(i,N){
            if(color[i] != -1){
                if(!num[2].empty()){
                    ans[i] = num[2].back();
                    num[2].pop_back();
                }
                else if(!num[1].empty()){
                    ans[i] = num[1].back();
                    num[1].pop_back();
                }
                else{
                    ans[i] = num[0].back();
                    num[0].pop_back();
                }
            }
        }
    }
    else{
        REP(i,N){
            if(!color[i]){
                ans[i] = num[0].back();
                num[0].pop_back();
                color[i] = -1;
            }
        }
        REP(i,N)
            if(color[i] != -1){
                if(!num[2].empty()){
                    ans[i] = num[2].back();
                    num[2].pop_back();
                }
                else if(!num[1].empty()){
                    ans[i] = num[1].back();
                    num[1].pop_back();
                }
                else{
                    ans[i] = num[0].back();
                    num[0].pop_back();
                }
            }
        }
    }
    REP(i,N) cout << ans[i] << " ";
    cout << endl;
}
