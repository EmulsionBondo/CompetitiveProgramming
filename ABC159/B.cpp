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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int N = S.size();
    string T = S.substr(0, (N-1)/2);
    string U = S.substr((N+3)/2-1);
    bool ok = true;
    for(int i=0;i<N/2;i++){
        if(S[i] != S[N-i-1]) ok = false;
    }
    for(int i=0;i<(N-1)/2;i++){
        if(T[i] != T[(N-1)/2 - i - 1]) ok = false;
        if(U[i] != U[(N-1)/2 - i - 1]) ok = false;
    }
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}