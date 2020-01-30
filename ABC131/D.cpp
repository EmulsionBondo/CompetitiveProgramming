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
    int n;
    cin>>n;
    vector<P> itv(n);
    REP(i,n){
        cin>>itv[i].second>>itv[i].first;
    }
    VSORT(itv);
    int t = 0;
    REP(i,n){
        //cout<<itv[i].second<<":"<<itv[i].first<<endl;
        if(t+itv[i].second<=itv[i].first){
            t += itv[i].second;
        }
        else{
            cout<<"No"<<endl;
            return 0;
        }
        //cout<<t<<endl;
        //cout<<t<<endl;
    }
    cout<<"Yes"<<endl;
}