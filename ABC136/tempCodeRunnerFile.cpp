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
    string S;
    cin>>S;
    vector<int> sum((int)S.size());
    int N = S.size();
    int R=1,L=0;
    int i = 0;
    int j=0;
    while(i<N){
        while(S[i+1]=='R' && i<N-1) R++,i++;
        j = i;
        while(S[i+1]=='L' && i<N-1) L++,i++;
        //cout<<j<<":"<<i<<endl;
        //cout<<R<<":"<<L<<endl;
        sum[j] += (R+1)/2;
        sum[j+1] += R/2;
        sum[j+1] += (L+1)/2;
        sum[j] += L/2;
        if(i==N-1){
            break;
        }
        R = 0;
        L = 0;
    }
    REP(i,N) cout<<sum[i]<<" "<<endl;
}
