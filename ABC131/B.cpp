#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct Edge{int to,weight; Edge(int t, int w) : to(t), weight(w) {}};
using DirectedGraph = vector<vector<Edge>>;
using UndirectedGraph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,l;
    cin>>n>>l;
    vector<int> num(n);
    int sum=l;
    num[0] = l;
    int mi = l;
    for(int i=1;i<n;i++){
        num[i] = l + i;
        sum+=num[i];
        //cout<<num[i]<<endl;
        if(abs(mi) > abs(num[i])){
            mi=num[i];
        }
    }
    cout<<sum-mi<<endl;
}