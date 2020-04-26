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
    cin >> n; // n is even
    if((n / 2) % 2 == 1){
        cout << "NO" << endl;
        return;
    }
    vector<int> even, odd;
    ll sum = 0;
    for(int i=2;i<=n;i+=2){
        even.push_back(i);
        sum += i;
    }
    for(int i=1;i<n-2;i+=2){
        odd.push_back(i);
        sum -= i;
    }
    odd.push_back(sum);
    cout << "YES" << endl;
    for(auto x : even) cout << x << " ";
    for(auto x : odd) cout << x << " ";
    cout << endl;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    REP(i,Q) solve();
}