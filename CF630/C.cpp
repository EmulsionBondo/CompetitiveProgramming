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
    int Q;
    cin >> Q;
    while(Q--){
        int n, k;
        string S;
        cin >> n >> k >> S;
        int ans = 0;
        vector<bool> used(n, false);
        for(int i=0;i<k;i++){
            int ma = 0;
            int cnt = 0;
            vector<int> alp(26);
            for(int j=i;j<n;j+=k) if(!used[j]){
                alp[S[j]-'a']++;
                cnt++;
                used[j] = true;
            }
            for(int j=n-1-i;j>=0;j-=k) if(!used[j]){
                alp[S[j]-'a']++;
                cnt++;
                used[j] = true;
            }
            REP(i,26) chmax(ma, alp[i]);
            ans += cnt- ma;
        }
        cout << ans << endl;
    }
}