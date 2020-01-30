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
    int N;cin>>N;
    vector<int> A(N);
    REP(i,N) cin>>A[i];
    vector<int> left(N),right(N);
    left[0] = A[0];
    right[N-1] = A[N-1];
    for(int i=1;i<N;i++) left[i] = max(A[i],left[i-1]);
    for(int i=N-2;i>=0;i--) right[i] = max(A[i],right[i+1]);
    REP(i,N){
        if(i==0) cout<<right[1]<<endl;
        else if(i==N-1) cout<<left[N-2]<<endl;
        else{
            cout<<max(left[i-1],right[i+1])<<endl;
        }
    }
}
