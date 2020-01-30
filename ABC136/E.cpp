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
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    ll sum = 0;
    REP(i,n){
        cin >> a[i];
        sum += a[i];
    }
    set<ll> candidates;
    for(int i=1;i*i<=sum;i++){
        if(sum%i == 0){
            candidates.insert(i);
            candidates.insert(sum/i);
        }
    }
    ll ans = 1;
    for(ll x : candidates){
        ll cnt = LINF;;
        vector<ll> r(n);
        REP(i,n) r[i] = a[i] % x;
        sort(r.begin(),r.end());
        ll B = 0;
        REP(i,n) B += x-r[i];
        ll A = 0;
        REP(i,n){
            A += r[i];
            B -= x-r[i];
            cnt = min(cnt,max(A,B));
        }
        if(cnt <= k) ans = max(ans,x);
    }
    cout<<ans<<endl;
}
