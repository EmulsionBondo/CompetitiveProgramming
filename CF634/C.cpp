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
    vector<int> cnt(n+1);
    REP(i,n){
        cin >> a[i];
        cnt[a[i]]++;
    }
    if(n == 1){
        cout << 0 << endl;
        return;
    }

    int distinct = 0, ma = 0;
    REP(i,n) if(cnt[i+1]){
        distinct++;
        chmax(ma, cnt[i+1]);
    }
    distinct--;
    if(distinct >= ma) cout << ma << endl;
    else{
        ma -= distinct;
        if(ma >= 2) cout << distinct + 1 << endl;
        else cout << distinct << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    REP(i,Q) solve();
}