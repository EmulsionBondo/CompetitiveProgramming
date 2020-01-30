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
const double PI = acos(-1.0);
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<ll> X(N+1),A(N+1);
    ll sum = 0;
    REP(i,N){
        cin>>A[i+1];
        sum += A[i+1];
    }
    X[1] = sum;
    for(int i=2;i<N;i+=2){
        X[1] -= 2*A[i];
    }
    for(int i=2;i<=N;i++){
        X[i] = 2*A[i-1] - X[i-1];
    }
    REP(i,N) cout<<X[i+1]<<" ";
    cout<<endl;
}
