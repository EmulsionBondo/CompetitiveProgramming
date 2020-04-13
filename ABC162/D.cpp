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
    int N;
    string S;
    cin >> N >> S;
    vector<ll> cumR(N+1), cumG(N+1), cumB(N+1);
    REP(i,N){
        cumR[i+1] = cumR[i] + (S[i] == 'R');
        cumG[i+1] = cumG[i] + (S[i] == 'G');
        cumB[i+1] = cumB[i] + (S[i] == 'B');
    }
    ll ans = 0;
    REP(i,N){
        for(int j=i+1;j<N-1;j++){
            if(S[i] == S[j]) continue;
            if(S[i] != 'R' && S[j] != 'R'){
                ans += cumR[N] - cumR[j];
                if(j + j - i > N) continue;
                if(S[2*j - i] == 'R') ans--;
            }
            if(S[i] != 'G' && S[j] != 'G'){
                ans += cumG[N] - cumG[j];
                if(j + j - i > N) continue;
                if(S[2*j - i] == 'G') ans--;
            }
            if(S[i] != 'B' && S[j] != 'B'){
                ans += cumB[N] - cumB[j];
                if(j + j - i > N) continue;
                if(S[2*j - i] == 'B') ans--;
            }
        }
    }
    cout << ans << endl;
}