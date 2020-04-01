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

int a[3][4];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    a[1][1] = (1LL << 17) + k;
    a[1][2] = (1LL << 17);
    a[2][1] = k;
    a[2][2] = (1LL << 17) + k;
    a[2][3] = k;
    cout << 2 << " " << 3 << endl;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=3;j++) cout << a[i][j] << " ";
        cout << endl;
    }
}