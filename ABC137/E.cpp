#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 3e18+7
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
const double PI = acos(-1.0);
const double EPS = 1e-10;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M,P;
    cin>>N>>M>>P;
    const int NMAX=2525;
    const int MMAX=5050;
    vector<int> a(MMAX),b(MMAX);
    vector<ll> c(MMAX);
 
    REP(i,M){
        cin>>a[i]>>b[i]>>c[i];
        c[i] = -c[i];
    }
 
    vector<ll> dist(NMAX);
 
    REP(i,N) dist[i]=INF;
 
    dist[0]=0;
 
    for(int loop=0;loop<N;++loop){
        for(int i=0;i<M;++i){
            if(dist[a[i]-1]==INF) continue;
 
            if(dist[b[i]-1] > dist[a[i]-1]+c[i]+P) dist[b[i]-1] = dist[a[i]-1] + c[i] +P;
        }
    }
 
    ll ans = dist[N-1];
 
    vector<bool> negative(NMAX,0);
 
    for(int loop=0;loop<N;++loop){
        for(int i=0;i<M;++i){
            if(dist[a[i]-1]==INF) continue;
 
            if(dist[b[i]-1] > dist[a[i]-1]+c[i] + P){
                dist[b[i]-1] = dist[a[i]-1] + c[i] + P;
                negative[b[i]-1] = true;
            }
 
            if(negative[a[i]-1]==true) negative[b[i]-1]=true;
        }
    }
    //cout<<ans<<endl;
    if(negative[N-1]) cout<<-1<<endl;
    else if(ans>0) cout<<0<<endl;
    else cout<<-ans<<endl;
    return 0;
}