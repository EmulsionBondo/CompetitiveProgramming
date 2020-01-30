#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define LINF 1e18
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
    vector<int> A(N+1),B(N);
    REP(i,N+1) cin>>A[i];
    REP(i,N) cin>>B[i];
    ll ans = 0;
    REP(i,N){
        if(A[i]<=B[i]){
            ans+=A[i];
            B[i] -= A[i];
        }
        else{
            ans += B[i];
            B[i] = 0;
        }
        if(A[i+1]<=B[i]){
            ans += A[i+1];
            B[i] -= A[i+1];
            A[i+1] = 0;
        }
        else{
            ans += B[i];
            A[i+1] -= B[i];
            B[i] = 0;
        }
    }
    cout<<ans<<endl;
}