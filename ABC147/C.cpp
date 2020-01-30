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
    int N;
    cin >> N;
    vector<vector<pair<int,int>>> A(N);
    REP(i,N){
        int a;
        cin >> a;
        REP(j,a){
            int x, y;
            cin >> x >> y;
            --x;
            A[i].emplace_back(x,y);
        }
    }
    int ans = 0;
    for(int i=0;i<(1<<N);i++){
        int tmp = 0;
        bool ok = true;
        REP(j,N){
            if((i>>j) & 1){
                tmp++;
                REP(k,A[j].size()){
                    int x = A[j][k].first;
                    int y = A[j][k].second;
                    if((i>>x) & 1){
                        if(y == 0){
                            ok = false;
                            break;
                        }
                    }
                    else{
                        if(y == 1){
                            ok = false;
                            break;
                        }
                    }
                }
            }
        }
        //cout << i << " " << tmp << " " << ok << endl;
        if(ok) chmax(ans, tmp);
    }
    cout << ans << endl;
}