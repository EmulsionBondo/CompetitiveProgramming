#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define ll long long
using namespace std;
//typedef vector<unsigned int>vec;
//typedef vector<ll>vec;
//typedef vector<vec> mat;
typedef pair<int, int> P;
typedef pair<ll,ll> LP;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
//template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    REP(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    deque<int> dq;
    REP(i,n) dq.push_back(a[i]);
    int parity = 0;
    vector<int> ans;
    while(!dq.empty()){
        if(parity & 1){
            ans.push_back(dq.back());
            dq.pop_back();
        }
        else{
            ans.push_back(dq.front());
            dq.pop_front();
        }
        parity = 1 - parity;
    }
    reverse(ans.begin(), ans.end());
    REP(i,n) cout << ans[i] << " ";
    cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    REP(i,Q) solve();
}