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
    int n;
    cin >> n;
    string S, LR = "L";
    cin >> S;
    ll L = 1, R = 0;
    for(int i=1;i<2*n;i++){
        if(S[i] == S[i-1]){
            if(LR[i-1] == 'R') LR.push_back('L'), L++;
            else LR.push_back('R'), R++;
        }
        else{
            if(LR[i-1] == 'R') LR.push_back('R'), R++;
            else LR.push_back('L'), L++;
        }
    }
    
    ll ans = 1;
    //cout << LR << endl;
    if(L != R || S[0] == 'W'){
        cout << 0 << endl;
        return 0;
    }
    else{
        L = 0;
        REP(i,2*n){
            if(LR[i] == 'L') L++;
            else{
                ans *= L;
                ans %= MOD;
                L--;
            }
        }
        REP(i,n){
            ans *= (i+1);
            ans %= MOD;
        }
    }
    cout << ans << endl;
}
