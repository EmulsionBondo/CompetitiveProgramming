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
//typedef vector<unsigned int>vec;
typedef vector<ll>vec;
typedef vector<vec> mat;
typedef vector<vector<int>> Graph;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const ll  MOD = 1000000007;
//const ll MOD = 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-10;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int X;
    cin >> X;
    if(X < 100){
        cout << 0 << endl;
        return 0;
    }
    int cnt = X / 100;
    int res = X % 100;
    cnt -= res / 5;
    res %= 5;
    if(res == 0 && cnt >= 0){
        cout << 1 << endl;
        return 0;
    }
    if(cnt < 0){
        cout << 0 << endl;
        return 0;
    }
    //cout << res << endl;
    cnt -= res / 4;
    res %= 4;
    if(res == 0 && cnt >= 0){
        cout << 1 << endl;
        return 0;
    }
    if(cnt < 0){
        cout << 0 << endl;
        return 0;
    }
    cnt -= res / 3;
    res %= 3;
    if(res == 0 && cnt >= 0){
        cout << 1 << endl;
        return 0;
    }
    if(cnt < 0){
        cout << 0 << endl;
        return 0;
    }
    cnt -= res / 2;
    res %= 2;
    if(res == 0 && cnt >= 0){
        cout << 1 << endl;
        return 0;
    }
    if(cnt < 0){
        cout << 0 << endl;
        return 0;
    }
    cnt -= res;
    res = 0;
    if(res == 0 && cnt >= 0){
        cout << 1 << endl;
        return 0;
    }
    if(cnt < 0){
        cout << 0 << endl;
        return 0;
    }

}
