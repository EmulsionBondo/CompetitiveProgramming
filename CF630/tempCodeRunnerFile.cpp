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

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

vector<pair<long long, long long> > prime_factorize(long long n){
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));//p^num
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> num(1001);
        REP(i,n){
            cin >> a[i];
            auto res = prime_factorize(a[i]);
            for(auto x : res){
                num[x.first].push_back(i);
                // cout << x.first << " " << i << endl;
            }
        }

        int color = 1;
        priority_queue<pair<int,int>> pq;
        REP(i,1001) if((int)num[i].size() > 0) pq.emplace(num[i].size(), i);
        vector<int> ans(n);
        set<int> st;
        while(!pq.empty() && (int)st.size() != n){
            int cnt, key;
            tie(cnt, key) = pq.top(); pq.pop();
            cout << key << endl;
            bool flg = false;
            for(auto idx : num[key]){
                if(st.find(idx) == st.end()){
                    ans[idx] = color;
                    flg = true;
                }
            }
            if(flg) color++;
        }
        cout << color - 1 << endl;
        REP(i,n) cout << ans[i] << " ";
        cout << endl;
    }
}