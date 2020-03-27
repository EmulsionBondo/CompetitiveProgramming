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
template<class T> inline void add(T &a, T b){a = ((a+b) % MOD + MOD) % MOD;};

vector<pair<int, int>> runLengthEncoding(vector<int> s) {
    int n = s.size();

    vector<pair<int, int>> res;
    int pre = s[0];
    int cnt = 1;
    for(int i=1;i<n;i++) {
        if (pre != s[i]) {
            res.push_back({ pre, cnt });
            pre = s[i];
            cnt = 1;
        }
        else cnt++;
    }

    res.push_back({ pre, cnt });
    return res;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q--){
        int n;
        cin >> n;
        vector<int> t(n);
        REP(i,n) cin >> t[i];
        bool monotone = true;
        REP(i,n-1) if(t[i] != t[i+1]) monotone = false;
        if(monotone){
            cout << 1 << endl;
            REP(i,n) cout << 1 << " ";
            cout << endl;
        }
        else{
            if(n % 2 == 0){
                cout << 2 << endl;
                REP(i,n) cout << (i % 2) + 1 << " ";
                cout << endl;
            }
            else{
                int same = -1;
                REP(i,n) if(t[i] == t[(i+1)%n]) same = i+1;
                if(~same){
                    cout << 2 << endl;
                    REP(i,same) cout << (i % 2) + 1 << " ";
                    for(int i=same;i<n;i++) cout << ((i + 1) % 2) + 1 << " " ;
                    cout << endl;
                }
                else{
                    cout << 3 << endl;
                    REP(i,n-1) cout << (i % 2) + 1 << " ";
                    cout << 3 << endl;
                }
            }
        }
    }
}
