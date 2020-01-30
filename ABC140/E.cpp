#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
typedef vector<unsigned int>vec;
typedef vector<vec> mat;
typedef vector<vector<int>> Graph;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> P(N), idx(N);
    REP(i,N){
        cin >> P[i];
        --P[i];
    }
    REP(i,N) idx[P[i]] = i;
    set<ll> st;
    ll ans = 0;
    for(int x=N-1;x>=0;x--){
        int i = idx[x];
        vector<ll> l(2, -1);
        vector<ll> r(2,N);
        st.insert(i);
        auto itr = st.find(i);
        REP(j, 2){
            if(itr == st.begin()) break;
            --itr;
            l[j] = *itr;
        }
        itr = st.find(i);
        REP(j,2){
            ++itr;
            if(itr == st.end()) break;
            r[j] = *itr;
        }
        ll c = (i - l[0]) * (r[1] - r[0]) + (l[0] - l[1]) * (r[0] - i);
        ans += c * (x + 1);
    }
    cout << ans << endl;
}
