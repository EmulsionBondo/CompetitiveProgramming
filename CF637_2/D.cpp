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

string num[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };

int needCount(string &s, string &t){
    int cnt = 0;
    REP(l,7){
        if(s[l] == '1' && t[l] == '0'){
            cnt = -1;
            break;
        }
        if(s[l] == '0' && t[l] == '1') cnt++;
    }
    return cnt;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    REP(i,n) cin >> s[i];
    // reverse(s.begin(), s.end());
    vector<vector<bool>> dp(n+10, vector<bool>(k+10, false));
    vector<vector<bool>> pre(n+10, vector<bool>(k+10, false));
    dp[0][0] = true;
    REP(i,n){
        REP(j,k+1){
            if(!dp[i][j]) continue;
            REP(l,10){
                int cnt = needCount(s[i], num[l]);
                if(cnt == -1) continue;
                if(j + cnt > k) continue;
                dp[i+1][j+cnt] = true;
            }
        }
    }
    if(!dp[n][k]){
        cout << -1 << endl;
        return;
    }

    pre[n][k] = true;
    for(int i=n;i>0;i--){
        REP(j,k+1){
            if(!dp[i-1][j]) continue;
            REP(l,10){
                int cnt = needCount(s[i-1], num[l]);
                if(cnt == -1) continue;
                if(j + cnt > k) continue;
                if(!pre[i][j+cnt]) continue;
                pre[i-1][j] = true;
            }
        }
    }

    string ans = "";
    int cur = 0;
    REP(i,n){
        int ma = -1;
        int next = -1;
        REP(j,10){
            int cnt = needCount(s[i], num[j]);
            if(cnt == -1) continue;
            if(cur + cnt > k) continue;
            if(!pre[i+1][cur + cnt]) continue;
            if(chmax(ma, j)) next = cur + cnt;
        }
        ans += char(ma + '0');
        cur = next;
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    // int Q; cin >> Q; REP(i,Q) solve();
}