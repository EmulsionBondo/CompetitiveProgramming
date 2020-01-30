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

int b[202020];

void divisor(int n){
    vector<int> res;
    for(int i=1; i*i <= n; i++){
        if(n % i == 0){
            b[i]++;
            if(i != n / i) b[n/i]++;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> a(N+1);
    REP(i,N) cin>>a[i+1];
    int ans = 0;
    vector<int> ans_v;
    for(int i=N;i>0;--i){
        b[i] %= 2;
        if(a[i]==b[i]) continue;
        else{
            divisor(i);
            ans_v.push_back(i);
            ans++;
        }
    }
    reverse(ans_v.begin(),ans_v.end());
    if(a[1]!=b[1]) cout<<-1<<endl;
    else{
        cout<<ans<<endl;
        if(ans_v.size()==0) return 0;
        for(auto x:ans_v) cout<<x<<" ";
        cout<<endl;
    }
}
