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

class StronglyConnectedComponents{
    int nodeNum;
    int size;
    vector<vector<int>> edge,revEdge;

    vector<int> label,visited,order;
    // 帰りがけ順に番号を振っていく
    void dfs(int cur){
        visited[cur] = 1;
        for(int next:edge[cur]) if(!visited[next]) dfs(next);
        order.push_back(cur);
    }
    // 通ることが出来た頂点に番号を振っていく
    void revDfs(int cur,int labelId){
        visited[cur] = 1;
        label[cur] = labelId;
        for(int next:revEdge[cur]) if(!visited[next]) revDfs(next,labelId);
    }

public:

	StronglyConnectedComponents(const int& nodeNum) : 
    nodeNum(nodeNum), edge(nodeNum), revEdge(nodeNum), label(nodeNum), visited(nodeNum) {}

    // vが属している強連結成分のグループ（トポロジカル順序）
	int operator[](int v) {
		return label[v];
	}

    void makeEdge(const int from,const int to) {
        edge[from].push_back(to);
        revEdge[to].push_back(from);
    }

    void solve(void) {
        for(int i = 0; i < nodeNum; ++i) visited[i] = 0;
        for(int i = 0; i < nodeNum; ++i) if(!visited[i]) dfs(i);
        for(int i = 0; i < nodeNum; ++i) visited[i] = 0;
        reverse(order.begin(),order.end());
        int labelId = 0;
        for(int i:order) if(!visited[i]) revDfs(i,labelId++);
        size = labelId;
    }

    void print(void) {
        for(auto labelId:label) cout << labelId << " ";
        cout << endl;
    }
    int getSize(){
        return size;
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << ~(-1) << endl;
}